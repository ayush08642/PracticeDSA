#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

void ok(bool i)
{
    if (i)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int solve()
{
    deque<int> q;
    int n = 0;
    cin >> n;
    vector<int> in(n);

    for (int &x : in)
    {
        cin >> x;
        q.push_back(x);
    }

    int count = 0, i = 0, j = n - 1, prev = INT_MIN;
    int left = 0, right = 0;
    while (!q.empty())
    {
        left = q.front(), right = q.back();
        if (left < right)
        {
            q.pop_front();
            if (prev <= left)
            {
                count++;
            }
            prev = (prev, left);
        }
        else
        {
            q.pop_back();

            if (prev <= right)
            {
                count++;
            }
            prev = (prev, right);
        }
    }
    return count;
}

int main()
{
    // Let's start!
    //  @author Ayush Sharma

    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}