// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of removeDuplicates function. The function is called on a sorted list. The function must remove all duplicates from the list in linear time and constant space
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

    void removeDuplicates()
    {
        LinkedList *res = new LinkedList();
        while (this->size > 0)
        {
            int val = this->getFirst();
            this->removeFirst();
            if (res->size == 0 || res->tail->data != val)
                res->addLast(val);
        }
        this->head = res->head;
        this->tail = res->tail;
        this->size = res->size;
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
    lst1->removeDuplicates();
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

// 10
// 2 2 2 3 3 5 5 5 5 5