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

vi ans;
void sol(auto &people, int nskills, int cp, vi onesol, int smask)
{
    if (cp == people.size())
    {
        if (smask == ((1 << nskills) - 1))
            if (ans.size() == 0 || onesol.size() < ans.size())
                ans = onesol;
        return;
    }
    sol(people, nskills, cp + 1, onesol, smask); // person not chosen

    onesol.pb(cp);
    sol(people, nskills, cp + 1, onesol, (smask | people[cp]));
    onesol.pop_back(); // helps in backtracking
}

int main()
{
    cout << "\nHello world!" << endl;
    // get skills and prepare the skill mapping
    int ns;
    cin >> ns;
    map<string, int> hashmap;
    for (int i = 0; i < ns; i++)
    {
        string skill;
        cin >> skill;
        hashmap.insert({skill, i});
    }

    int np;
    cin >> np;
    vi people;

    for (int i = 0; i < np; i++)
    {
        int person_skills_cnt;
        cin >> person_skills_cnt;
        people.pb(0);
        for (int j = 0; j < person_skills_cnt; j++)
        {
            string skill;
            cin >> skill;
            int skill_maps = hashmap[skill];
            people[i] = people[i] | (1 << skill_maps);
        }
    }
    cout << "\n========================================\n";
    vi s;
    sol(people, ns, 0, s, 0);
    for (auto prs : ans)
        cout << prs << " ";
    cout << "\n========================================\n";
    return 0;
}

// 3
// java nodejs reactjs
// 3
// 1 java
// 1 nodejs
// 2 nodejs reactjs