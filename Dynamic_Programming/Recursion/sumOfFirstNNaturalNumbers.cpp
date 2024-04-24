#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int sumOfN(int n)
{
    if (n < 1)
    {
        return -1;
    }
    if (n == 1)
    {
        return n;
    }
    return n + sumOfN(n - 1);
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    //Let's start!

    vector<int> nums({1, 2, 3, 5, 10, 1024, 100000});
    for (auto num : nums)
    {
        cout << num << " : " << sumOfN(num) << endl;
    }

    return 0;
}