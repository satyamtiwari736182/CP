// You are given an array of k linked-lists, each linked-list is sorted in increasing order.
// Merge all the linkedlists into one sorted linkedlist and return it.

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

Node *mergeSortedList(Node *lst1, Node *lst2)
{
    Node *dmy = new Node(-1);
    Node *head = dmy;
    while (lst1 && lst2)
    {
        if (lst1->data <= lst2->data)
            head->next = lst1, lst1 = lst1->next, head = head->next;
        else
            head->next = lst2, lst2 = lst2->next, head = head->next;
    }
    if (lst1)
        head->next = lst1;
    if (lst2)
        head->next = lst2;
    return dmy->next;
}

Node *mergeKLists(vector<Node *> &lsts, int left, int right)
{
    if (left > right)
        return nullptr;

    if (left == right)
        return lsts[left];
    int mid = (left + right) / 2;

    Node *head1 = mergeKLists(lsts, left, mid);
    Node *head2 = mergeKLists(lsts, mid + 1, right);

    return mergeSortedList(head1, head2);
}

void solve()
{
    Node *lst1 = makeList();
    Node *lst2 = makeList();
    Node *lst3 = makeList();
    Node *lst4 = makeList();

    cout << "\n***********\n";
    vector<Node *> lsts({lst1, lst2, lst3, lst4});
    Node *lst = mergeKLists(lsts, 0, 3);
    display(lst);
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

5
10 20 30 40 50
12
7 9 10 12 15 20 37 43 44 48 52 56
5
4 5 6 11 13
6
30 39 42 45 46 80

*/
