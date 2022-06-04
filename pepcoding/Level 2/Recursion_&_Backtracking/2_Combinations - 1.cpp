// 1. You are give a number of boxes (nboxes) and number of identical items (ritems).
// 2. You are required to place the items in those boxes and print all such configurations possible.

// Items are identical and all of them are named 'i'.
// Note 1 -> Number of boxes is greater than number of items, hence some of the boxes may remain
//                    empty.
// Note 2 -> Check out the question video and write the recursive code as it is intended without
//                    changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

void combination(int curr_box, int total_boxes, int selected_so_far, int req_selection, string asf)
//Decisions for box getting a item(which are similar)
{
    if (curr_box > total_boxes)
    {
        if (selected_so_far == req_selection)
            cout << asf << endl;
        return;
    }
    combination(curr_box + 1, total_boxes, selected_so_far + 1, req_selection, asf + "i "); // box accepting an item
    combination(curr_box + 1, total_boxes, selected_so_far, req_selection, asf + "_ ");     // box not accepting an item
}

void solve()
{
    int box_cnt, item_cnt;
    cin >> box_cnt >> item_cnt;
    combination(1, box_cnt, 0, item_cnt, "");
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