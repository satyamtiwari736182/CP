// 1. You are give a number of boxes (nboxes) and number of non-identical items (ritems).
// 2. You are required to place the items in those boxes and print all such configurations possible.

// Items are numbered from 1 to ritems.
// Note 1 -> Number of boxes is greater than number of items, hence some of the boxes may remain empty.
// Note 2 -> Check out the question video and write the recursive code as it is intended without changing signature. The judge can't
//                    force you but intends you to teach a concept.

#include "../header.h"

void permutation(vi &boxes, int item_i, int total_item)
// Decisions for item(which are different) getting the correct boxes
{
    if (item_i > total_item)
    {
        parr(boxes, boxes.size());
        cout << endl;
        return;
    }

    for (int i = 0; i < boxes.size(); i++) // placing the item in different boxes and checking.
    {
        if (boxes[i] == 0)
        {
            boxes[i] = item_i;
            permutation(boxes, item_i + 1, total_item);
            boxes[i] = 0;
        }
    }
}

void solve()
{
    int box_cnt, item_cnt;
    cin >> box_cnt >> item_cnt;
    vi boxes(box_cnt);
    permutation(boxes, 1, item_cnt);
}
int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

// 5 3