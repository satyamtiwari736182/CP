// 1. You are give a single sorted linkedlist of numbers. 
// 2. remove all duplicate nodes such that duplicate numbers appear once and Return the remaning linked list.



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

void removeDuplicates(Node *head)
{
    Node *prev = head, *curr = head->next;
    while (curr)
    {
        if (prev->data != curr->data)
            prev->next = curr, prev = prev->next;
        curr = curr->next;
    }
    prev->next = nullptr;
}

void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();

    removeDuplicates(lst1);
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
5 5 1 1 4 4 6 6 9 9
//******
12
1 1 1 4 5 6 6 7 8 9 9 9

*/