// 1. You are given an array(arr) of integers.
// 2. You have to find the count of arithmetic slices in the given array.
// 3. Arithmetic slice is defined as the sub-sequence of an array having all its elements in A.P and length of sub-sequence should be greater than or equal to 3.

#include "../header.h"

int solution(vi &arr)
{
    int ans = 0;

    // map<int, int> hashmap(N);
    unordered_map<int, int> hashmap[N];
    for (int i = 1; i < arr.size(); i++)
        for (int j = 0; j < i; j++)
        {
            int cdiff = arr[i] - arr[j];
            if (cdiff <= INT_MIN || cdiff >= INT_MAX)
                continue;
            int apsEndingOn_j = hashmap[j][cdiff];
            int apsEndingOn_i = hashmap[i][cdiff];

            ans += apsEndingOn_j;
            hashmap[i][cdiff] = apsEndingOn_i + apsEndingOn_j + 1;
        }
    return ans;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "\n------------\n";
    cout << solution(arr) << endl;

    //------------------------------------------------------

    return 0;
}

/*
4
1 2 3 4
*/
