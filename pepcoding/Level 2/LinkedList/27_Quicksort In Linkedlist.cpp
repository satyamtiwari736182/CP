// 1. Given the head of a linked list, return the list after sorting it in increasing order.
// 2. You must apply quick sort.
// 3. Time Complexity : O(nlogn)
// 4. Space Complexity : constant space 


// 4
// 0
// 6
// 7
// 5



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

Node *getTail(Node *head)
{
    Node *curr = head, *pivot = nullptr;

    while (curr)
        pivot = curr, curr = curr->next;
    return pivot;
}

int getSize(Node *head)
{
    if (!head)
        return 0;
        
    Node *node = head;
    int cnt = 0;
    while (node->next != nullptr)
        node = node->next, cnt++;
    return cnt;
}

vector<Node *> segregate(Node *head, int pivotIdx)
{
    Node *pivot = head;
    while (pivotIdx-- > 0)
        pivot = pivot->next;

    Node *dmyl = new Node(-1), *dmyg = new Node(-1);
    Node *pl = dmyl, *pg = dmyg;
    Node *curr = head;

    while (curr)
    {
        if (curr == pivot)
            pivot = pivot;
        else if (curr->data <= pivot->data)
            pl->next = curr, pl = pl->next;
        else
            pg->next = curr, pg = pg->next;
        curr = curr->next;
    }

    pl->next = nullptr;
    pivot->next = nullptr;
    pg->next = nullptr;

    return {dmyl->next, pivot, dmyg->next};
}

void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();
    int pivotIdx;
    cin >> pivotIdx;
    // lst1 = segregate(lst1, pivotIdx);
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

12
1 5 2 9 5 14 11 1 10 10 1 3
7
*/