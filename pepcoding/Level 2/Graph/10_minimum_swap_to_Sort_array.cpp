// Given an array of n distinct elements, find the minimum number of swaps required to sort the array.

#include "../header.h"

class Pair
{
public:
    int val, idx;
    Pair(int val, int idx) : val(val), idx(idx) {}
};

bool comparable(Pair first, Pair second)
{
    return first.val < second.val;
}

int min_swap(vi &arr)
{
    int n = arr.size();
    vector<Pair> vec;
    for (int i = 0; i < n; i++)
        vec.push_back(Pair(arr[i], i));

    sort(all(vec), comparable);

    int swap_count = 0;

    bool visited[n] = {0};

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true || vec[i].idx == i)
            continue;

        int cycle_len = 0;
        int j = i;

        while (visited[j] == false)
        {
            visited[j] = true;
            cycle_len++;
            j = vec[j].idx;
        }

        swap_count += cycle_len - 1;
    }

    return swap_count;
}

int main()
{
    cout << "\nhello!" << endl;

    int n;
    cin >> n;
    vi arr;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.pb(val);
    }
    cout << "\n--------------------------\n";
    cout << min_swap(arr);
    cout << "\n--------------------------\n";
    parr(arr, n);
    return 0;
}

/*
8
6 4 2 14 8 10 12 16
*/