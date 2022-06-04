// 1. You are give a number of boxes (nboxes) and number of identical items (ritems).
// 2. You are required to place the items in those boxes and print all such configurations possible.

// Items are identical and all of them are named 'i'
// Note 1 -> Number of boxes is greater than number of items, hence some of the boxes may remain 
//                    empty.
// Note 2 -> Check out the question video and write the recursive code as it is intended without 
//                    changing signature. The judge can't force you but intends you to teach a concept.


#include "../header.h"
void permutation(vi &boxes, int item_i, int total_item, int last_occ_box)
{
    if (item_i > total_item)
    {
        for (int i = 0; i < boxes.size(); i++)
        {
            if (boxes[i] == true)
                cout << "i ";
            else
                cout << "_ ";
        }
        cout << endl;
        return;
    }

    for (int i = last_occ_box + 1; i < boxes.size(); i++)
    {
        if (boxes[i] == false)
        {
            boxes[i] = true;
            permutation(boxes, item_i + 1, total_item, i);
            boxes[i] = false;
        }
    }
}

void solve()
{
    int box_cnt, item_cnt;
    cin >> box_cnt >> item_cnt;
    vi boxes(box_cnt);
    permutation(boxes, 1, item_cnt, -1);
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