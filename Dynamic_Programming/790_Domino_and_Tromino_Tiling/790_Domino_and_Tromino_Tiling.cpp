#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int MOD = 1'000'000'007;
    unordered_map<int, long> f_cache;
    unordered_map<int, long> p_cache;

    long p(int n)
    {
        if (p_cache.find(n) != p_cache.end())
        {
            return p_cache[n];
        }
        long val = 0;
        if (n == 2)
        {
            val = 1l;
        }
        else
        {
            val = (p(n - 1) + f(n - 2)) % MOD;
        }
        p_cache[n] = val;
        return val;
    }

    long f(int n)
    {
        if (f_cache.find(n) != f_cache.end())
        {
            return f_cache[n];
        }
        long val = 0;
        if (n == 1)
        {
            val = 1l;
        }
        else if (n == 2)
        {
            val = 2l;
        }
        else
        {
            val = (f(n - 1) + f(n - 2) + 2 * p(n - 1)) % MOD;
        }
        f_cache[n] = val;
        return val;
    }

    int numTilings(int n)
    {
        return static_cast<int>(f(n));
    }
};


// Time complexity: O(N)
// Space complexity: O(N)

// Extra remarks: None