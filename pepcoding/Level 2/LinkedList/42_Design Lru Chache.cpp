
// 1. Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// 2. Discards the least recently used items first. This algorithm requires keeping track of what
//    was used when, which is expensive if one wants to make sure the algorithm always discards
//    the least recently used item. General implementations of this technique require keeping
//    "age bits" for cache-lines and track the "Least Recently Used" cache-line based on age-bits.
//    In such an implementation, every time a cache-line is used, the age of all other cache-lines changes

// 3. mplement the LRUCache class:
//       3.1 LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//       3.2 int get(int key) Return the value of the key if the key exists, otherwise return -1.
//       3.3 void put(int key, int value) Update the value of the key if the key exists. Otherwise,
//           add the key-value pair to the cache. If the number of keys exceeds the capacity from this
//           operation, evict the least recently used key.

// 4. Could you do get and put in O(1) time complexity?

#include "../header.h"
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

private:
    class Node
    {
    public:
        int key, data;
        Node *next, *prev;
        Node(int key, int data) : key(key), data(data), next(nullptr), prev(nullptr) {}
    };

    Node *head = nullptr, *tail = nullptr;
    int cap;
    map<int, Node *> cache;

    void addNode(Node *node) // addFirst
    {
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void removeNode(Node *node)
    {
        Node *nextNbr = node->next;
        Node *prevNbr = node->prev;

        prevNbr->next = nextNbr;
        nextNbr->prev = prevNbr;

        node->prev = nullptr;
        node->next = nullptr;
    }

    void moveToFirst(Node *node)
    {
        removeNode(node);
        addNode(node);
    }

public:
    int get(int key)
    {
        Node *node = cache.count(key) == 0 ? nullptr : cache[key];
        if (node == nullptr)
            return -1;
        int val = node->data;
        moveToFirst(node);

        return val;
    }

    void put(int key, int value)
    {
        Node *node = cache.count(key) == 0 ? nullptr : cache[key];
        if (node == nullptr)
        {
            node = new Node(key, value);
            cache[key] = node;
            addNode(node);
            if (cache.size() > cap)
            {
                Node *LRU_node = tail->prev;
                Node *temp = LRU_node->prev;
                cache.erase(LRU_node->key);
                removeNode(LRU_node);
                temp->next = tail;
                tail->prev = temp;
            }
        }
        else
            node->data = value, moveToFirst(node);
    }

    void displayCache()
    {
        Node *temp = head->next;
        while (temp != tail)
        {
            cout << "[ " << temp->key << " " << temp->data << " ], ";
            temp = temp->next;
        }
    }
};

void solve()
{
    string command;
    LRUCache *obj = nullptr;
    while (getline(cin, command))
    {
        fflush(stdin);
        fflush(stdout);
        vs arr;
        string str;
        str_to_tok(command, ' ', arr, str);

        if (arr[0] == "Start")
        {
            int cap;
            convert(arr[1], cap);
            obj = new LRUCache(cap);
        }

        else if (arr[0] == "get")
        {
            int key, val;
            convert(arr[1], key);
            // cout << "\t" << key << endl;

            cout << "\t" << obj->get(key) << endl;
        }

        else if (arr[0] == "put")
        {
            int key, val;
            convert(arr[1], key);
            convert(arr[2], val);
            // cout << "\t" << key << " " << val << endl;

            obj->put(key, val);
        }

        else if (arr[0] == "Stop")
            break;

        cout << "\n****  ";
        obj->displayCache();
        cout << "  ****\n";
    }
}

/*
class Node
{
public:
    int key, data;
    Node *next, *prev;
    Node(int key, int data) : key(key), data(data), next(nullptr), prev(nullptr) {}
};*/

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // map<int, Node *> hashmap;
    // cout << (hashmap[1] == 0) << endl;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*

Start 3
put 1 10
put 2 20
put 3 30
get 1
put 1 15
get 1
get 2
put 4 40
get 3
get 4
Stop

*/