// 1. Question will be provided with two Intervals Lists.
// 2. An interval is is defined as (sp,ep) i.e. sp --> starting point &  ep --> ending point of an interval
// 3. All intervals are closed in nature
// 4. Intervals[i] = [startingPointi,endingPointi]
// 5. Both interval lists are sorted in nature(sorted based upon starting time of each interval).

// Task is to "find & print all intersection of intervals from both interval lists(intervals from list 1 & list 2).".

// Example 1 :
//     list_1 : [[1,3]]
//     list_2 : [[2,5]]
//     Output : [[2,3]]
//     Explanation : interval from list 1 starts @ 1 & ends @ 3 where as interval from list 2 starts @ 2 & ends @ 5 thus intersection(time span common in intervals from both lists) is {2,3}.

// Example 2 :
//     list_1 : [[1,3]]
//     list_2 : [[4,5]]
//     Output : []
//     Explanation : there is no common time-span(i.e. no intersection)  between intervals from both given list.
// Example 3 :
//     list_1 : [[1,3] [5,10] [12,17]]
//     list_2 : [[2,4] [5,7] [9,13]]
//     Output : [[2,3] [5,7] [9,10] [12,13]]

#include "../header.h"

vvi solve(vvi &lst1, vvi &lst2)
{
    vvi res;
    sort(all(lst1)), sort(all(lst2));
    int i = 0, j = 0, n1 = lst1.size(), n2 = lst2.size();
    while (i < n1 && j < n2)
    {
        int sc = max(lst1[i][0], lst2[j][0]), ec = min(lst1[i][1], lst2[j][1]);
        if (sc <= ec)
            res.pb({sc, ec});
            
        if (lst1[i][1] < lst2[j][1])
            i++;
        else
            j++;
    }
    return res;
}

int main()
{
    cout << "hello world!\n";
    int n;
    cin >> n;
    vvi lst1(n);
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        lst1[i] = {s, e};
    }
    vvi lst2(n);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        lst2[i] = {s, e};
    }
    cout << endl;
    vvi res = solve(lst1, lst2);
    pmatrix(res, res.size(), 2);
}

// 3
// 5 10
// 1 3
// 12 17
// 3
// 9 13
// 5 7
// 2 4