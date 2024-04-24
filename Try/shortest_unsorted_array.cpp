#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

void print(vector<int> &v)
{
    cout << "> ";
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> tryfind(vector<int> &arr)
{
    int n = int(arr.size());
    vector<int> pre(n), post(n);
    int sum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = max(sum, arr[i]);
        post[i] = sum;
    }

    sum = INT_MAX;

    for (int i = n - 1; i >= 0; i--)
    {
        sum = min(sum, arr[i]);
        pre[i] = sum;
    }

    print(arr);
    print(pre);
    print(post);

//  2, 6, 4, 8, 10, 9, 15
    int start = 0, end = 0;
    bool start_flag = true;
    for (int i = 0; i < n; i++)
    {
        if ((pre[i] != post[i]) && start_flag)
        {
            start_flag = false;
            start = i;
            end = i;
        }
        else if (pre[i] != post[i])
        {
            end = max(end, i);
        }
    }

    vector<int> out(arr.begin() + start, arr.begin() + end + 1);
    cout << endl;
    print(out);
    return out;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    vector<int> arr({2, 6, 4, 8, 10, 9, 15});
    auto v = tryfind(arr);

    return 0;
}