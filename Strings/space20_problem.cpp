#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string space20(string input)
{
    int space_cnt = 0;
    for (char c : input)
    {
        if (c == ' ')
        {
            space_cnt++;
        }
    }

    int n = int(input.size());
    int total = n + (space_cnt * 3);
    string out; out.reserve(total);

    cout << input << endl << endl;
    for (int i = total - 1, j = n - 1; i >= 0 && j >= 0; i--, j--)
    {
        cout << out << "|" << endl;
        if (input[j] == ' ')
        {
            out = "0" + out; i--;
            out = "2" + out; i--;
            out = "%" + out; i--;
        }
        else{
            out = input[j] + out;
        }
    }
    return out;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!

    string out = "Hello I'm Mohan Pyaare, raj dulare..";

    cout << space20(out) << endl;

    return 0;
}