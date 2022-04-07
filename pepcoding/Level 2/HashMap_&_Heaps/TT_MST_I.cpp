// 1.	https://www.hackerrank.com/challenges/arrays-ds/problem

#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>

vector<int> reverseArray(vector<int> a)
{
    int i = 0, j = a.size() - 1;
    while (i < j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr = reverseArray(arr);
    for (int val : arr)
        cout << val << " ";
    return 0;
}
// 2.	https://www.hackerrank.com/challenges/equal-stacks/problem

#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
int main()
{
    int n1, n2, n3;
    while (~scanf("%d%d%d", &n1, &n2, &n3))
    {
        vector<int> a(n1);
        for (int i = 0; i < n1; ++i)
            scanf("%d", &a[i]);
        vector<int> b(n2);
        for (int i = 0; i < n2; ++i)
            scanf("%d", &b[i]);
        vector<int> c(n3);
        for (int i = 0; i < n3; ++i)
            scanf("%d", &c[i]);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        map<int, int> t;
        for (int k = 0; k < 3; k++)
        {
            const vi &v = k == 0 ? a : k == 1 ? b
                                              : c;
            int sum = 0;
            for (int x : v)
            {
                sum += x;
                ++t[sum];
            }
        }
        int ans = 0;
        for (auto p : t)
            if (p.second == 3)
                ans = max(ans, p.first);
        printf("%d\n", ans);
    }
    return 0;
}
