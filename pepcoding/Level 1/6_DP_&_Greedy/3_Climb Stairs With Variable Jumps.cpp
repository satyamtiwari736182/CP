// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you
//      could jump to in a single move.
//      You can of course jump fewer number of steps in the move.
// 4. You are required to print the number of different paths via which you can climb to the top.

#include "../header.h"

// Downstair case
int getstairV_D(int n, int *arr)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    int count = 0;
    for (int i = 1; i <= arr[n]; i++)
        count += getstairV_D(n - i, arr);
    return count;
}

// Upstair case
int getstairV_U_M(int n, int *arr, int idx)
{
    if (idx > n)
        return 0;
    if (n == idx)
        return 1;
    int count = 0;
    for (int i = 1; i <= arr[idx]; i++)
        count += getstairV_U_M(n, arr, i + idx);
    return count;
}

int getstairV_U_T(int n, int *arr, int *dp)
{
    dp[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= arr[i]; j++)
            dp[i] += dp[i + j];
    }
    return dp[1];
}

// int getstairminV_U_M(int n,int *arr,int idx,int *dp)
//{
//	int mini=INT_MAX;
//	if(idx>n) {
//		dp[idx]=mini;
//		return mini;
//	}
//	if(idx==n) {
//		dp[idx]=1;
//		return 1;
//	}
//	if(dp[idx]) return dp[idx];
//	for(int i=1;i<=arr[idx];i++){
//		if((i+idx)<=n && dp[i+idx]) return dp[i+idx];
//		mini=min(mini,getstairminV_U_M(n,arr,i+idx,dp));
//	}
//	dp[idx]=mini+1;
//	return dp[idx];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << "hello!" << endl;
    int path = 0, n;
    cin >> n;
    int arr2[100] = {0}; // n+1

    for (int i = 1; i <= n; i++)
        cin >> arr2[i];

    cout << getstairV_U_M(n, arr2, 1) << endl;

    return 0;
}

/*
10
3 2 4 2 0 2 3 1 2 2
*/

// 10
// 3
// 3
// 0
// 2
// 1
// 2
// 4
// 2
// 0
// 0