// 1. You are give a number of boxes (nboxes) and number of non-identical items (ritems).
// 2. You are required to place the items in those boxes and print all such configurations possible.

// Items are numbered from 1 to ritems.
// Note 1 -> Number of boxes is greater than number of items, hence some of the boxes may remain 
//                    empty.
// Note 2 -> Check out the question video and write the recursive code as it is intended without 
//                    changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

void combination(int curr_box, int total_boxes, vi &items, int selected_so_far, int req_selection, string asf)
{
    if (curr_box > total_boxes)
    {
        if (selected_so_far == req_selection)
            cout << asf << endl;
        return;
    }
    combination(curr_box + 1, total_boxes, items, selected_so_far, req_selection, asf + "_ ");

    for (int i = 0; i < req_selection; i++)
    {
        if (items[i] == 0)
        {
            items[i] = 1;
            combination(curr_box + 1, total_boxes, items, selected_so_far + 1, req_selection, asf + to_string(i + 1) + " ");
            items[i] = 0;
        }
    }
}

void solve()
{
    int box_cnt, item_cnt;
    cin >> box_cnt >> item_cnt;
    vi items(item_cnt);
    combination(1, box_cnt, items, 0, item_cnt, "");
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