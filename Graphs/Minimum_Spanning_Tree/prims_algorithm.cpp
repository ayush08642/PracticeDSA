#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Graph
{
    // Adjacency list
    vector<pair<int,int>> *l; 
    // We're using pair of int to int, because, it's a weighted graphs.
    int V = 0;

public:
    Graph(int n):V(n)
    {
        this->l = new vector<pair<int, int>>[n];
    }

    void addEdge(int from, int to, int weight)
    {
        l[from].push_back({to, weight});
        l[to].push_back({from, weight});
    }

    // Minimum Spanning Tree using Prim's algorithm.
    int primMST()
    {
        //priority_queue<int, vector<int>, greater<int>> qq; // Min heap.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        // Array to maintain wether the node is visited or not, boolean array.
        vector<bool> visited(this->V, false);

        // {weight, node}
        q.push({0, 0}); // Source node.
        int answer = 0;
        
        while(!q.empty())
        {
            // pick-up an active edge with minimum weight.
            pair<int, int> best = q.top();
            q.pop();

            int to = best.second;
            int weight = best.first;

            // Check if visited.
            if (visited[to])
            {
                continue;
            }
            // Else:
            answer += weight;
            visited[to] = true;

        //             pair     vector, where l is an array.
            for (auto &[w, f] : l[to])
            {
                if (!visited[f])
                {
                    q.push({w, f});
                }
            }
        }
        return answer;
    }
};


int main(int argc, char const *argv[])
{
    


    return 0;
}

