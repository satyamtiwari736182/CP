// 1. You are given a partially written LinkedList class.
// 2. Here is a list of existing functions:
//     2.1 addLast - adds a new element with given value to the end of Linked List
//     2.2. display - Prints the elements of linked list from front to end in a single line.
//     All elements are separated by space
//     2.3. size - Returns the number of elements in the linked list.
//     2.4. removeFirst - Removes the first element from Linked List.
//     2.5. getFirst - Returns the data of first element.
//     2.6. getLast - Returns the data of last element.
//     2.7. getAt - Returns the data of element available at the index passed.
//     2.8. addFirst - adds a new element with given value in front of linked list.
//     2.9. addAt - adds a new element at a given index.
//     2.10. removeLast - removes the last element of linked list.
//     2.11. removeAt - remove an element at a given index
// 3. You are required to complete the body of reversePI function. The function should be an iterative function and should reverse the contents of linked list by changing the "next" property of nodes.
// 4. Input and Output is managed for you.

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

    void addFirst(int val)
    {
        Node *newNode = new Node(val);
        if (size == 0)
            head = tail = newNode;
        else
            newNode->next = head, head = newNode;
        size++;
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

    //?==============================================
    //*==============================================
    void reverse()
    {
        Node *prev = nullptr, *curr = head;
        while (curr)
        {
            Node *Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        Node *temp = head;
        head = tail;
        tail = head;
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
    lst->reverse();
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

// addFirst 10
// addFirst 20
// addLast 30
// addLast 40
// addLast 50
// addFirst 60
// removeAt 2
// display
// reversePI
// display
// quit