// 1. You are given an array of n integers.
// 2. You have to divide these n integers into 2 subsets such that the difference of sum of two subsets
//      is as minimum as possible.
// 3. If n is even, both set will contain exactly n/2 elements. If  is odd, one set will contain (n-1)/2 and
//     other set will contain (n+1)/2 elements.
// 3. If it is not possible to divide, then print "-1".

// Note -> Check out the question video and write the recursive code as it is intended without
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

string arrToStr(vi &arr)
{
    string str = "";
    for (int val : arr)
        str = str + to_string(val) + " ";
    return str;
}

int minDiff = INT_MAX;
string ans = "";
void solution(vi &arr, int vidx, vi &set1, vi &set2, int soset1, int soset2)
{
    if (vidx == arr.size())
    {
        int delta = abs(soset1 - soset2);
        if (delta < minDiff)
            minDiff = delta, ans = arrToStr(set1) + "| " + arrToStr(set2);
        return;
    }

    if (set1.size() < (arr.size() + 1) / 2)
    {
        set1.pb(arr[vidx]);
        solution(arr, vidx + 1, set1, set2, soset1 + arr[vidx], soset2);
        set1.pop_back();
    }

    if (set2.size() < (arr.size() + 1) / 2)
    {
        set2.pb(arr[vidx]);
        solution(arr, vidx + 1, set1, set2, soset1, soset2 + arr[vidx]);
        set2.pop_back();
    }
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n), set1, set2;
    rarr(arr, 0, n);
    solution(arr, 0, set1, set2, 0, 0);
    cout << ans << endl;
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

/*
6
1 2 3 4 5 6
*/
