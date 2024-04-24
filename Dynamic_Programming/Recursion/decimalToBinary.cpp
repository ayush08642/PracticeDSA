#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string decimalToBinary(int num)
{
    if (num == 1 || num == 0)
    {
        return to_string(num);
    }
    int tmp = num % 2;
    return decimalToBinary(num / 2) + to_string(tmp);
}

int main()
{
    // @author Ayush Sharma (ayush08642)

    vector<int> nums({1, 2, 3, 5, 10, 1024, 100000});
    for (auto num : nums)
    {
        cout << num << " : " << decimalToBinary(num) << endl;
    }

    return 0;
}