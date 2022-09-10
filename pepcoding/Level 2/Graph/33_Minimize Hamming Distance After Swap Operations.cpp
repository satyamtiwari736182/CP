// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/

#include "../header.h"

int parent[N];
int ranks[N];

int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

bool Union(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);

    if (px != py)
    {
        if (ranks[px] > ranks[py])
            parent[py] = px;
        else if (ranks[px] < ranks[py])
            parent[px] = py;
        else
            parent[px] = py, ranks[py]++;

        return true;
    }
    return false;
}

int minimumHammingDistance(vi &source, vi &target, vvi &allowedSwap)
{
    int n = source.size();
    for (int i = 0; i < n; i++)
        parent[i] = i, ranks[i] = 1;
    for (auto swaps : allowedSwap)
    {
        int a = swaps[0], b = swaps[1];
        int la = findParent(a), lb = findParent(b);
        if (la != lb)
            Union(a, b);
    }

    unordered_map<int, unordered_map<int, int>> hashmap; // leader=>(val=>cnt)
    for (int i = 0; i < n; i++)
    {
        int src = source[i];
        int leader = findParent(i);
        hashmap[leader][src]++;
    }

    int hamming_dist = 0;
    for (int i = 0; i < n; i++)
    {
        int leader = findParent(i);
        int tar = target[i];
        if (hashmap[leader][tar] <= 0)
            hamming_dist++;
        else
            hashmap[leader][tar]--;
    }

    return hamming_dist;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vi src(n), tar(n);
    vvi allowedSwaps(n, vi(2));
    rarr(src, 0, n);
    rarr(tar, 0, n);
    cin >> n;
    rmatrix(allowedSwaps, n, 2);
    cout << "\n==========================================\n";
    cout << minimumHammingDistance(src, tar, allowedSwaps);
    cout << "\n==========================================\n";
    return 0;
}

/*

4
1 2 3 4
2 1 4 5
2
0 1
2 3

*/