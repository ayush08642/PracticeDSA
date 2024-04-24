#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

static int arr[1001][1001]; //= {{-1}};
void *p = memset(arr, -1, sizeof arr);

int knapsack(vector<int> &val, vector<int> &wght, int W, int n)
{
    if (arr[n][W] != -1)
    {
        return arr[n][W];
    }

    // Base case.
    if (n == 0 || W == 0)
    {
        arr[n][W] = 0;
        return 0;
    }

    if (wght[n - 1] <= W)
    {
        arr[n][W] = max(
            val[n - 1] + knapsack(val, wght, W - wght[n - 1], n - 1),
            knapsack(val, wght, W, n - 1));
        return arr[n][W];
    }
    else if (wght[n - 1] > W)
    {
        arr[n][W] = knapsack(val, wght, W, n - 1);
        return arr[n][W];
    }
    return 0;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    int numberOfitems = 6;
    vector<int> itemWeights({10, 20, 15, 45, 23, 65});
    vector<int> itemValues({40, 35, 2, 19, 17, 58});
    int weightlimit = 50;

    cout << knapsack(itemValues, itemWeights, weightlimit, numberOfitems) << endl;

    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}