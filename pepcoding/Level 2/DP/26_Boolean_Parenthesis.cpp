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
int main()
{
    int n;
    string str1, str2;
    cin >> str1 >> str2;
    n = str1.length();

    int truedp[n][n], falsedp[n][n];
    fill(*truedp, *truedp + n * n, 0);
    fill(*falsedp, *falsedp + n * n, 0);

    //-----------------------------------------------------
    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                if (str1[i] == 'T')
                {
                    truedp[i][j] = 1;
                    falsedp[i][j] = 0;
                }
                else
                {
                    truedp[i][j] = 0;
                    falsedp[i][j] = 1;
                }
            }
            else
                for (int k = 0; k < j; k++)
                {
                    char optr = str2[k];

                    int ltc = truedp[i][k];
                    int rtc = truedp[k + 1][j];

                    int lfc = falsedp[i][k];
                    int rfc = falsedp[k + 1][j];

                    if (optr == '&')
                    {
                        truedp[i][j] += ltc * rtc;
                        falsedp[i][j] += lfc * rtc + ltc * rfc + lfc * rfc;
                    }

                    else if (optr == '|')
                    {
                        truedp[i][j] += ltc * rtc + lfc * rtc + ltc * rfc;
                        falsedp[i][j] += lfc * rfc;
                    }
                    
                    else
                    { // ^
                        truedp[i][j] += ltc * rfc + lfc * rtc;
                        falsedp[i][j] += ltc * rtc + lfc * rfc;
                    }
                }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(truedp, n, n);
    cout << "\n***************************\n";
    pmatrix(falsedp, n, n);
    return 0;
}

// TFTF
// &|^
