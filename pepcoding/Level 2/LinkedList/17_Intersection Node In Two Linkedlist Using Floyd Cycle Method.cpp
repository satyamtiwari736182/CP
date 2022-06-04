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

Node *cycleNode(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return new Node(INF);
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow == fast)
        slow = head, fast = fast;
    else
        return new Node(INF);

    while (slow != fast)
        slow = slow->next, fast = fast->next;

    return slow;
}

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

Node *intersectionNode(Node *h1, Node *h2)
{
    Node *curr = h1;
    while (curr->next != nullptr)
        curr = curr->next;

    Node *prev = curr;
    curr->next = h2;

    Node *node = cycleNode(h1);
    prev->next = nullptr;

    return node;
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