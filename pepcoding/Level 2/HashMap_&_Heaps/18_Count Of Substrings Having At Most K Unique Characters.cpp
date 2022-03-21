#include "../header.h"

int solution(string str, int k)
{
    map<char, int> hashmap;
    int ans = 0;
    int n = str.size();
    int i = -1, j = -1;
    while (true)
    {
        bool f1 = false, f2 = false;

        while (i < n - 1)
        {
            f1 = true;
            i++;
            char ch = str[i];
            hashmap[ch]++;
            
            if (hashmap.size() > k)
                break;
            ans += i - j;
        }

        while (j < i)
        {
            f2 = true;
            j++;
            char ch = str[j];
            hashmap[ch]--;
            if (hashmap[ch] == 0)
                hashmap.erase(ch);

            if (hashmap.size() == k)
            {
                ans += i - j;
                break;
            }
        }

        if (f1 == false && f2 == false)
            break;
    }
    return ans;
}
int main()
{

    cout << "\nHello world!" << endl;

    int n, t, k;

    cin >> t;
    test(t)
    {
        string str;
        cin >> str;
        cin >> k;
        cout << "\n============================================\n";
        cout << "\n"
             << solution(str, k) << endl;
        cout << "\n============================================\n";
    }

    return 0;
}

// 1
// aabcbcdbca
// 2
