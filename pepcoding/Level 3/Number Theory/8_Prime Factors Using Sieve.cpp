// you have T numbers and for each number N you want to print all of it's prime factors.

// Expected complexity : 0(logn) for each query. You can do linear time preprocessing.

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

        for (int primes : ans)
            cout << primes << " ";
        cout << "\n===========================================\n";
    }

    return 0;
}

// 6
// 10
// 15
// 23
// 93
// 39
// 6426