// Given a singly linkedlist : l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... -> ln-1 -> ln
// reorder it : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 -> .....

// for more information watch video.

// Given a singly linked list of Integers, determine it is a palindrome or not.

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

Node *reverseList(Node *h1)
{
    Node *curr = h1, *prev = nullptr;
    while (curr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node *midNode(Node *lst1)
{
    Node *slow = lst1, *fast = lst1;
    while (fast->next != nullptr && fast->next->next != nullptr)
        slow = slow->next, fast = fast->next->next;
    return slow;
}

void foldList(Node *head)
{
    Node *mid = midNode(head);
    Node *nHead = mid->next;
    mid->next = nullptr;
    nHead = reverseList(nHead);
    Node *c1 = head, *f1 = nullptr;
    Node *c2 = nHead, *f2 = nullptr;

    while (c2 != nullptr)
    {
        f1 = c1->next, f2 = c2->next;

        c1->next = c2;
        c2->next = f1;

        c1 = f1, c2 = f2;
    }
}
void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();

    foldList(lst1);
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

10
5 1 4 6 9 9 6 4 1 5

//****
5
5 6 7 8 5

*/