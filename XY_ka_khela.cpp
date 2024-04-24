// Walmart Aishwarya Veldoj


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int countPairs(vector<int> p, vector<int> q, int n, int m)
{
    vector<int> a({0, 0}), b({0, 0});
    for (int i = 0; i < n; i++)
    {
        a[p[i] % 2]++;
    }
    for (int i = 0; i < m; i++)
    {
        b[q[i] % 2]++;
    }
    return (a[0] * b[0]) + (a[1] * b[1]);
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    int n = 0;
    cin >> n;
    vector<int> p(n, 0);
    for (int &x : p)
    {
        cin >> x;
    }

    int m = 0;
    cin >> m;
    vector<int> q(m, 0);
    for (int &x : q)
    {
        cin >> x;
    }

    int cnt = countPairs(p, q, n, m);
    cout << cnt << endl;

    return 0;
}
