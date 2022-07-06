// 1. You are required to complete the code of our LLToQueueAdapter class.
// 2. As data members, you've a linkedlist available in the class.
// 3. Here is the list of functions that you are supposed to complete
//      3.1. add -> Should accept new data in FIFO manner
//      3.2. remove -> Should remove and return data in FIFO manner. If not available,
//      print "Queue underflow" and return -1.
//      3.3. peek -> Should return data in FIFO manner. If not available, print "Queue
//      underflow" and return -1.
//      3.4. size -> Should return the number of elements available in the queue
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

    void addLast(int val)
    {
        Node *newNode = new Node(val);
        if (size == 0)
            head = tail = newNode;
        else
            tail->next = newNode, tail = newNode;
        size++;
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
    int getFirst()
    {
        if (size == 0)
            return -1;
        else
            return head->data;
    }

public:
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
    int getSize()
    {
        return size;
    }

    void add(int val)
    {
        addLast(val);
    }

    int remove()
    {
        int val = getFirst();
        removeFirst();
        return val;
    }

    int peek()
    {
        return getFirst();
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
        lst->add(vl);
    cout << lst->remove() << endl;
    cout << lst->remove() << endl;
    cout << lst->peek() << endl;

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

// add 10
// add 20
// add 30
// add 40
// add 50
// add 60
// peek
// remove
// peek
// remove
// peek
// remove
// peek
// remove
// peek
// remove
// peek
// remove
// quit