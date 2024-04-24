#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

void printv(vector<int> &arr)
{
    cout << ">> ";
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int build(vector<int> &tree, vector<int> &arr, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = start + ((end - start) >> 1);
    int left = build(tree, arr, (2 * node), start, mid);
    int right = build(tree, arr, (2 * node) + 1, mid + 1, end);
    tree[node] = min(left, right);
    return tree[node];
}

int query(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
    {
        return INT_MAX;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    int mid = start + ((end - start) >> 1);
    int q1 = query(tree, (2 * node), start, mid, left, right);
    int q2 = query(tree, (2 * node) + 1, mid + 1, end, left, right);
    return min(q1, q2);
}

int main()
{
    int n = 8;
    int k = 4;
    // cin >> n;//
    vector<int> arr({62, 64, 77, 75, 71, 60, 79, 75}), tree(n * 4);

    build(tree, arr, 1, 0, n - 1);
    
    int mx = INT_MIN;
    //printv(arr);
    //printv(tree);
    for (int i = 0; i < n - k; i++)
    {
        mx = max(mx, query(tree, 1, 0, n - 1, i, i + k - 1));
    }

    printf("ans: %d\n", mx);

    return 0;
}
