// Given a string, print all suffixes of it in lexicographical order.

#include "../header.h"

class SuffixArray
{
public:
    int MAX_N = 100010;
    int n = -1; // length of input string
    string s;   // input string
    vi RA, SA, tempRA, tempSA, lcp;

    void countingSort(int k)
    {                              // O(n)
        int i, maxi = max(300, n); // up to 255 ASCII chars or length of n
        int sum = 0;
        int c[MAX_N];
        memset(c, 0, sizeof(c)); // clear frequency table

        for (i = 0; i < n; i++)
            c[i + k < n ? RA[i + k] : 0]++; // count the frequency of each integer rank

        for (i = 0; i < maxi; i++)
        {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }

        for (i = 0; i < n; i++) // shuffle the suffix array if necessary
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];

        for (i = 0; i < n; i++) // update the suffix array SA
            SA[i] = tempSA[i];
    }

    void kasai()
    {
        int k = 0;
        this->lcp.resize(n);
        int rank[n];
        memset(rank, 0, sizeof(rank));

        for (int i = 0; i < n; i++)
            rank[this->SA[i]] = i;

        for (int i = 0; i < n; i++, k = max(k - 1, 0))
        {
            if (rank[i] == n - 1)
            {
                k = 0;
                continue;
            }
            int j = this->SA[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            this->lcp[rank[i]] = k;
        }
    }

    SuffixArray(string x)
    {
        RA.resize(MAX_N); // Rank array
        SA.resize(MAX_N); // Suffix array
        tempRA.resize(MAX_N);
        tempSA.resize(MAX_N);

        this->s = x;
        // this.s += "$";
        this->n = s.length();
        for (int i = 0; i < n; i++)
            RA[i] = s[i];
        for (int i = 0; i < n; i++)
            SA[i] = i;

        for (int k = 1; k < n; k *= 2)
        {
            countingSort(k);
            countingSort(0);

            int r = 0;
            tempRA[SA[0]] = r;          // re-ranking; start from rank r = 0
            for (int i = 1; i < n; i++) // compare adjacent suffixes if same pair => same rank r; otherwise, increase r
            {
                tempRA[this->SA[i]] = (RA[this->SA[i]] == RA[this->SA[i - 1]] && RA[this->SA[i] + k] == RA[this->SA[i - 1] + k]) ? r : ++r;
            }

            for (int i = 0; i < n; i++)
            {
                RA[i] = tempRA[i]; // update the rank array RA
            }

            if (RA[this->SA[n - 1]] == n - 1)
                break; // nice optimization trick
        }
        kasai(); // use it to make lcp array in O(N) time
    }
};

void solve()
{
    string str;
    cin >> str;
    int n = str.length();
    SuffixArray *suff_arr_obj = new SuffixArray(str);

    vi suffix_array = suff_arr_obj->SA;
    vi lcp = suff_arr_obj->lcp;

    for (int i = 0; i < n; i++)
    {
        int x = suffix_array[i];
        cout << Substr(str, x, n) << endl;
    }
    parr(suffix_array, n);
    cout << endl;
    parr(lcp, n);
}

int main()
{
    cout << "hello\n";
    int t = 1;
    // cin>>t;
    test(t)
    {
        solve();
        cout << "\n----------------------\n";
    }

    return 0;
}

// bananaban