// given a singly linked list with head node head, return a middle node of linked list.
// if there is 2 mid node then return first mid node.

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

Node *midNode(Node *lst1)
{
    Node *slow = lst1, *fast = lst1;
    while (fast->next != nullptr && fast->next->next != nullptr)
        slow = slow->next, fast = fast->next->next;
    return slow;
}

void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();

    cout << midNode(lst1)->data;
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

6
6 1 3 2 4 0

//****
5
5 6 7 8 3

*/

// 7
// 1 2 3 4 5 6 7