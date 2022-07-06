
#include "../header.h"

class MedianPriorityQueue
{
private:
    priority_queue<int> left;                             // max-heap
    priority_queue<int, vector<int>, greater<int>> right; // min-heap

public:
    void add(int val)
    {
        if (right.size() > 0 && val > right.top())
            right.push(val);
        else
            left.push(val);

        // balancing
        if (left.size() - right.size() == 2)
            right.push(left.top()), left.pop();
        else if (right.size() - left.size() == 2)
            left.push(right.top()), right.pop();
    }

    int remove()
    {
        if (getSize() == 0)
        {
            cout << "Underflow";
            return -1;
        }
        else if (left.size() >= right.size())
        {
            int val = left.top();
            left.pop();
            return val;
        }
        else
        {
            int val = right.top();
            right.pop();
            return val;
        }
    }

    int peek()
    {
        if (getSize() == 0)
        {
            cout << "Underflow";
            return -1;
        }
        else if (left.size() >= right.size())
            return left.top();
        else
            return right.top();
    }

    int getSize()
    {
        return left.size() + right.size();
    }
};

void solve()
{
    MedianPriorityQueue *med_pq = new MedianPriorityQueue();
    bool flag = true;
    while (flag)
    {
        string str;
        cin >> str;

        if (str == "add")
        {
            int val;
            cin >> val;
            med_pq->add(val);
        }
        else if (str == "peek")
            cout << med_pq->peek() << endl;
        else if (str == "remove")
            cout << med_pq->remove() << endl;

        else if (str == "quit")
            flag = false;
        else if (str == "size")
            cout << med_pq->getSize();
        else
            cout << "Invalid command\n";
    }
}

int main()
{
    cout << "hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
// 10 10 10 20 20 30 30 40 40 50

add 10
add 20
add 30
add 40
peek
add 50
peek
remove
peek
remove
peek
remove
peek
remove
peek
quit

*/