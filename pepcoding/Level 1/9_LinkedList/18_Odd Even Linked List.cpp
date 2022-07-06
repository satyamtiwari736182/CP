
// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of oddEven function. The function is expected to tweak the list such that all odd values are followed by all even values. The relative order of elements should not change. Also, take care of the cases when there are no odd or no even elements. Make sure to properly set head, tail and size as the function will be tested by calling addFirst and addLast.
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

    void seperateEvenOddValues()
    {
        LinkedList *odd = new LinkedList();
        LinkedList *even = new LinkedList();
        while (this->size > 0)
        {
            int val = this->getFirst();
            this->removeFirst();
            if (val % 2 == 0)
                even->addLast(val);
            else
                odd->addLast(val);
        }
        odd->tail->next = even->head;
        this->head = odd->head;
        this->tail = even->tail;
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
    lst1->seperateEvenOddValues();
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

// 7
// 2 8 9 1 5 4 3
// 10
// 100