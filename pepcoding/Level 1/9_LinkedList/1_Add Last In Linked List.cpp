// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of addLast function. This function is supposed to add an element to the end of LinkedList. You are required to update head, tail and size as required.
// 3. Input and Output is managed for you. Just update the code in addLast function.
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
private:
    Node *head, *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    int size()
    {
        return size;
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

    void addLast(int val)
    {
        Node *newNode = new Node(val);
        if (size == 0)
            head = tail = newNode;
        else
            tail->next = newNode, tail = newNode;
        size++;
    }

    void addAt(int idx, int val)
    {
        if (idx < 0 || idx > size)
            cout << "Invalid arguments\n";
        else if (idx == 0)
            addFirst(val);
        else if (idx == size)
            addLast(val);
        else
        {
            Node *node = new Node(val);
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
                temp = temp->next;
            node->next = temp->next;
            temp->next = node;
            size++;
        }
    }

    int getFirst()
    {
        if (size == 0)
            return -1;
        else
            return head->data;
    }

    int getLast()
    {
        if (size == 0)
            return -1;
        else
            return tail->data;
    }

    int getAt(int idx)
    {
        if (size == 0)
            return -1;
        else if (idx < 0 || idx >= size)
            return -1;
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx; i++)
                temp = temp->next;
            return temp->data;
        }
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

    void removeLast()
    {
        if (size == 0)
            cout << "List is empty\n";
        else if (size == 1)
            head = tail = nullptr, size = 0;
        else
        {
            Node *temp = head;
            for (int i = 0; i < size - 2; i++)
                temp = temp->next;
            tail = temp;
            tail->next = nullptr;
            size--;
        }
    }

    void removeAt(int idx)
    {
        if (idx < 0 || idx >= size)
            cout << "Invalid arguments\n";
        else if (idx == 0)
            removeFirst();
        else if (idx == size - 1)
            removeLast();
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
                temp = temp->next;
            temp->next = temp->next->next;
            size--;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
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
    lst->removeFirst();
    lst->display();
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
// addLast 10
// addLast 20
// addLast 30
// addLast 40
// addLast 50
// quit