#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> ans;
 
    unordered_set<string> found;
 
    for (int i = 0; i < n; i++) {
 
        string word = words[i];
 
        sort(begin(word), end(word));
 
        if (found.find(word) == found.end()) {
 
            ans.push_back(words[i]);
            found.insert(word);
        }
    }
 
    // Sort the resultant vector of strings
    sort(begin(ans), end(ans));
    return ans;
}