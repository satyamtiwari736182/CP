// 1. Given a singly linklist. determine if the linked list has a cycle in it.
// 2. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.


#include "../header.h"

class Node
{
public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

bool cyclePresentInLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

Node *takeInput()
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

    int idx;
    cin >> idx;

    if (idx >= 0)
    {
        Node *curr = dummy->next;
        while (idx-- > 0)
            curr = curr->next;
        prev->next = curr;
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

void solve()
{
    Node *lst = takeInput();
    cout << "\n***********\n";
    // display(lst);
    cout << cyclePresentInLL(lst);
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
8
10 18 20 8 -1 38 31 84
3


//********
10 18 20 8 -1 38 31 84
8 -1 38 31 84
8 -1 38 31 84
8 -1 38 31 84

*/