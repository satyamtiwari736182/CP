// 1. You are given N number of books. Every ith book has Ai number of pages.
// 2. You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value.
// 3. Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
// 4. Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.

#include "../header.h"
bool check(vi &arr, int pages, int m)
{
    int cnt_student = 1, cnt_pages = 0;
    for (int val : arr)
    {
        cnt_pages += val;
        if (cnt_pages > pages)
        {
            cnt_pages = val;
            cnt_student++;
        }
    }

    return cnt_student <= m;
}

int solve(vi &arr, int m)
{
    int low = 0, high = 0, pages = 0;
    for (int i : arr)
    {
        low = max(low, i);
        high += i;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(arr, mid, m) == 1)
        {
            pages = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return pages;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> m;

        cout << "\n============================================\n";

        cout << solve(arr, m);

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 4
// 12 30 48 10
// 2

// 4
// 20 10 30 40
// 2