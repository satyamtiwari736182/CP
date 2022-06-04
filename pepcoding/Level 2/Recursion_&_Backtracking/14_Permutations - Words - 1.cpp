// 1. You are given a word (may have one character repeat more than once).
// 2. You are required to generate and print all arrangements of these characters. 

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't 
//                force you but the intention is to teach a concept. Play in spirit of the question.



#include "../header.h"

void getWordPermutation(int cs, int ts, map<char, int> &freq_map, string asf)
{
    if (cs > ts)
    {
        cout << asf << endl;
        return;
    }
    for (auto pr : freq_map)
    {
        char ch = pr.first;
        if (freq_map[ch] > 0)
        {
            freq_map[ch]--;
            getWordPermutation(cs + 1, ts, freq_map, asf + ch);
            freq_map[ch]++;
        }
    }
}

void solve()
{
    string str;
    cin >> str;
     cout<<endl;
    map<char, int> freq_map;
    for (char ch : str)
        freq_map[ch]++;
    getWordPermutation(1, str.length(), freq_map, "");
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}


// aabb
