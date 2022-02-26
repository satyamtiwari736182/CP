
#include <bits/stdc++.h>
using namespace std;

#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)

#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];

#define rvarr(arr, l, r)        \
    for (int i = l; i < r; i++) \
    {                           \
        int val;                \
        cin >> val;             \
        arr.push_back(val);     \
    }

#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
        {                           \
            int val;                \
            cin >> val;             \
            arr[i].push_back(val);  \
        }

#define pmatrix(arr, n, m)            \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
            cout << arr[i][j] << " "; \
        cout << endl;                 \
    }

#define vi vector<int>
#define vs vector<string>
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ll long long
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mod 1000000007
const int INF = 1e9 + 7;
const double PI = 3.141592653589793238;
const int M = 100, N = 100;

vi findNumOfValidWords(auto &words, auto &puzzles)
{
    map<char, vi> hashmap;

    for (string word : words)
    {
        int mask = 0;
        for (char ch : word)
        {
            int bit = ch - 'a';
            mask = mask | (1 << bit);
        }

        set<char> unique;
        for (char ch : word)
        {
            if (unique.find(ch) != unique.end())
                continue;
            hashmap[ch].pb(mask);
            unique.insert(ch);
        }
    }

    vi res;
    for (string puzzle : puzzles)
    {
        int pmask = 0;
        for (char ch : puzzle)
        {
            int bit = ch - 'a';
            pmask = pmask | (1 << bit);
        }
        char ftch = puzzle[0];

        vi wordsToCheck;
        if (hashmap.find(ftch) != hashmap.end())
            wordsToCheck = hashmap[ftch];
        int count = 0;

        for (int wmask : wordsToCheck)
            if ((wmask & pmask) == wmask)
                count++;

        res.pb(count);
    }

    return res;
}

int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    vs words;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.pb(word);
    }

    int m;
    cin >> m;
    vs puzzles;
    for (int i = 0; i < m; i++)
    {
        string puz;
        cin >> puz;
        puzzles.pb(puz);
    }

    cout << "\n========================================\n";
    vi ans = findNumOfValidWords(words, puzzles);
    for (int i = 0; i < ans.size(); i++)
        cout << puzzles[i] << " -> " << ans[i] << endl;

    cout << "\n========================================\n";
    return 0;
}

// 7
// aaaa asas able ability actt actor access
// 6
// aboveyz abrodyz abslute absoryz actresz gaswxyz