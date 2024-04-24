#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <thread>
#include <chrono>
using namespace std;

void vprint(vector<vector<int>> &arr, string prompt)
{
    cout << "- - - - - - - - - " << endl;
    cout << prompt << endl;
    for (vector<int> v : arr)
    {
        for (int x : v)
        {
            this_thread::sleep_for(chrono::milliseconds(150));
            cout << x << "      " << flush;
        }
        cout << endl;
    }
    cout << "- - - - - - - - - " << endl;
}

void generateSpiral_(vector<vector<int>> &arr, int n)
{
    int32_t sqr = n * n;
    int32_t val = 1;
    int32_t cnt = 0;
    int32_t row = 0, col = 0;
    int r = n - 1;
    while (val <= sqr)
    {
        this_thread::sleep_for(chrono::milliseconds(200));
        // Left to Right
        int j = col;
        for (; j < n - cnt; j++)
        {
            printf("---j---\n");
            arr[row][j] = val;
            val++;
        }
        vprint(arr, "Left ---> Right");

        //
        int i = row + 1;
        j--;
        for (; i < n - cnt; i++)
        {
            // printf("i: %d, j: %d\n", i, j);
            arr[i][j] = val;
            val++;
        }
        vprint(arr, "Top vvv Bottom");
        // cout << "ddddddddddddd" << endl;

        // Right to Left
        int l = j - 1;
        printf("row: %d, l: %d\n", row, l);
        for (; l > col; l--)
        {
            printf("row: %d, l: %d\n", row, l);
            arr[r][l] = val;
            val++;
        }
        vprint(arr, "Right <--- Left");

        // Bottom to Top.
        i--;
        int m = i;
        for (; m > row; m--)
        {
            printf("m: %d, cnt: %d\n", m, cnt);
            arr[m][cnt] = val;
            val++;
        }
        vprint(arr, "Bottom ^^^ Top");
        vprint(arr, "loop.............. ");

        row++;
        col++;
        cnt++;
    }
}

void generateSpiral(vector<vector<int>> &v, int n)
{
    int r1 = 0, r2 = n - 1;
    int c1 = 0, c2 = n - 1;
    int val = 0;

    vector<vector<int>> v(n, vector<int>(n));
    while (r1 <= r2 && c1 <= c2)
    {
        for (int i = c1; i <= c2; ++i)
        {
            v[r1][i] = ++val;
        }

        for (int i = r1 + 1; i <= r2; ++i)
        {
            v[i][c2] = ++val;
        }

        if (r1 < r2 && c1 < c2)
        {
            for (int i = c2 - 1; i > c1; --i)
            {
                v[r2][i] = ++val;
            }

            for (int i = r2; i > r1; --i)
            {
                v[i][c1] = ++val;
            }
        }
        ++r1;
        --r2;
        ++c1;
        --c2;
    }
     return v;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!
    int n = 3;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    generateSpiral(arr, n);
    vprint(arr, "Final!");

    return 0;
}