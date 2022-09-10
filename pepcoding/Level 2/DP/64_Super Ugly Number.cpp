// 1. You are given an array(arr) of size k which contains prime numbers in ascending order, and an integer N.
// 2. You have to find Nth super ugly number.
// 3. Super ugly number is defined as the number whose prime factors are elements of the given array.

// Assumption -> 1 is the first super ugly number.


#include "../header.h"

int solution(vi &primes, int n)
{
    int *ptrs = new int[primes.size()];
    fill(ptrs, ptrs + primes.size() + 1, 1);

    int *dp = new int[n + 1];
    fill(dp, dp + n + 1, 0);

    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int minVal = INT_MAX;

        for (int j = 0; j < primes.size(); j++)
            minVal = min(minVal, primes[j] * dp[ptrs[j]]);

        dp[i] = minVal;

        for (int j = 0; j < primes.size(); j++)
            if (primes[j] * dp[ptrs[j]] == minVal)
                ptrs[j]++;
    }

    return dp[n];
}

int solution2(vi &primes, int n)
{
    int *dp = new int[n + 1];
    fill(dp, dp + n + 1, 0);

    dp[1] = 1;

    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pque; //{value,pointer,prime}
    for (int i = 0; i < primes.size(); i++)
        pque.push({primes[i], {i, primes[i]}});

    for (int i = 2; i <= n; i++)
    {
        auto temp = pque.top();
        pque.pop();

        if (dp[i - 1] != temp.fs)
            dp[i] = temp.fs, i++;

        pque.push({temp.se.se * dp[temp.se.fs + 1], {temp.se.fs + 1, temp.se.se}});
    }

    return dp[n];
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> n;

    cout << "\n------------\n";
    cout << solution(arr, n) << endl;
    // cout << solution2(arr, n) << endl;
    //------------------------------------------------------

    return 0;
}

/*
4
3 5 7 11
13
*/
