// 1. Merge two sorted linkedlists and return head of a sorted linkedlist. The list should be made by splicing together the nodes of the first two lists
// 2. Both list are sorted in increasing order.

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

void solve()
{
    Node *lst1 = makeList();
    Node *lst2 = makeList();

    cout << "\n***********\n";
    Node *lst = mergeSortedList(lst1, lst2);
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
10
7 9 10 12 15 20 37 43 44 48 52 56

*/