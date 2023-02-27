#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void cascade(list<string> &hand, list<string>::iterator t_end)
{
    list<string>::iterator t = hand.end();
    list<string>::iterator b = hand.end();
    for (size_t i = 0; i < 3; i++)
    {
        if (b == hand.begin())
        {
            continue;
        }

        b--;
    }
    list<string>::iterator maybe = hand.begin();

    while (t != t_end && b != hand.begin())
    {
        t--;
        b--;
        
        if ((*t)[0] == (*b)[0])
        {
            t = hand.erase(t);
            for (size_t i = 0; i < 3; i++)
            {
                t--;
                t = hand.erase(t);
            }
            cascade(hand, t_end);
            return;
        }
        else if ((*t)[1] == (*b)[1])
        {
            if (maybe == hand.begin())
            {
                maybe = t;
            }
        }
    }
    
    t = maybe;
    b = t;
    for (size_t i = 0; i < 3; i++)
    {
        if (b == hand.begin())
        {
            return;
        }

        b--;
    }

    hand.erase(t);
    b = hand.erase(b);
    cascade(hand, b);
}

int main()
{
    fast_cin();
    // cout << "HERE\n";

    list<string> hand;
    string tmp;
    cin >> tmp;
    hand.push_back(tmp);
    for (size_t i = 0; i < 51; i++)
    {
        cin >> tmp;
        // cout << tmp << '\n';
        hand.push_back(tmp);
        list<string>::iterator tmp_it = hand.end();
        tmp_it--;
        cascade(hand, tmp_it);
        // for (list<string>::iterator it = hand.begin(); it != hand.end(); it++)
        // {
        //     cout << *it << ' ';
        // }
        // cout << '\n';
    }
    

    cout << hand.size();
    for (list<string>::iterator it = hand.begin(); it != hand.end(); it++)
    {
        cout << ' ' << *it;
    }
}

// void cascade(vector<string> &hand)
// {
//     unordered_set<int> inds;
//     for (int i = hand.size() - 1; i >= 3; i--)
//     {
//         if (inds.find(i) == inds.end())
//         {
//             if (hand[i][0] == hand[i - 3][0])
//             {
//                 inds.insert(i);
//                 inds.insert(i - 1);
//                 inds.insert(i - 2);
//                 inds.insert(i - 3);
//                 break;
//             }
//             else if (hand[i][1] == hand[i - 3][1])
//             {
//                 inds.insert(i);
//                 inds.insert(i - 3);
//             }
//         }
//     }

//     vector<string> new_hand;
//     for (size_t i = 0; i < hand.size(); i++)
//     {
//         if (inds.find(i) == inds.end())
//         {
//             new_hand.push_back(hand[i]);
//         }
//     }

//     hand = new_hand;
// }