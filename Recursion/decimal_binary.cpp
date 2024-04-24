#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// 
string decimalToBinary_visualize(int decimal)
{
    if (decimal == 1 || decimal == 0)
    {
        cout << "\"" << to_string(decimal) << "\"" << " + " << "\"\"" << endl;
        return (decimal ? "1" : "0");
    }
    string tmp = decimalToBinary_visualize(decimal / 2);
    cout << "\"" << to_string(decimal%2) << "\"" << " + \"" << tmp << "\"" << endl;
    //return to_string(decimal%2) + decimalToBinary_visualize(decimal / 2);
    return tmp + to_string(decimal%2);
}

string decimalToBinary(int decimal)
{
    if (decimal == 1 || decimal == 0)
    {
        return (decimal ? "1" : "0");
    }
    return to_string(decimal%2) + decimalToBinary(decimal / 2);
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    //Let's start!

    vector<int> nums{0, 1, 5, 10, 50, 16, 63};

    for (auto x : nums)
    {
        cout << decimalToBinary_visualize(x) << endl;
        cout << endl;
    }

    return 0;
}