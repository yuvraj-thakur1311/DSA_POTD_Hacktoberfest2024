#include <bits/stdc++.h>

using namespace std;

class CustomStack
{
public:
    int n;
    stack<int> stk;
    vector<int> inc;

    CustomStack(int n)
    {
        this->n = n;
    }

    void push(int x)
    {
        if (stk.size() < n) {
            stk.push(x);
            inc.push_back(0);
        }
    }

    int pop()
    {
        if (stk.empty()) return -1;
        if (inc.size() > 1) inc[inc.size() - 2] += inc.back();
        int res = stk.top() + inc.back();
        stk.pop();
        inc.pop_back();
        return res;
    }

    void increment(int k, int val)
    {
        if (!stk.empty()) {
            int idx = min(k, (int)inc.size()) - 1;
            inc[idx] += val;
        }
    }
};

int main()
{
    CustomStack customStack(3); // Stack with max size of 3

    customStack.push(1);        // Stack: [1]
    customStack.push(2);        // Stack: [1, 2]
    customStack.push(3);        // Stack: [1, 2, 3]

    cout << customStack.pop() << endl;   // Output: 3, Stack: [1, 2]

    customStack.increment(2, 100);  // Increment first 2 elements by 100, Stack: [101, 102]

    customStack.push(4);        // Stack: [101, 102, 4]

    cout << customStack.pop() << endl;   // Output: 4, Stack: [101, 102]

    cout << customStack.pop() << endl;   // Output: 102, Stack: [101]

    cout << customStack.pop() << endl;   // Output: 101, Stack: []

    cout << customStack.pop() << endl;   // Output: -1, Stack is empty

    return 0;
}
