
// You have given a pointer to the head node of a linked list, the task is to reverse the linked list. 
// We need to reverse the list by changing the links between nodes.


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

void solve()
{
    Node *lst = makeList();

    cout << "\n***********\n";
    display(lst);
    cout << endl;
    lst = reverseList(lst);
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
7
1 2 3 4 5 6 7

*/