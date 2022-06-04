// 1. Given a singly linklist, Segregate 012 Node of LinkedList and return pivot node of linkedlist.
// 2. After segregation zero nodes should come first and then ones node followed by two's nodes.



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

Node *segregate_012(Node *head)
{
    Node *dmy0 = new Node(-1), *dmy1 = new Node(-1), *dmy2 = new Node(-1);
    Node *p0 = dmy0, *p1 = dmy1, *p2 = dmy2;
    Node *curr = head;
    while (curr)
    {
        if (curr->data == 0)
            p0->next = curr, p0 = p0->next;
        else if (curr->data == 1)
            p1->next = curr, p1 = p1->next;
        else
            p2->next = curr, p2 = p2->next;
        curr = curr->next;
    }
    p0->next = dmy1->next;
    p1->next = dmy2->next;
    p2->next = nullptr;

    return dmy0->next;
}

void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();

    lst1 = segregate_012(lst1);
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

17
2 2 0 2 1 0 0 2 2 1 2 1 2 0 1 0 0
*/