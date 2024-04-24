#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static int tribonacci(int n)
    {
        int current = 1, prev = 1, preprev = 0, out = 0;
        if (n <= 0)
        {
            return 0;
        }

        else if (n <= 2)
        {
            return 1;
        }

        for (int i = 3; i <= n; ++i)
        {
            out = preprev + prev + current;
            preprev = prev;
            prev = current;
            current = out;
        }
        return out;
    }
};

void check_passed(bool output)
{
    if (output)
    {
        cout << " PASSED\n"
             << endl;
    }
    else
    {
        cout << " FAILED\n"
             << endl;
    }
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!
    // Test case - 1
    int n1 = 4, expected1 = 4, out1 = Solution::tribonacci(n1);
    printf("n = %d\nOutput: %d\nExpected: %d", n1, out1, expected1);
    check_passed(out1 == expected1);

    int n2 = 25, expected2 = 1389537, out2 = Solution::tribonacci(n2);
    printf("n = %d\nOutput: %d\nExpected: %d", n2, out2, expected2);
    check_passed(out2 == expected2);

    return 0;
}
