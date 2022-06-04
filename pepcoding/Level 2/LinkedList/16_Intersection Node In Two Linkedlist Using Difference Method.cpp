// 1. Given the heads of two singly linked-lists headA and headB
// 2. Return the node at which the two lists intersect.
// 3. If the two linked lists have no intersection, return null.

#include "../header.h"

class Node
{
public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
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

int getSize(Node *head)
{
    Node *node = head;
    int cnt = 0;
    while (node->next != nullptr)
        node = node->next, cnt++;
    return cnt;
}

Node *intersectionNode(Node *h1, Node *h2)
{
    Node *lst1 = h1;
    Node *lst2 = h2;
    int n1 = getSize(h1);
    int n2 = getSize(h2);

    if (n2 > n1)
        swap(n1, n2), swap(lst1, lst2);

    int d = n1 - n2;
    while (d-- > 0)
        lst1 = lst1->next;

    while (lst1 != lst2)
        lst1 = lst1->next, lst2 = lst2->next;

    return lst1;
}

void solve()
{
    int idx;
    Node *lst1 = makeList();
    cin >> idx;
    Node *lst2 = makeList();
    if (idx >= 0)
    {
        Node *curr = lst1;
        while (idx-- > 0)
            curr = curr->next;
        Node *prev = lst2;
        while (prev->next != nullptr)
            prev = prev->next;
        prev->next = curr;
    }

    cout << "\n***********\n";
    cout << intersectionNode(lst1, lst2)->data << endl;
    display(lst1);
    cout << endl;
    display(lst2);
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
4
14 12 8 7
2
4
7 2 6 5

*/