#include <vector>
#include <string>
#include <iostream>
#include <math>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<vector<int>> memo(s.length(), vector<int>(130, -1));
        return longestIdealString(s, k, 0, '@', memo);
    }

    void print2D(vector<vector<int>> mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    int longestIdealString(string s, int k, int si, char prevChar, vector<vector<int>>& memo) {
        if (si >= int(s.length())) {
            return 0;
        }
        if (memo[si][prevChar] != -1) {
            return memo[si][prevChar];
        }
        int take = 0;
        if (abs(prevChar - s[si]) <= k || prevChar == '@') {
            take = 1 + longestIdealString(s, k, si + 1, s[si], memo);
        }
        int notTake = longestIdealString(s, k, si + 1, prevChar, memo);
        // print2D(memo);
        return memo[si][prevChar] = max(take, notTake);
    }
};
