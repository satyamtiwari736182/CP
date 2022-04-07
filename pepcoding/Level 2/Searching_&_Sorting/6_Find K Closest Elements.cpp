// 1. Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
// 2. An integer a is closer to x than an integer b if:
//         |a - x| < |b - x|, or
//         |a - x| == |b - x| and a < b

#include "../header.h"

struct comparator
{
    bool operator()(pi pr1, pi pr2)
    {
        return pr1.se < pr2.se;
    }
};

vi solve_I(vi &arr, int k, int val)
// using priority queue.
{
    vi ans;
    priority_queue<pi, vector<pi>, comparator> pq;
    for (int ele : arr)
    {
        int gap = abs(val - ele);

        if (pq.size() < k)
            pq.push({ele, gap});

        else if (pq.top().se > gap)
        {
            pq.pop();
            pq.push({ele, gap});
        }
        else if (pq.top().se == gap)
        {
            if (pq.top().fs > ele)
            {
                pq.pop();
                pq.push({ele, gap});
            }
        }
    }

    while (!pq.empty())
    {
        ans.pb(pq.top().fs);
        pq.pop();
    }

    sort(all(ans));
    return ans;
}
//------------------------------------------
vi solve_II(vi &arr, int k, int val)
// using Binary Search
{
    vi ans;

    int mid = 0, low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (val == arr[mid])
            break;
        else if (val > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    int left = mid - 1, right = mid;
    while (left >= 0 && right < arr.size() && k-- > 0)
    {
        int gap1 = abs(val - arr[left]);
        int gap2 = abs(val - arr[right]);

        if (gap1 < gap2)
            ans.pb(arr[left--]);
        else if (gap2 < gap1)
            ans.pb(arr[right++]);
        else if (gap1 == gap2)
        {
            if (arr[left] < arr[right])
                ans.pb(arr[left--]);
            else
                ans.pb(arr[right++]);
        }
    }

    while (left-- >= 0 && k-- > 0)
        ans.pb(arr[left]);
    while (right++ < arr.size() && k-- > 0)
        ans.pb(arr[right]);

    sort(all(ans));

    return ans;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, val;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> k >> val;
        cout << "\n============================================\n";

        vi ans = solve_I(arr, k, val);
        for (int itm : ans)
            cout << itm << " ";
        cout << "\n============================================\n";
    }
    return 0;
}

// 1

// 6
// 10 20 30 40 50 60
// 3
// 45