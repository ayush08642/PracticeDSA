#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void prints(stack<string> s)
{
    cout << endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

string simplifyPath(string path)
{
    int n = int(path.size());
    auto &p = path;

    stack<string> st;
    string out = "", temp = "";
    for (int i = 0; i < n; i++)
    {
        // We shall take care of slashes at the end.
        if (p[i] == '/')
        {
            continue;
        }
        temp = "";
        while (i < n && p[i] != '/')
        {
            temp += p[i];
            i++;
        }
        // It doesn't matter us if it points to current folder.
        if (temp == ".")
        {
            continue;
        }
        // If it's previous folder than.. pop the stack to go up one directory.
        else if (temp == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(temp);
        }
    }
    if (st.empty())
    {
        return "/";
    }

    while (!st.empty())
    {
        out = "/" + st.top() + out;
        st.pop();
    }
    return out;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    vector<string> paths({"/home//foo/", "/../", "/home/"});
    for (string path : paths)
    {
        cout << simplifyPath(path) << "|" << endl;
    }

    return 0;
}