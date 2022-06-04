// 1. Given a singly linklist, Segregate Node of LinkedList over lastindex and return pivot node of linkedlist.
// 2. pivot is always be last index of linkedlist.
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

Node *segregate_last(Node *head)
{
    Node *dmyl = new Node(-1), *dmyg = new Node(-1), *dmy2 = new Node(-1);
    Node *pl = dmyl, *pg = dmyg, *p2 = dmy2;
    Node *curr = head;
    Node *pivot = getTail(head);

    while (curr)
    {
        if (curr->data <= pivot->data)
            pl->next = curr, pl = pl->next;
        else
            pg->next = curr, pg = pg->next;
        curr = curr->next;
    }

    pg->next = nullptr;
    pl->next = dmyg->next;
    // return dmyl->next;
    return pl;
}

void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();

    lst1 = segregate_last(lst1);
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
*/