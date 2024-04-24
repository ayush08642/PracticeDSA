/**
 * @file building_tree.cpp
 * @author Ayush Sharma (ayush.sharma08642.com)
 * @brief Segment Tree (Basic operations)
 * @date 2022-04-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

void print(vector<int> arr)
{
    cout << ">> ";
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

void print_tree(vector<int> tree)
{
    int n = int(tree.size());
    int br = 1;
    for (int i = 1; i < n; i++)
    {
        cout << tree[i] << " ";
        if (i == br)
        {
            cout << endl;
            br = (br * 2) + 1;
        }
    }
    cout << endl;
}

void build_sum_tree(vector<int> &arr, vector<int> &sum_tree, int node, int start, int end)
{
    if (start == end)
    {
        sum_tree[node] = arr[start];
        return;
    }
    int mid = start + ((end - start) >> 1);
    build_sum_tree(arr, sum_tree, (2 * node), start, mid);
    build_sum_tree(arr, sum_tree, (2 * node) + 1, mid + 1, end);
    // print(sum_tree);
    sum_tree[node] = sum_tree[node * 2] + sum_tree[(node * 2) + 1];
    // print(sum_tree);
}

//        [Left to right] is the desired segment range.
int query_sum_tree(vector<int> sum_tree, int node, int start, int end, int left, int right)
{
    // (start .. end ... left .. right) OR (left .. right ... start .. end)
    // No Overlapping.
    if (right < start || left > end)
    {
        return 0;
    }

    // Complete overlapping.
    // left ... start .. end ... right
    if (left <= start && end <= right)
    {
        return sum_tree[node];
    }

    // (left.. start .. right .. end) or (start .. left .. end .. right)
    // Partial overlapping.
    // if (right > start || left < end)
    //{    //}
    int mid = start + ((end - start) >> 1);
    int q1 = query_sum_tree(sum_tree, (2 * node), start, mid, left, right);
    int q2 = query_sum_tree(sum_tree, (2 * node) + 1, mid + 1, end, left, right);
    return q1 + q2;
}

int update_sum_tree(vector<int> &tree, int node, int index, int new_val, int start, int end)
{
    // No overlapping
    // (index ... start .. end) or (start .. end ... index)
    if (index < start || end < index)
    {
        return tree[node];
    }

    if (index == start && index == end)
    {
        tree[node] = new_val;
        return tree[node];
    }

    int mid = start + ((end - start) >> 1);
    int left = update_sum_tree(tree, (2 * node), index, new_val, start, mid);
    int right = update_sum_tree(tree, (2 * node) + 1, index, new_val, mid + 1, end);
    tree[node] = left + right;
    return tree[node];
}

int build_max_tree(vector<int> &arr, vector<int> &max_tree, int node, int start, int end)
{
    if (start == end)
    {
        max_tree[node] = arr[start];
        return max_tree[node];
    }
    // elements:  1 2 3 4 5 6 7 8
    // indices:   0 1 2 3 4 5 6 7
    int mid = start + ((end - start) >> 1);
    int left = build_max_tree(arr, max_tree, (2 * node), start, mid);
    int right = build_max_tree(arr, max_tree, (2 * node) + 1, mid + 1, end);

    max_tree[node] = max(left, right);
    return max_tree[node];
}

//        [Left to right] is the desired segment range.
int query_max_tree(vector<int> &max_tree, int node, int start, int end, int left, int right)
{
    // No-overlapping...
    // (start .. end ... left .. right) OR (left .. right ... start .. end)
    if (end < left || right < start)
    {
        return INT_MIN;
    }

    // Completely overlapping.
    //   left .. start ... end .. right
    if (left <= start && end <= right)
    {
        return max_tree[node];
    }

    // Partial Overlapping...
    int mid = start + ((end - start) >> 1);
    int q1 = query_max_tree(max_tree, (2 * node), start, mid, left, right);
    int q2 = query_max_tree(max_tree, (2 * node) + 1, mid + 1, end, left, right);
    // printf("start: %d, end: %d\n", start, end);
    // printf("q1: %d, q2: %d\n\n", q1, q2);
    return max(q1, q2);
}

int update_max_tree(vector<int> &tree, int node, int index, int val, int start, int end)
{
    if (start > index || end < index)
    {
        return tree[node];
    }
    if (start == index && start == end)
    {
        tree[node] = val;
        return tree[node];
    }
    int mid = start + ((end - start) >> 1);
    int left = update_max_tree(tree, (2 * node), index, val, start, mid);
    int right = update_max_tree(tree, (2 * node) + 1, index, val, mid + 1, end);
    tree[node] = max(left, right);
    return tree[node];
}

/**
 * @brief build_min_tree, builds a segment tree using divide and conquer approach.
 *
 * @param arr is the given vector
 * @param min_tree minimum segment tree
 * @param node current node, represented using index.
 * @param start start of current segment.
 * @param end end of current segment.
 * @return int
 */
