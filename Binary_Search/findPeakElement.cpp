#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
#include <algorithm>
using namespace std;

int findPeakElement(vector<int> v)
{
    int n = int(v.size());
    int low = 0, high = n - 1, mid = 0;
    printf("low: %d, mid: %d, high: %d\n", low, mid, high);

    while (low < high)
    {
        mid = low + ((high - low) >> 1);
        if (v[mid] < v[mid + 1])
        {   //v[mid] < v[mid + 1]
            // If this condition is true, then, we're on the rising edge.
            low = mid + 1;
        }
        else
        {// Else, we're on the falling edge.
            high = mid;
        }

        // Added a delay and printf statement for better visualisation.
        printf("low: %d, mid: %d, high: %d\n", low, mid, high);
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    return v[low];
}

int main()
{
    // @author Ayush Sharma (ayush08642)

    vector<int> in({1, 2, 3, 3, 4, 5, 6, 3, 2, 2, 1});
    //              0  1  2  3  4  5  6  7  8  9  10
    //                             ^
    //                                      ^
    //                                   ^
    //                                ^
    //
    cout << findPeakElement(in) << endl;

    return 0;
}