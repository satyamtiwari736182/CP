// 1. You are give two single linkedlist of digits.
// 2. The most significant digit comes first and each of their nodes contain a single digit. Subtract the two numbers and return it as a linked list.
// 3. You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 4. any list can be larger in term of number.

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
        cout << temp->data;
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

Node *subtractList(Node *h1, Node *h2)
{
    Node *lst11 = reverseList(h1);
    Node *lst22 = reverseList(h2);
    Node *lst3 = new Node(INF);
    Node *dummy = lst3;
    Node *lst1 = lst11, *lst2 = lst22;
    int borrow = 0;

    while (borrow != 0 || lst1 != nullptr || lst2 != nullptr)
    {

        int val1 = 0, val2 = 0;
        if (lst1 != nullptr)
            val1 = lst1->data;
        if (lst2 != nullptr)
            val2 = lst2->data;

        int val = val1 - val2 + borrow;

        if (val < 0)
            val += 10, borrow = -1;
        else
            borrow = 0;

        lst3->next = new Node(val);
        lst3 = lst3->next;

        if (lst1 != nullptr)
            lst1 = lst1->next;
        if (lst2 != nullptr)
            lst2 = lst2->next;
    }
    lst1 = reverseList(lst11);
    lst2 = reverseList(lst22);
    h1 = lst1;
    h2 = lst2;
    return reverseList(dummy->next);
}

void solve()
{
    Node *lst1 = makeList();
    Node *lst2 = makeList();

    cout << "\n***********\n";

    display(lst1);
    cout << " - ";
    display(lst2);
    cout << " = ";
    Node *lst3 = subtractList(lst1, lst2);
    display(lst3);
    cout << "\n***********\n";
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
6
6 1 3 2 4 0
5
5 6 7 8 3

*/