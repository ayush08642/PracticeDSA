#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Node
{
    int val = 0;
    list<Node *> nbrs;
};

class Graph
{
private:
    int V = 0;
    list<int> *l;

public:
    Graph(int v)
    {
        this->V = v;
        this->l = new list<int>[V];
    }

    void addEdge(int vi, int vj, bool undir=true)
    {
        l[vi].push_back(vj);
        if (undir && (vj != vi))
        {x
            l[vj].push_back(vi);
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < this->V; i++)
        {
            cout << i << " -> ";
            for (int node : l[i])
            {
                cout << node << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!

    Graph g(6);

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    //g.addEdge(2, 2);
    g.addEdge(2, 2);
    g.addEdge(4, 5);
    g.addEdge(5, 2);

    g.printAdjList();

    return 0;
}