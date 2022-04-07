// Given two integer numbers, your task is to find count of all common divisors of given numbers


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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
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
        int a, b, n;

        cout << "\n===========================================\n";
        cin >> a >> b;
        n = __gcd(a, b);
        vi ans = getPrimeFactors(arr, n);

        int count_factor = countFactor(ans, n);
        cout << count_factor;
        cout << "\n===========================================\n";
    }

    return 0;
}

// 3

// 100000 100000
// 12 24
// 747794 238336