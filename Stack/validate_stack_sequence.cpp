#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl;
}

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int i = 0, j = 0;
    int n = int(pushed.size()), m = int(popped.size());

    st.push(pushed[0]);

    while (i < n && j < m)
    {
        if (!st.empty())
        {
            if (i == n - 1 && popped[j] != st.top())
            {
                return false;
            }
            while (st.top() != popped[j] && i < n)
            {
                i++;
                st.push(pushed[i]);
                print(st);
            }
            st.pop();
            j++;
            cout << "pop: " << endl;
            print(st);
        }
        cout << "..";
    }
    if (i == n - 1 && j == m - 1)
    {
        return true;
    }
    return false;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!

    vector<int> pushed({1, 2, 3, 4, 5}), popped({1, 2, 3, 4, 5});
    cout << boolalpha << validateStackSequences(pushed, popped) << endl;

    return 0;
}
