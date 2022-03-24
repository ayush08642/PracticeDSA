#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<string> getTokens(string input)
{
    stringstream ss(input);

    string token;
    vector<string> out;

//  Without delimiter, it'll not break down the string to tokens and return the whole string at once.
    while (getline(ss, token, ','))
    {
        out.push_back(token);
    }

    return out;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    //Let's start!
    string input;
    getline(cin, input);

    auto output = getTokens(input);

    for (auto x : output)
    {
        cout << "\"";
        cout << x << "\" ";
    }
    cout << endl;

    return 0;
}