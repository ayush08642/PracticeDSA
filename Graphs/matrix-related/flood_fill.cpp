#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

void printq(queue<pair<int, int>> q)
{
    cout << "q> { ";
    while (!q.empty())
    {
        auto &[r, c] = q.front();
        cout << "[" << r << ", " << c << "] ";
        q.pop();
    }
    cout << " }" << endl;
}

void printm(vector<vector<int>> image)
{
    for (auto row : image)
    {
        for (auto p : row)
        {
            cout << p << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    auto &im = image;
    auto &nc = newColor;
    int n = int(im.size()), m = int(im[0].size());
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;


    int originalColor = im[sr][sc];
    q.push({sr, sc});
    im[sr][sc] = nc;
    //printq(q);
    //printm(im);

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        visited.insert(p);
        q.pop();
        int r = p.first, c = p.second;
        pair<int, int> up{r + 1, c}, down{r - 1, c}, left{r, c - 1}, right{r, c + 1};
        if (up.first >= 0 && up.first < n && up.second >= 0 && up.second < m && !visited.count(up) && originalColor == im[up.first][up.second])
        {
            q.push(up);
            im[up.first][up.second] = nc;
        }
        if (down.first >= 0 && down.first < n && down.second >= 0 && down.second < m && !visited.count(down) && originalColor == im[down.first][down.second])
        {
            q.push(down);
            im[down.first][down.second] = nc;
        }
        if (left.first >= 0 && left.first < n && left.second >= 0 && left.second < m && !visited.count(left) && originalColor == im[left.first][left.second])
        {
            q.push(left);
            im[left.first][left.second] = nc;
        }
        if (right.first >= 0 && right.first < n && right.second >= 0 && right.second < m && !visited.count(right) && originalColor == im[right.first][right.second] )
        {
            q.push(right);
            im[right.first][right.second] = nc;
        }
        //printq(q);
        //printm(im);
    }
    return im;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    vector<vector<int>> image({{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    int sr = 1, sc = 1, newColor = 2;

    auto newImage = floodFill(image, sr, sc, newColor);

    return 0;
}