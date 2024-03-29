// #include <bits/stdc++.h>
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
#include <list>
#include <locale>
#include <map>
#include <unordered_map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
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
#define test(t) while (t-- > 0)
#define vi vector<int>
#define vs vector<string>
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define vii vector<pi>
#define vvi vector<vi>
#define ll long long int
#define lld long double
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mod 1000000007
const int INF = 1e9 + 7;
const double PI = 3.141592653589793238;
const int M = 100, N = 100;

string Substr(string str, int i, int j)
{
    int len = j - i;
    if (j <= i)
        return "-1";
    return str.substr(i, len);
}

//=================================================
//! Segment Tree
//=================================================

//=================================================
//! Number Theory
//=================================================
vi sieve(int n)
{
    vi isPrime(n + 1, 1), prime;

    for (int i = 2; i * i <= isPrime.size(); i++)
        for (int j = i * i; j < isPrime.size(); j += i)
            isPrime[j] = false;

    for (int i = 2; i <= isPrime.size(); i++)
        if (isPrime[i] == true)
            prime.pb(i);

    return prime;
}

vi segSieve(int a, int b)
{
    int b_sqrt = sqrt(b);
    vi primes = sieve(b_sqrt);

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