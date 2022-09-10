// Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

// Implement the FreqStack class:

// FreqStack() constructs an empty frequency stack.
// void push(int val) pushes an integer val onto the top of the stack.
// int pop() removes and returns the most frequent element in the stack.
// If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

#include "../header.h"

unordered_map<int, stack<int>> freqStack;
unordered_map<int, int> fmap;
int maxFreq = 0;
void push(int val)
{
    int freq = ++fmap[val];
    freqStack[freq].push(val);
    maxFreq = max(maxFreq, freq);
}

int pop()
{
    int toDelete = freqStack[maxFreq].top();
    freqStack[maxFreq--].pop();
    if (freqStack[maxFreq].empty())
        maxFreq--;
    return toDelete;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {

        cout << "\n============================================\n";

        cout << "\n============================================\n";
    }

    return 0;
}