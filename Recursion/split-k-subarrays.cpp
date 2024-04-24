#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(int mid, int arr[], int n, int K)
    {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
            {
                return false;
            }
            sum += arr[i];
            // If the sum is greater than
            // mid increase count
            if (sum > mid)
            {
                count++;
                sum = arr[i];
            }
        }
        count++;
        // Check condition
        if (count <= K)
        {
            return true;
        }
        return false;
    }

    long long solve(int N, int K, int A[])
    {
        // add your code
        auto &a = A;
        int n = N, k = K;
        int start = 0; // *max_element(a, a + n);
        int end = 0;

        for (int i = 0; i < n; i++)
        {
            start = max(start, a[i]);
            end += a[i];
        }
        cout << "start: " << start << " : end: " << end << endl;

        int out = 0;
        while (start <= end)
        {
            cout << "loop: " << start << " : " << end << endl;
            int mid = start + ((end - start) >> 1);
            cout << "mid: " << mid << endl;
            if (check(mid, a, n, k))
            {
                out = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return out;
    }
};

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!
    Solution s;
    int k = 2, n = 4;
    int arr[4] = {3, 10, 5, 20};
    cout << s.solve(n, k, arr) << endl;

    return 0;
}