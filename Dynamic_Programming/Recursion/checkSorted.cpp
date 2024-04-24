#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


bool isSorted(vector<int> nums, int i, int size)
{
    //if (i == size - 2)
    //{ //Both works the same, but this works for nums.length > 1;
    //    return nums[i] < nums[i + 1];
    //}
    if (i == size - 1)
    {
        return true;
    }
    return (nums[i] < nums[i + 1]) && (isSorted(nums, i + 1, size));
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    vector<int> nums1({1, 2, 3, 5, 10, 1024, 100000});
    vector<int> nums2({1, 2, 1024, 3, 5, 10, 100000});

    cout << boolalpha;
    cout << isSorted(nums1, 0, int(nums1.size())) << endl;
    cout << isSorted(nums2, 0, int(nums2.size())) << endl;

    return 0;
}