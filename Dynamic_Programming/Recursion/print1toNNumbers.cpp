#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void print1toNDecreasing(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    // Reverse
    cout << n << " ";
    print1toNDecreasing(n - 1);
}

void print1toNIncreasing(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    print1toNIncreasing(n - 1);
    cout << n << " ";
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!
    print1toNIncreasing(10);
    cout << endl;
    print1toNDecreasing(10);
    cout << endl;

    return 0;
}