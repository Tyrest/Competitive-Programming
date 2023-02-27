#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

class Node
{
    int val;
    vector<Node> children;

    Node(string t)
    {
        int i = t.find(' ');
        val = atoi(t.substr(0, i).c_str());
        s = 
        while (i != string::npos)
        {
            i = t.find(')', i + 1)
        }
    }
}

int main()
{
    fast_cin();

    string a;
    getline(std::cin, a);
    string b;
    getline(std::cin, b);
    Node(a);
}