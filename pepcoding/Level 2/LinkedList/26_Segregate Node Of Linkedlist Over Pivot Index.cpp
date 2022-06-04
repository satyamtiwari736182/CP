// 1. Given a singly linklist, Segregate Node of LinkedList over pivot index and return starting node of linkedlist.
// 2. pivot will be any random index in range of 0 to length Of Linkedlist
// 3. After segregation pivot Element should have to be present at correct position as in sorted linkedlist.

#include "../header.h"

class Node
{
public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
    Node() : data(0), next(nullptr) {}
};

Node *makeList()
{
    int n;
    cin >> n;
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new Node(val);
        prev = prev->next;
    }

    return dummy->next;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *getTail(Node *head)
{
    Node *curr = head, *pivot = nullptr;

    while (curr)
        pivot = curr, curr = curr->next;
    return pivot;
}
Node *segregate(Node *head, int pivotIdx)
{
    int idx = 1;
    Node *pivot = head;
    while (pivot != nullptr)
    {
        if (idx == pivotIdx)
            break;
        pivot = pivot->next, idx++;
    }
    // cout << pivot->data << " " << idx << endl;

    Node *dmyl = new Node(-1), *dmyg = new Node(-1), *dmy2 = new Node(-1);
    Node *pl = dmyl, *pg = dmyg, *p2 = dmy2;
    Node *curr = head;

    while (curr)
    {
        if (curr == pivot)
            pivot = pivot;
        else if (curr->data <= pivot->data)
            pl->next = curr, pl = pl->next;
        else
            pg->next = curr, pg = pg->next;
        curr = curr->next;
    }

    pl->next = pivot;
    pivot->next = dmyg->next;
    pg->next = nullptr;
    return dmyl->next;
    // return pl;
}

void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();
    int pivotIdx;
    cin >> pivotIdx;
    lst1 = segregate(lst1, pivotIdx);
    cout << "\n***********\n";

    display(lst1);
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

/*

12
1 5 2 9 5 14 11 1 10 10 1 3
7
*/