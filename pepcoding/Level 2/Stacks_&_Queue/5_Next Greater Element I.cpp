// 1: You are given two integer arrays query and nums containing unique elements.
// 2: Here query is a subset of nums that means all elements of query are also present in nums.
// 3: Find all the next greater numbers for query's elements in the corresponding places of nums. If it does not exist -1 is answer for this number.
// 4: You are required to complete the body of the function nextGreaterI(int nums[], int query[]) which returns the answer array containing next greater element's.


#include "../header.h"

void solve()
{
    string str;
    int val;
    getline(cin, str);
    vi arr, qry;
    str_to_tok(str,' ', qry, val);
    getline(cin, str);
    str_to_tok(str,' ', arr, val);

    int n = arr.size(), flag = -1;
    stack<int> stk;
    map<int, int> nge;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[i] >= stk.top())
            stk.pop();

        if (stk.empty())
            nge[arr[i]] = flag;
        else
            nge[arr[i]] = stk.top();

        stk.push(arr[i]);
    }

    for (int qr : qry)
        cout << nge[qr] << " ";
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

4 1 2
1 3 4 2

*/