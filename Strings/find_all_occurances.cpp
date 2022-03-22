#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> find_all_occr(string para, string word)
{
    int index = int(para.find(word));
    vector<int> out;
    while (index != -1)
    {
        out.push_back(index);
        index = int(para.find(word, index + 1));
    }
    return out;
}


int main()
{
    // @author Ayush Sharma (ayush08642)
    //Let's start!

    string para = "Hello, my name is business wale Mohan-pyaare Rajdulaare. I'm a business owner. I work in real estate business.";

    auto out = find_all_occr(para, "business");
    if (out.size() > 0)
    {
        cout << '\n' << para << endl;
        int i = 0;
        for (auto x : out)
        {
            for (; i < x; i++)
            {
                cout << " ";
            }
            cout << "^";
            i++;
        }
        cout << endl;
    }
    else{
        cout << "\nNo occurances found!" << endl;
    }

    return 0;
}