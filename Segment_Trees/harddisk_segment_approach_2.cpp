#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

//void printv(vector<int> &arr)
//{
//    cout << ">> ";
//    for (auto x : arr)
//    {
//        cout << x << " ";
//    }
//    cout << endl;
//}

int minq(deque<int> q)
{
    int mn = INT_MAX;
    while (!q.empty())
    {
        cout << q.front() << " ";
        mn = min(mn, q.front());
        q.pop_front();
    }
    cout << endl;
    return mn;
}

int segments(vector<int> arr, int k, int n)
{
    deque<int> q;

// Creating the window.
    for (int i = 0; i < k; i++)
    {
        q.push_back(arr[i]);
    }

    int mx = minq(q);

// Traversing the window in the array.
    for (int i = k; i < n; i++)
    {
        q.push_back(arr[i]);
        q.pop_front();
        mx = max(mx, minq(q));
    }
    return mx;
}

int main()
{
    int n = 8;
    int k = 4;
    // cin >> n;//
    vector<int> arr({62, 64, 77, 75, 71, 60, 79, 75});
    //printv(arr);
    int ans = segments(arr, k, n);

    printf("ans: %d\n", ans);

    return 0;
}
