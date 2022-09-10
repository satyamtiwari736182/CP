// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include "../header.h"

int totalLength = 0;
int rec(int n, int left, int right, vi &cuts)
{
    if (left >= right)
        return 0;

    int ans = (int)1e8;
    for (int cutPoint = left; cutPoint < right; cutPoint++)
    {
        int leftEnd = left == 0 ? 0 : cuts[left - 1];
        int rightEnd = right == cuts.size() ? totalLength : cuts[right];

        int cost = rightEnd - leftEnd;

        int leftPart = rec(leftEnd, left, cutPoint, cuts);
        int rightPart = rec(rightEnd, cutPoint + 1, right, cuts);

        int myAns = leftPart + cost + rightPart;

        ans = min(ans, myAns);
    }
    return ans;
}

int minCost(int n, vi &cuts)
{
    sort(all(cuts));
    totalLength = n;
    return rec(n, 0, cuts.size(), cuts);
}

int main()
{
    cout << "\nHello world!\n";
    int lenth, n;
    cin >> lenth >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "\n------------\n";
    //------------------------------------------------------
    cout << minCost(lenth, arr) << endl;

    return 0;
}

/*
7
4
1 3 4 5
*/
