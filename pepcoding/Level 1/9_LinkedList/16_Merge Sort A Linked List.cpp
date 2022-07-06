// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of mergeSort function. The function is static and is passed the head and tail of an unsorted list. The function is expected to return a new sorted list. The original list must not change.
// 3. Input and Output is managed for you.

#include "../header.h"

class Node
{
public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head, *tail;
    int size;

    void addLast(int val)
    {
        Node *newNode = new Node(val);
        if (size == 0)
            head = tail = newNode;
        else
            tail->next = newNode, tail = newNode;
        size++;
    }

    void add(int val)
    {
        addLast(val);
    }

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    //?==============================================
    //*==============================================
};

LinkedList *merge(LinkedList *lst1, LinkedList *lst2)
{
    Node *one = lst1->head;
    Node *two = lst2->head;
    LinkedList *res = new LinkedList();

    while (one && two)
    {
        if (one->data < two->data)
            res->addLast(one->data), one = one->next;
        else
            res->addLast(two->data), two = two->next;
    }
    while (one)
        res->addLast(one->data), one = one->next;

    while (two)
        res->addLast(two->data), two = two->next;

    return res;
}

Node *mid(Node *left, Node *right)
{
    Node *slow = left, *fast = left;
    while (fast != right && fast->next != right)
        slow = slow->next, fast = fast->next->next;
    return slow;
}

LinkedList *mergeSort(Node *left, Node *right)
{
    if (left == right)
    {
        LinkedList *lst = new LinkedList();
        lst->add(left->data);
        return lst;
    }
    Node *md = mid(left, right);
    LinkedList *lftSort = mergeSort(left, md);
    LinkedList *rhtSort = mergeSort(md->next, right);
    return merge(lftSort, rhtSort);
}

void solve()
{
    string inputData;
    fflush(stdin);
    getline(cin, inputData);

    int val = 0;
    vi data;
    str_to_tok(inputData, ' ', data, val);
    LinkedList *lst1 = new LinkedList();
    for (int vl : data)
        lst1->add(vl);
    lst1 = mergeSort(lst1->head, lst1->tail);
    lst1->display();
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

// 6
// 10 2 19 22 3 7