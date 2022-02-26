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
struct Node
{
    Node(int x, int y) : m_x(x), m_y(y) {}
    int m_x, m_y;
};
bool comparator(int a, int b)
{
    return a < b;
}
bool compareNodeX(Node a, Node b)
{
    return a.m_x > b.m_x;
}
bool compareNodeY(Node a, Node b)
{
    return a.m_y < b.m_y;
}
int main()
{
    int arr[] = {5, 6, 4, 3, 8, 7, 1, 3};
    vector<Node> nodes = {
        Node(5, 4),
        Node(3, 2),
        Node(15, 14),
        Node(8, 3),
        Node(7, 9),
        Node(6, 4),
        Node(0, 1),
    };

    int n = sizeof(arr) / sizeof(*arr);
    sort(arr, arr + n, comparator);
    parr(arr, n);

    cout << endl;
    sort(all(nodes), compareNodeX);
    for (auto i : nodes)
    {
        cout << i.m_x << " " << i.m_y << ",  ";
    }
    cout << endl;
    sort(all(nodes), compareNodeY);
    for (auto i : nodes)
    {
        cout << i.m_x << " " << i.m_y << ",  ";
    }
    cout << endl;

    cout << "\nhello!" << endl;
    return 0;
}
