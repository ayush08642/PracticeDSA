#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define print(...) __f(#__VA_ARGS__ , __VA_ARGS__)

template<typename arg>
void __f (const char*name, arg&& arg1)
{
    cout << name << ": " << arg1 << endl;
}

template<typename arg, typename... args>
void __f(const char* names, arg&& arg1, args&&... args_)
{
    const char* comma = strchr (names + 1, ',');
    cout.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args_...);
}


double powerOfN(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    return base * powerOfN(base, power - 1);
}
// Time  complexity: O(N) or O(power)
// Space complexity: O(N) or O(power)


double powerOfN_faster(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    double subproblem = powerOfN_faster(base, power/2);
    double subproblemSq = subproblem * subproblem;
    if (power & 1)
    {
        return base * subproblemSq;
    }
    return subproblemSq;
}
// Time complexity: O(log2(N)) or simply O(log2(N))
// Time complexity: O(log2(N)) or simply O(log2(N))


int main()
{
    // @author Ayush Sharma (ayush08642)
    //cout << powerOfN(1, 10) << endl;
    //cout << powerOfN(2, 10) << endl;
    //cout << powerOfN(0, 0) << endl;
    //cout << powerOfN(0, 10) << endl;
    //cout << powerOfN(5, 10) << endl;
    //cout << powerOfN(5, 0) << endl;
    vector<int> nums({1,2,3,4,4,5});

    print(powerOfN(1, 10));
    print(powerOfN(3, 10));
    print(powerOfN(0, 10));
    print(powerOfN(1, 0));
    print(powerOfN(2, 64));
    print(powerOfN_faster(2, 64));


    return 0;
}