#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int knapsack(vector<int> &val, vector<int> &wght, int maxwght, int n)
{
    if (n == 0 || maxwght == 0)
    {
        return 0;
    }

    if (wght[n - 1] <= maxwght)
    {
        return max(
            val[n - 1] + knapsack(val, wght, maxwght - wght[n - 1], n - 1),
            knapsack(val, wght, maxwght, n - 1));
    }
    else if (wght[n - 1] > maxwght)
    {
        return knapsack(val, wght, maxwght, n - 1);
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

    return 0;
}