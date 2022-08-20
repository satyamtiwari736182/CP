// Design your implementation of the circular double-ended queue (deque).

// Your implementation should support following operations:

// 1. MyCircularDeque(): Initializes the deque object.
// 2. insertFront(): Adds an item at the front of Deque.
// 3. insertLast(): Adds an item at the rear of Deque.
// 4. deleteFront(): Deletes the front item from the Deque and return it's value. If the deque is empty, return null.
// 5. deleteLast(): Deletes the last item from Deque and return it's value. If the deque is empty, return null.
// 6. getFront(): Gets the front item from the Deque. If the deque is empty, return null.
// 7. getRear(): Gets the last item from Deque. If the deque is empty, return null.
// 8. isEmpty(): Checks whether Deque is empty or not.

#include "../header.h"

template <class T>
class DeQueue
{
public:
    class Node
    {
        T data;
        Node *next = nullptr, *prev = nullptr;
        // Node() : data(null) = default;
        Node(T val) : data(val) {}
    };

private:
    Node *front, *rear, *tail;
    int size = 0;

public:
    DeQueue()
    {
        front = rear = nullptr;
        front->next = tail;
        tail->prev = front;
    }

    void insertFront(T val)
    {
        Node *node = new Node(val);
        node->next = rear;
        node->prev = rear->prev;
        // node->prev = node->next;
        rear->prev = node;
        size++;
    }

    void insertLast(T val) {}

    void deleteLast() {}

    void deleteFront() {}
};

void solve()
{
    int n;
    cin >> n;

    string str = "start";
    cin >> str;
    while (str != "exit")
    {
    }
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

insertLast 1
insertLast 2
insertFront 3
insertFront 4
getRear
deleteLast
getRear
deleteLast
insertFront 4
getFront

*/