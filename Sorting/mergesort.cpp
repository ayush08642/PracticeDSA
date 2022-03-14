#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

template<typename T>
void printv(vector<T> v)
{
    cout << "\n> ";
    for (T vi : v)
    {
        cout << vi << " ";
    }
    cout << endl;
}

// Helper function
void merge(vector<int> &arr, int start, int end)
{
    vector<int> temp(end - start);
    int mid = start + ((end - start) >> 1);
    int i = start, j = mid + 1, k = 0;

    while(i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int p = start, q = 0; p <= end; p++, q++)
    {
        arr[p] = temp[q];
    }
}


// Sorting function
void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + ((end - start) >> 1);

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}


int main()
{
    // @author Ayush Sharma (ayush08642)
    vector<int> arr ({49, 36, 25, 16, 9, 4, 121, 100, 81, 64});
    int start = 0, end = static_cast<int>(arr.size() - 1);
    // Before
    printv<int>(arr);

    mergeSort(arr, start, end);

    // After
    printv<>(arr);

    return 0;
}