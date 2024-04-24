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
    for (T x : v)
    {
        cout << x << ", ";
    }
    cout << endl;
}

void convertInvert(vector<long long> &nums, long long s, long long e, long long &count)
{
    long long mid = s + ((e - s) >> 1);
    long long i = s, k = 0;
    long long j = mid + 1;
    vector<long long> temp(e - s + 1);
    while (i <= mid && j <= e)
    {
        if (nums[i] < nums[j])
        {
            temp[k] = nums[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = nums[j];
            k++;
            j++;
            count += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp[k] = nums[i];
        k++;
        i++;
        count += (mid - i + 1);
    }
    while (j <= e)
    {
        temp[k] = nums[j];
        k++;
        j++;
    }
    cout << ">> ";
    for (int a = s; a <= e; a++)
    {
        cout << nums[a] << ". ";
    }
    printv(temp);
    for (long long p = s, k = 0; p <= e; p++, k++)
    {
        nums[p] = temp[k];
    }
}

void invert(vector<long long> &nums, long long s, long long e, long long &count)
{
    // Base Case
    cout << "\nBase case: s: " << s << " e: " << e << endl;
    if (s >= e)
    {
        cout << "RETurn" << endl;
        return;
    }
    long long mid = s + ((e - s) >> 1);
    // Recursive Calls
    printf("s: %lld, mid: %lld, count: %lld\n", s, mid, count);
    invert(nums, s, mid, count);
    printf("s: %lld, mid + 1: %lld, count: %lld\n", mid + 1, e, count);
    invert(nums, mid + 1, e, count);
    printf("MERGER-> s: %lld, e: %lld, count: %lld\n", s, e, count);
    convertInvert(nums, s, e, count);
    //printv<>(nums);
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    vector<long long> nums ({468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323});

    long long count = 0, n = (long long)(nums.size());
    cout << "Hello" << endl;
    
    invert(nums, 0ll, n - 1, count);
    cout << "Inversion count: " << count << endl;
    return 0;
}