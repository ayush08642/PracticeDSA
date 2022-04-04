#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

namespace my{
    int lower_bound(vector<int> &nums, int key)
    {
        int start = 0, end = int(nums.size()) - 1;
        int mid = -1, out = -1;

        while (start <= end)
        {
            mid = start + ((end - start) >> 1);
            if (nums[mid] == key)
            {
                out = mid;
                end = mid - 1;
            }
            else if (nums[mid] > key)
            {
                end = mid - 1;
            }
            else if (nums[mid] < key)
            {
                start = mid + 1;
            }
        }
        return out;
    }
}

int main()
{
    // @author Ayush Sharma (ayush08642)

    vector<int> in({1, 2, 2, 2, 3, 4, 5, 5, 6, 6, 6, 7, 8});
    cout << my::lower_bound(in, 5) << endl;

    return 0;
}