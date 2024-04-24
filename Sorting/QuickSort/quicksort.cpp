#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void printv(vector<int> arr)
{
    cout << ">> ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int partition(vector<int> &arr, int start, int end)
{
    int i = start - 1;
    int j = start;
    int pivot = arr[end];

    for (; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[end], arr[++i]);
    return i;
}


void quicksort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = partition(arr, start, end);

    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
}


int main()
{
    // @author Ayush Sharma (ayush08642)

    vector<int> arr ({8, 6, 1, 5, 7, 2, 3, 4, 9});

    int n = int(arr.size());

    printv(arr);
    quicksort(arr, 0, n - 1);
    printv(arr);

    return 0;
}