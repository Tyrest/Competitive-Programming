#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    string in;
    cin >> in;

    int vowel_count = 0;
    int y_count = 0;

    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u')
            vowel_count++;
        if (in[i] == 'y')
            y_count++;
    }

    cout << vowel_count << " " << vowel_count + y_count << endl;
}