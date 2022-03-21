#include "../header.h"

int solution(string str, int k)
{
    // int cntAns = 0;
    int ans = 0;

    map<char, int> hashmap_B;
    map<char, int> hashmap_S;
    int is = -1, ib = -1, j = -1;
    int n1 = str.length();

    while (true)
    {
        bool f1 = false, f2 = false, f3 = false;

        while (ib < n1 - 1)
        {
            f1 = true;
            ib++;
            char ch = str[ib];
            hashmap_B[ch]++;

            if (hashmap_B.size() == (k + 1))
            {
                hashmap_B.erase(ch);
                break;
            }
        }

        while (is < ib)
        {
            f2 = true;
            is++;
            char ch = str[is];
            hashmap_S[ch]++;

            if (hashmap_S.size() == k)
            {
                hashmap_S.erase(ch);
                break;
            }
        }

        while (j < is)
        {
            f3 = true;

            if (hashmap_B.size() == k && hashmap_S.size() == k - 1)
                ans += ib - is;

            j++;
            char ch = str[j];

            hashmap_B[ch]--;
            hashmap_S[ch]--;

            if (hashmap_B[ch] == 0)
                hashmap_B.erase(ch);
            if (hashmap_S[ch] == 0)
                hashmap_S.erase(ch);

            if (hashmap_S.size() < k - 1 || hashmap_B.size() < k)
                break;
        }

        if (f1 == false && f2 == false && f3 == false)
            break;
    }

    return ans;
}

int main()
{

    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        string str;
        int k;
        cin >> str >> k;
        cout << "\n============================================\n";
        cout << solution(str, k) << endl;
        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// aabcbcdbca 2