// Problem: 2997-minimum-number-of-operations-to-make-array-xor-equal-to-k
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stringstream>
using namespace std;

class Solution
{
public:
    int arrayXOR(vector<int> &nums)
    {
        int output = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            output = output ^ nums[i];
        }
        return output;
    }

    std::string intToBinRepr(int num)
    {
        if (num == 0)
        {
            return "0"; // Special case for input 0
        }

        std::string bin = "";
        while (num > 0)
        {
            bin = ((num & 1) ? "1" : "0") + bin;
            num = num >> 1;
        }
        return bin;
    }

    void printBinArr(vector<int> &nums)
    {
        cout << "{ ";
        for (int num : nums)
        {
            printf("[%s], ", intToBinRepr(num).c_str());
        }
        cout << " } ";
    }

    int countOnesInBinRepr(int num)
    {
        int count = 0;
        string snum = intToBinRepr(num);
        for (char c : snum)
        {
            if (c == '1')
            {
                count++;
            }
        }
        return count;
    }

    int minOperations(vector<int> &nums, int k)
    {
        // cout << intToBinRepr(k) << " -> ";
        // printBinArr(nums);
        int xorResult = arrayXOR(nums);
        // cout << "=> " << intToBinRepr(xorResult) << endl;
        if (xorResult == k)
        {
            return 0;
        }

        return countOnesInBinRepr(k ^ xorResult);
    }
};
