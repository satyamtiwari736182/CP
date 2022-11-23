// #include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
// C++
#include <algorithm>
#include <bitset>
#include <complex>
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
#include <climits>
#include <list>
#include <locale>
#include <unordered_map>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <cstring>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace chrono;
// using namespace __gnu_pbds;

#define debug(x) cout << #x << " = " << x << endl;
// #define REP(a, b) for (int i = a; i < b; i++)
#define REP(i, a, b) for (i = a; i < b; i++)

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

#define rvmatrix(arr, n, m)             \
    {                                   \
        arr.resize(n);                  \
        for (int i = 0; i < n; i++)     \
            for (int j = 0; j < m; j++) \
            {                           \
                int val;                \
                cin >> val;             \
                arr[i].push_back(val);  \
            }                           \
    }

#define pmatrix(arr, n, m)            \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
            cout << arr[i][j] << " "; \
        cout << endl;                 \
    }

#define convert(tok, val)       \
    {                           \
        stringstream strm(tok); \
        strm >> val;            \
    }

#define str_to_tok(str, deli, arr, val)         \
    {                                           \
                                                \
        stringstream strtokenize(str);          \
        string tok;                             \
        while (getline(strtokenize, tok, deli)) \
        {                                       \
            stringstream strm(tok);             \
            strm >> val;                        \
            arr.pb(val);                        \
        }                                       \
    }

#define Fill(arr, val) fill(*arr, *arr + sizeof(arr) / sizeof(arr[0][0]), val);
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define test(t) while (t-- > 0)
#define vi vector<int>
#define vs vector<string>
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define vii vector<pi>
#define vvi vector<vi>
#define fs first
#define se second
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define endl '\n'
#define sz(x) ((int)(x).size())
#define set_bits __builtin_popcountll
#define PI 3.141592653589793238462

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

const int M = 100, N = 100;

//! **************************************************************************
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
// void _print(pbds v)
// {
//     cerr << "[ ";
//     for (auto i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
//! **************************************************************************

//? **************************************************************************
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (ll i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (ll j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
void precision(int a) { cout << setprecision(a) << fixed; }

//? **************************************************************************

string Substr(string str, int i, int j)
{
    int len = j - i;
    if (j <= i)
        return "\0";
    return str.substr(i, len);
}

vs split(string str, string deli)
{
    vs vec;
    char *ptr = strtok((char *)str.c_str(), deli.c_str());
    while (ptr)
        vec.pb(ptr), ptr = strtok(NULL, deli.c_str());
    return vec;
}

//=================================================
//! Segment Tree
//=================================================

//=================================================
//! Number Theory
//=================================================

vi segSieve(int a, int b)
{
    int b_sqrt = sqrt(b);
    vector<ll> primes = sieve(b_sqrt);

    vi arr(b - a, 1);

    for (int prime : primes)
    {
        int multiple = ceil(a * 1.0 / prime);
        if (multiple == 1)
            multiple++;

        int idx = multiple * prime - a;
        for (int j = idx; j < arr.size(); j += prime)
            arr[j] = false;
    }

    vi ans;

    for (int i = 0; i < arr.size(); i++)
        if (arr[i])
            ans.pb(a + i);

    return ans;
}

int *catalanNumber(int n)
{
    int *catlan = new int[n + 1];
    catlan[0] = catlan[1] = 1;
    for (int num = 2; num <= n; num++)
    {
        int sum = 0;
        for (int i = 0, j = num - 1; i < num; i++, j--)
            sum += catlan[i] * catlan[j];
        catlan[num] = sum;
    }
    return catlan;
}

//=================================================
//! Text Processing

//? Aho Corasick

//=================================================

//=================================================
//! Geometry

class Point
{
public:
    Point(lld x, lld y) : x(x), y(y) {}
    Point() = default;
    lld x = 0, y = 0;
};

Point getCoordinates()
{
    lld x, y;
    cin >> x >> y;
    Point p1(x, y);
    return p1;
}

int orentation(Point p1, Point p2, Point p3)
{
    lld slope1 = (p2.y - p1.y) * (p3.x - p2.x);
    lld slope2 = (p3.y - p2.y) * (p2.x - p1.x);
    lld diff = slope1 - slope2;

    if (diff > 0)
        return 2;
    else if (diff == 0)
        return 0;
    else
        return 1;
}

bool onSeg(Point p1, Point p2, Point p3)
{
    return (p3.x <= max(p1.x, p2.x) && p3.x >= min(p1.x, p2.x) && p3.y <= max(p1.y, p2.y) && p3.y >= min(p1.x, p2.y));
}

bool intersects(Point p1, Point p2, Point p3, Point p4)
{

    lld pos_p3_line1 = orentation(p1, p2, p3);
    lld pos_p4_line1 = orentation(p1, p2, p4);

    lld pos_p1_line2 = orentation(p3, p4, p1);
    lld pos_p2_line2 = orentation(p3, p4, p2);

    if (pos_p1_line2 != pos_p2_line2 && pos_p3_line1 != pos_p4_line1)
        return 1;
    else if (pos_p1_line2 == 0 && onSeg(p1, p2, p3))
        return 1;
    else if (pos_p2_line2 == 0 && onSeg(p1, p2, p4))
        return 1;
    else if (pos_p3_line1 == 0 && onSeg(p3, p4, p1))
        return 1;
    else if (pos_p4_line1 == 0 && onSeg(p3, p4, p2))
        return 1;

    return 0;
}

ll area(vector<Point> pts)
{
    int n = pts.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        Point A = pts[i], B = pts[(i + 1) % n];
        ans += A.x * B.y - A.y * B.x;
    }
    return abs(ans);
}

//=================================================