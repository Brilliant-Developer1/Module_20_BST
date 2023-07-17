// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void level_order(Node *root)
{
    if (!root)
        return;

    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        Node *f = que.front();
        que.pop();

        cout << f->value << " ";

        if (f->left)
            que.push(f->left);
        if (f->right)
            que.push(f->right);
    }
}
Node *convert(int array[], int n, int L, int R)
{
    if (L > R)
        return NULL;
    int mid = (L + R) / 2;

    Node *root = new Node(array[mid]);

    Node *leftRoot = convert(array, n, L, mid - 1);
    Node *rightRoot = convert(array, n, mid + 1, R);

    root->left = leftRoot;
    root->right = rightRoot;
    return root;
}

int main()
{
    // Node *root = input_tree();
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    Node *root = convert(array, n, 0, n - 1);

    level_order(root);

    return 0;
}