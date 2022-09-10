// Implement LRU(Least Recently Used Cache), Task is to complete implementations of put(),get().
// 1. capacity : capacity of the cache will be provided as input.
// 2. put(key,value) : add the key-value pair to the Cache & override if the pair is already present in cache;
// 3. get(key) : get the value associated with the key, return "-1" incase key-value pair doesn't exists

// NOTE : Watch Question video to get better understanding of problem.
// Example  : 
//     Input : Start 3
//             put 1 10
//             put 2 20
//             put 3 30
//             get 1
//             put 1 15
//             get 1
//             get 2
//             put 4 40
//             get 3
//             get 4
//             Stop
            
            
//     Output : 10
//              15
//              20
//              -1
//              40



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


// start 3
// put 1 10
// put 2 20
// put 3 30
// put 4 40
// get 1
// stop