#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int> people, int weight_limit)
{
    int i, j;
    // Time complexity of sorting: O(nLog(n)) .
    sort(people.rbegin(), people.rend());
    for (auto x : people)
    {
        cout << x << " ";
    }
    cout << endl;
    int n = int(people.size());
    for (i = 0, j = n - 1; i <= j; ++i)
    {
        if (people[i] + people[j] <= weight_limit)
        {
            j--;
        }
        printf("i: %d, j: %d,\n", i, j);//, people[i], people[j], people[i] + people[j]);
    }
    return i;
}
// Overall Time complexity of above function: O(nLog(n)) .

int main()
{
    // @author Ayush Sharma (ayush08642)
    vector<int> people1({ 3,2,2,1});
    int weight_limit1 = 3;
    cout << numRescueBoats(people1, weight_limit1) << endl;

    vector<int> people2({ 3,5,3,4});
    int weight_limit2 = 5;
    cout << numRescueBoats(people2, weight_limit2) << endl;

    return 0;
}