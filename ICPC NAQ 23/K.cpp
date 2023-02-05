#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int evaluate(int a, int b, int c, char op1, char op2)
{
    int val = a;

    if (op1 == '+')
    {
        val += b;
    }
    else if (op1 == '-')
    {
        val -= b;
    }
    else if (op1 == '*')
    {
        val *= b;
    }
    else if (op1 == '/')
    {
        if (a % b != 0)
            return 3001;
        val /= b;
    }

    if (op2 == '+')
    {
        val += c;
    }
    else if (op2 == '-')
    {
        val -= c;
    }
    else if (op2 == '*')
    {
        val *= c;
    }
    else if (op2 == '/')
    {
        if (val % c != 0)
            return 3001;
        val /= c;
    }

    if (val < 0)
        return 3001;
    return val;
}

int main()
{
    fast_cin();

    int a, b, c;
    cin >> a >> b >> c;

    int ans = a + b + c;

    vector<char> ops = {'+', '-', '*', '/'};

    for (size_t i = 0; i < ops.size(); i++)
    {
        for (size_t j = 0; j < ops.size(); j++)
        {
            int val = evaluate(a, b, c, ops[i], ops[j]);
            ans = min(ans, val);
        }
    }

    cout << ans;
}