#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> &arr)
{
    for (auto v : arr)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int knapsack(vector<int> &wt, vector<int> &val, int W, int n)
{
    vector<vector<int>> arr(n + 1, vector<int>(W + 1));

    // Base case conversion.
    // for (int i = 0; i < n + 1; i++)
    //{
    //    arr[i][0] = 0;
    //}

    // for (int i = 0; i < W + 1; i++)
    //{
    //     arr[0][i] = 0;
    // }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                arr[i][j] = max(
                    val[i - 1] + arr[i - 1][j - wt[i - 1]],
                    arr[i - 1][j]);
            }
            else // if (wt[i - 1] > j)
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    print(arr);

    return arr[n][W];
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    int numberOfitems = 6;
    vector<int> itemWeights({10, 20, 15, 45, 23, 65});
    vector<int> itemValues({40, 35, 2, 19, 17, 58});
    int weightlimit = 50;

    cout << knapsack(itemWeights, itemValues, weightlimit, numberOfitems) << endl;

    return 0;
}