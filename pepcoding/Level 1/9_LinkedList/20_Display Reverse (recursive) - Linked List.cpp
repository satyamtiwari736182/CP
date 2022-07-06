// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of displayReverse and displayReverseHelper functions. The function are expected to print in reverse the linked list without actually reversing it.
// 3. Input and Output is managed for you.

// Note -> The online judge can't force you to write recursive function. But that is what the expectation is, the intention in to help you learn.

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

    int getFirst()
    {
        if (size == 0)
            return -1;
        else
            return head->data;
    }

    void removeFirst()
    {
        if (size == 0)
            return;
        if (size == 1)
            tail = nullptr;

        Node *temp = head->next;
        delete (head);
        head = temp;
        size--;
    }
    void addFirst(int val)
    {
        Node *newNode = new Node(val);
        if (size == 0)
            head = tail = newNode;
        else
            newNode->next = head, head = newNode;
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

    void displayR(Node *root)
    {
        if (root)
        {
            displayR(root->next);
            cout << root->data << " ";
        }
    }
};

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
    lst1->display();
    cout << endl;
    lst1->displayR(lst1->head);
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

// 11
// 1 2 3 4 5 6 7 8 9 10 11
// 100
// 200