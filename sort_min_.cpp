#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;


// At most once. // 
void checkOneSwapSort(vector<int> &nums)
{
    int n = int(nums.size());
    int count_mismatch = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != (i + 1))
        {
            count_mismatch++;
            if (count_mismatch > 2)
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    int n = 0;
    cin >> n;
    vector<int> in(n, 0);

    for (int &a : in)
    {
        cin >> a;
    }
    checkOneSwapSort(in);
    return 0;
}