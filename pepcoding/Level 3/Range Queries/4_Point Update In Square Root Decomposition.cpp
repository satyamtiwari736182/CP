// You are given a list of N numbers and Q queries. There are two types of queries:

// 1. f l r : In a line, the first character would be f, and 2 index l and r, you have to find the sum of numbers between l and r.
// 2. u i d : In a line, the first character would be u, and we have to change the value at index i in the original array by d.

#include "../header.h"

vi sqrt_arr, arr;
int block;

void sqrt_decomposition() // preprocessing
{
    sqrt_arr.resize(block);
    fill(all(sqrt_arr), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        int block_idx = i / block;
        sqrt_arr[block_idx] += arr[i];
    }
}

int query(int left, int right)
{
    int ans = 0;
    while (left <= right)
    {
        if (left % block == 0 && (left + block - 1) <= right)
        {
            int block_idx = left / block;
            ans += sqrt_arr[block_idx];
            left += block;
        }
        else
        {
            ans += arr[left];
            left++;
        }
    }
    return ans;
}

void update(int idx, int change)
{
    int block_idx = idx / block;
    sqrt_arr[block_idx] += change;
    arr[idx] += change;
}

void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    rarr(arr, 0, n);

    block = ceil(sqrt(n));
    // preprocessing
    sqrt_decomposition();
    //------Query-----
    int q;
    cin >> q;
    test(q)
    {
        char type;
        cin >> type;
        if (type == 'f')
        {
            int left, right;
            cin >> left >> right;
            int ans = query(left, right);
            cout << ans << "  **\n";
        }
        else if (type == 'u')
        {
            int idx, change;
            cin >> idx >> change;
            update(idx, change);
        }
    }
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }
    // cout << block << " " << sqrt_arr.size();

    return 0;
}

// 5
// 1 5 3 9 -2
// 3
// f 0 4
// u 2 3
// f 0 4