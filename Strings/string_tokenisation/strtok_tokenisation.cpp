#include <iostream>
#include <string>
#include <cstring> // for strtok.
using namespace std;


int main()
{
    // @author Ayush Sharma (ayush08642)
    //Let's start!

    char input[1000];

    cin.getline(input, 1000);

// strtok takes two strings as input, first is to store token and other for delimiter.
    char* token = strtok(input, " ");

    while(token != nullptr)
    {
        cout << token << endl;
        token = strtok(nullptr, " ");
    }

    return 0;
}