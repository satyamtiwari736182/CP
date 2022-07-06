// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of kReverse function. The function is expected to tweak the list such that all groups of k elements in the list get reversed and linked. If the last set has less than k elements, leave it as it is (don't reverse).
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

    void kGrpReverse(int k)
    {
        LinkedList *prev = new LinkedList();
        while (this->size > 0)
        {
            int kk = k;
            LinkedList *curr = new LinkedList();
            if (this->size >= k)
            {
                while (kk-- > 0)
                {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr->addFirst(val);
                }

                if (prev->size == 0)
                    prev = curr, prev->size += curr->size;

                else
                {
                    prev->tail->next = curr->head;
                    prev->tail = curr->tail;
                    prev->size += curr->size;
                }
            }

            else
            {
                prev->tail->next = this->head;
                prev->size += this->size;
                this->size = 0;
            }
        }
        this->head = prev->head;
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
    lst1->kGrpReverse(3);
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

// 11
// 1 2 3 4 5 6 7 8 9 10 11
// 3
// 100
// 200