int build_min_tree(vector<int> &arr, vector<int> &min_tree, int node, int start, int end)
{
    if (start == end)
    {
        min_tree[node] = arr[start];
        return min_tree[node];
    }
    int mid = start + ((end - start) >> 1);
    int left = build_min_tree(arr, min_tree, (2 * node), start, mid);
    int right = build_min_tree(arr, min_tree, (2 * node) + 1, mid + 1, end);
    min_tree[node] = min(left, right);
    return min_tree[node];
}

int query_min_tree(vector<int> &min_tree, int node, int start, int end, int left, int right)
{
    // No overlapping.
    // (left ... right .. start ... end) or (start ... end .. left ... right)
    if (right < start || end < left)
    {
        return INT_MAX;
    }

    // Complete overlapping..
    // left .. start ... end .. right
    if (left <= start && end <= right)
    {
        return min_tree[node];
    }

    // Partial overlapping..
    int mid = start + ((end - start) >> 1);
    int q1 = query_min_tree(min_tree, (2 * node), start, mid, left, right);
    int q2 = query_min_tree(min_tree, (2 * node) + 1, mid + 1, end, left, right);
    return min(q1, q2);
}

int update_min_tree(vector<int> &tree, int node, int index, int val, int start, int end)
{
    if (start > index || end < index)
    {
        return tree[node];
    }

    if (start == index && start == end)
    {
        tree[node] = val;
        return tree[node];
    }

    int mid = start + ((end - start) >> 1);
    int left = update_max_tree(tree, (2 * node), index, val, start, mid);
    int right = update_max_tree(tree, (2 * node) + 1, index, val, mid + 1, end);
    tree[node] = min(left, right);
    return tree[node];
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    // Let's start!

    int n = 0;
    cin >> n;
    vector<int> arr(n), sum_tree((2 * n) + 2), max_tree((2 * n) + 2), min_tree((2 * n) + 2);

    for (int &x : arr)
    {
        cin >> x;
    }

    //*****-----******---*****-----******---*****-----******
    build_sum_tree(arr, sum_tree, 1, 0, n - 1);
    cout << endl
         << '\n';

    cout << "Sum Segment tree" << endl;
    print_tree(sum_tree);

    while (true)
    {
        int type = -1;
        cout << "option: (-1 : exit,  1 : rangeQuery, 2 : update";
        cin >> type;

        if (type == -1)
        {
            cout << "\nEnd of sum query." << endl;
            break;
        }
        else if (type == 1)
        {
            int l, r;
            cout << "\nEnter l & r: " << endl;
            cin >> l >> r;
            int q = query_sum_tree(sum_tree, 1, 0, n - 1, l, r);
            printf("q_sum: %d\n", q);
        }
        else
        {
            int index, new_val;
            cout << "Enter index and new_val: " << endl;
            cin >> index >> new_val;
            update_sum_tree(sum_tree, 1, index, new_val, 0, n - 1);
            print_tree(sum_tree);
        }
    }

    //*****-----******---*****-----******---*****-----******
    build_max_tree(arr, max_tree, 1, 0, n - 1);
    cout << endl
         << '\n';
    cout << "Max Segment tree" << endl;
    print_tree(max_tree);

    while (true)
    {
        int type;
        cout << "option: (-1 : exit,  1 : rangeQuery, 2 : update\n";
        cin >> type;
        if (type == -1)
        {
            cout << "\nEnd of max query." << endl;
            break;
        }
        else if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int q = query_max_tree(max_tree, 1, 0, n - 1, l, r);
            printf("\nq_max: %d\n", q);
        }
        else
        {
            int index, new_val;
            cout << "Enter index and new_val: " << endl;
            cin >> index >> new_val;
            update_max_tree(max_tree, 1, index, new_val, 0, n - 1);
            print_tree(max_tree);
        }
    }

    //*****-----******---*****-----******---*****-----******
    build_min_tree(arr, min_tree, 1, 0, n - 1);
    cout << endl
         << '\n';
    cout << "Min Segment tree" << endl;
    print_tree(min_tree);

    while (true)
    {
        int type;
        cout << "option: (-1 : exit,  1 : rangeQuery, 2 : update\n";
        cin >> type;
        if (type == -1)
        {
            cout << "\nEnd of min query." << endl;
            break;
        }
        else if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int q = query_min_tree(min_tree, 1, 0, n - 1, l, r);
            printf("\nq_min: %d\n", q);
        }
        else
        {
            int index, new_val;
            cout << "Enter index and new_val: " << endl;
            cin >> index >> new_val;
            update_min_tree(min_tree, 1, index, new_val, 0, n - 1);
            print_tree(min_tree);
        }
    }

    return 0;
}