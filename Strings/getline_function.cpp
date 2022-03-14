#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main()
{
    // @author Ayush Sharma (ayush08642)
    string s;

//  Takes whole line as input and terminates input of one string when encounters a LF(\n).
    getline(cin, s);

//  getline(input_stream, variable_to_store, delimiting_character)
    getline(cin, s, '.');

    cout << s << endl;

    return 0;
}