// You are given a list of N numbers and Q queries.Each query is specified by two numbers i and j.The answer to
// each query is the minimum number between the range between i and j(including i and j).The query are specified using 0 based indexing.

// Expected complexity : O(Q * logN)

#include "../header.h"

vi sqrt_arr, arr;
int block;

void sqrt_decomposition() // preprocessing
{
    sqrt_arr.resize(block);
    fill(all(sqrt_arr), INT_MAX);

    for (int i = 0; i < arr.size(); i++)
    {
        int block_idx = i / block;
        sqrt_arr[block_idx] = min(sqrt_arr[block_idx], arr[i]);
    }
}

int query(int left, int right)
{
    int ans = INT_MAX;
    while (left <= right)
    {
        if (left % block == 0 && (left + block - 1) <= right)
        {
            int block_idx = left / block;
            ans = min(ans, sqrt_arr[block_idx]);
            left += block;
        }
        else
        {
            ans = min(ans, arr[left]);
            left++;
        }
    }
    return ans;
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
        int left, right;
        cin >> left >> right;
        int ans = query(left, right);
        cout << left << " " << right << " " << ans << "  **\n";
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
    // parr(sqrt_arr, block);
    cout << block << " " << sqrt_arr.size();

    return 0;
}

// 4
// 2 4 3 1
// 4
// 1 2
// 1 3
// 2 2
// 0 1