// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of mergeTwoSortedLists function. The function is static and is passed two lists which are sorted. The function is expected to return a new sorted list containing elements of both lists. Original lists must stay as they were.
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

    data.clear();

    fflush(stdin);
    getline(cin, inputData);
    str_to_tok(inputData, ' ', data, val);
    LinkedList *lst2 = new LinkedList();
    for (int vl : data)
        lst2->add(vl);

    lst1->display();
    cout << endl;
    lst2->display();
    cout << endl;

    //*================
    LinkedList *res = merge(lst1, lst2);
    res->display();
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

// 5
// 10 20 30 40 50
// 10
// 7 9 12 15 37 43 44 48 52 56