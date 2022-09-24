
// You have been given three Integers a, b and k. you need to find an integral solution of x and y such that a*x + b*y= k * gcd(a,b).

// It can be proven that solution always exist.

#include "../header.h"

class Pair
{
public:
    Pair(ll xx, ll yx, ll gcdx) : x(xx), y(yx), gcd(gcdx) {}
    ll x, y, gcd;
};

Pair euclide(int a, int b)
{
    if (b == 0)
        return Pair(1, 0, a);
    Pair dash = euclide(b, a % b);
    return Pair(dash.y, dash.x - (a / b) * dash.y, dash.gcd);
}

int main()
{
    cout << "\nHello world!" << endl;
    int a, b, k, t = 1;
    // cin >> t;
    test(t)
    {
        cin >> a >> b >> k;
        Pair ans = euclide(a, b);
        cout << ans.x << " " << ans.y << " " << ans.gcd << endl;
        ans.x *= k;
        ans.y *= k;
        cout << ans.x << "\t" << ans.y << endl;
    }

    return 0;
}

// 1
// 3 5 8

/*
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

int sumOfFactor(vi &primeFactor, int n)
{
    int sumOfFactors = 1;
    if (primeFactor.size() == 0)
        return sumOfFactors;
    for (int prime : primeFactor)
    {
        int cnt = 1;
        while (n % prime == 0)
        {
            cnt++;
            n /= prime;
        }
        sumOfFactors *= (pow(prime, cnt) - 1);
        sumOfFactors /= (prime - 1);
    }
    return sumOfFactors;
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

        int count_factor = sumOfFactor(ans, n);
        cout << count_factor;
        cout << "\n===========================================\n";
    }

    return 0;
}

// 3

// 100000 100000
// 12 24
// 747794 238336

*/