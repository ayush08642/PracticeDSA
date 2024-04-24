#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int lis(vector<int> &arr, int prev, int cur, int size)
{
    if (cur == size)
    {
        return 0;
    }
    int op1 = 0, op2 = 0;
    if (prev == -1 || arr[prev] < arr[cur])
    {
        op1 = 1 + lis(arr, cur, cur + 1, size);
    }
    op2 = lis(arr, prev, cur, size);
    return max(op1, op2);
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    vector<int> arr({1, 2, 5, 3, 4});

    cout << lis(arr, -1, 0, int(arr.size()));
    return 0;
}

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    KthLargest(int k, vector<int> &nums)
    {
        n = k;
        for (auto c : nums)
        {
            pq.push(c);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > n)
        {
            pq.pop();
        }
        return pq.top();
    }
};
