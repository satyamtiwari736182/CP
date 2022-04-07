// Given t test cases and in each test case you have a positive integer n, we have to find the total number of divisors for n.


#include "../header.h"

void sieve(vi &arr)
{
    for (int i = 0; i < arr.size(); i++)
        arr[i] = i;

    for (int i = 2; i * i < arr.size(); i++)
        if (arr[i] == i)
        {
            for (int j = i * i; j < arr.size(); j += i)
                if (arr[j] == j)
                    arr[j] = i;
        }
}
vi getPrimeFactors(vi &arr, int n)
{
    set<int> hashset;
    while (n > 1)
    {
        hashset.insert(arr[n]);
        n /= arr[n];
    }
    vi ans;
    for (int prime : hashset)
        ans.pb(prime);

    return ans;
}
int countFactor(vi &primeFactor, int n)
{
    int count = 1;
    for (int prime : primeFactor)
    {
        int cnt = 1;
        while (n % prime == 0)
        {
            cnt++;
            n /= prime;
        }
        count *= cnt;
    }
    return count;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    vi arr;
    arr.resize(int(1e5 + 1));
    sieve(arr);
    cin >> t;
    test(t)
    {
        int n;

        cout << "\n===========================================\n";
        cin >> n;
        vi ans = getPrimeFactors(arr, n);

        int count_factor = countFactor(ans, n);
        cout << count_factor;
        cout << "\n===========================================\n";
    }

    return 0;
}

// 10
// 21
// 22
// 23
// 24
// 25
// 26
// 27
// 28
// 29
// 30