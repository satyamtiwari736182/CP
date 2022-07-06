// 1. You are required to complete the code of our MedianPriorityQueue class. The class should mimic the behaviour of a PriorityQueue and give highest priority to median of it's data.
// 2. Here is the list of functions that you are supposed to complete
// 2.1. add -> Should accept new data.
// 2.2. remove -> Should remove and return median value, if available or print "Underflow" otherwise and return -1
// 2.3. peek -> Should return median value, if available or print "Underflow" otherwise and return -1
// 2.4. size -> Should return the number of elements available
// 3. Input and Output is managed for you.

// Note -> If there are even number of elements in the MedianPriorityQueue, consider the smaller median as median value.



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