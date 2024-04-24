#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int subsetSum(vector<int> &nums, int sum, int n)
{
    if (sum == 0 || n == 0)
    {
        return 0;
    }
    if (nums[n - 1] <= sum)
    {
        return max(
            nums[n - 1] + subsetSum(nums, sum - nums[n - 1], n - 1),
            subsetSum(nums, sum, n - 1));
    }
    else if (nums[n - 1] > sum)
    {
        return subsetSum(nums, sum, n - 1);
    }
    return 0;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!
    int n = 5;
    vector<int> nums({2, 3, 7, 8, 10});
    int sum = 2;

    cout << boolalpha <<( subsetSum(nums, sum, n) == sum) << endl;

    return 0;
}