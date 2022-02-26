#include <bits/stdc++.h>
using namespace std;

#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)

#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];

#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
    {                               \
        vi vec;                     \
        for (int j = 0; j < m; j++) \
        {                           \
            int x;                  \
            cin >> x;               \
            vec.pb(x);              \
        }                           \
        arr.pb(vec);                \
    }

#define pmatrix(arr, n, m)            \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
            cout << arr[i][j] << " "; \
        cout << endl;                 \
    }

#define vi vector<int>
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

int sliding_puzzle(vector<vi> &grid)
{
    queue<string> que;
    string target = "123450";
    string initial_state;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            initial_state = initial_state + to_string(grid[i][j]);
    vector<vi> swapidx = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {4, 2}};

    que.push(initial_state);
    int level = 0;
    set<string> vis_state;

    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            string temp_state = que.front();
            que.pop();

            if (temp_state == target)
                return level;

            int idx = -1;
            for (int i = 0; i < temp_state.size(); i++)
                if (temp_state[i] == '0')
                {
                    idx = i;
                    break;
                }

            vi swapes = swapidx[idx];
            for (int i = 0; i < swapes.size(); i++)
            {
                string temp = temp_state;
                swap(temp[idx], temp[swapes[i]]);
                string new_state = temp;
                if (vis_state.find(new_state) != vis_state.end())
                    continue;

                que.push(new_state);
                vis_state.insert(new_state);
            }
        }
        level++;
    }
    return -1;
}

int main()
{
    cout << "\nhello!" << endl;

    int n, m;
    cin >> n >> m;
    vector<vi> grid;
    rvmatrix(grid, n, m);
    cout << "\n--------------------------\n";
    cout << sliding_puzzle(grid);
    cout << "\n--------------------------\n";
    pmatrix(grid, n, m);

    return 0;
}

// 2 3
// 4 1 2
// 5 0 3