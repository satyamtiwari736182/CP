// Design a stack which supports the following operations.

// Implement the CustomStack class:

//     1: void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
//     2: int pop() Pops and returns the top of stack or -1 if the stack is empty.
//     3: void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack.

#include "../header.h"

class CustomStack
{
public:
    int *value, *increment, index, size;

    CustomStack(int maxSize)
    {
        value = new int[maxSize], size = maxSize;
        increment = new int[maxSize];
        index = -1;
    }

    void push(int x)
    {
        if (index + 1 == size)
            return;
        index++;
        value[index] = x;
        increment[index] = 0;
    }

    int pop()
    {
        if (index == -1)
            return -1;
        int x = value[index];
        int inc = increment[index];
        index--;
        if (index >= 0)
            increment[index] += inc;
        return x + inc;
    }

    void Increment(int k, int val)
    {
        int idx = min(k - 1, index);
        if (index >= 0)
            increment[idx] += val;
    }
};

void solve()
{
    int n;
    cin >> n;

    CustomStack stk(n);
    string str = "start";
    cin >> str;
    while (str != "exit")
    {
        if (str == "push")
        {
            int val;
            cin >> val;
            stk.push(val);
        }
        else if (str == "pop")
            cout << stk.pop() << " popped\n";
        else
        {
            int idx, inc;
            cin >> idx >> inc;
            stk.Increment(idx, inc);
        }
        cin >> str;
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

3
push 1
push 2
pop
push 2
push 3
push 4
increment 5 100
increment 2 100
pop
pop
pop
pop
exit

*/