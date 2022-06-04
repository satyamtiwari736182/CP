#include "../header.h"

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
private:
    Node *head, *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addFirst(int val)
    {
        Node *newNode = new Node(val);
        if (size == 0)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addLast(int val)
    {
        Node *newNode = new Node(val);
        if (size == 0)
            head = tail = newNode;
        else
            tail->next = newNode, newNode->prev = tail, tail = newNode;
        size++;
    }

    void removeFirst()
    {
        if (size == 0)
            return;
        if (size == 1)
            tail = nullptr;

        Node *temp = head->next;
        temp->prev = nullptr;
        delete (head);
        head = temp;
        size--;
    }

    void removeLast()
    {
        if (size == 0)
            return;
        if (size == 1)
            head = tail = nullptr;

        Node *temp = tail->prev;
        temp->next = nullptr;
        delete (tail);
        tail = temp;
        size--;
    }

    void removeAt(int idx)
    {
        if (size == 0 || size < idx)
            return;
        Node *node = head;
        while (idx-- > 0)
            node = node->next;

        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete (node);
        size--;
    }

    Node *getAt(int idx)
    {
        if (size == 0 || size < idx)
            return new Node(INF);
        Node *node = head;
        while (idx-- > 0)
            node = node->next;
        return node;
    }

    Node *getFirst()
    {
        return tail;
    }

    Node *getlast()
    {
        return head;
    }

    int getSize()
    {
        return size;
    }

    void displayForward()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void displayBackward()
    {
        Node *temp = tail;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
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
    LinkedList *lst = new LinkedList();

    for (int vl : data)
        lst->addFirst(vl);
    lst->removeFirst();
    lst->removeLast();
    lst->displayForward();
    cout << "\n*******\n";
    lst->displayBackward();
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
10 20 30 40 50 60 70 80 90 96
*/