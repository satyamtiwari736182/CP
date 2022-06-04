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

int getSize(Node *head)
{
    Node *node = head;
    int cnt = 0;
    while (node->next != nullptr)
        node = node->next, cnt++;
    return cnt;
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
bool isPlaindrome(Node *head)
{
    Node *mid = midNode(head);
    Node *nHead = mid->next;
    nHead = reverseList(nHead);
    Node *c1 = head;
    Node *c2 = nHead;
    int res = true;

    while (c2 != nullptr)
    {
        if (c1->data != c2->data)
        {
            res = false;
            break;
        }
        c1 = c1->next,c2 = c2->next;
    }

    nHead = reverseList(nHead);
    mid->next = nHead;

    return res;
}
void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();

    cout << isPlaindrome(lst1);
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