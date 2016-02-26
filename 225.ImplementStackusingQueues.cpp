class Stack {
private:
    queue<int> Queue;
public:
    // Push element x onto stack.
    void push(int x) {
        Queue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int n = Queue.size();
        while (--n > 0) {
            Queue.push(Queue.front());
            Queue.pop();
        }
        Queue.pop();
    }

    // Get the top element.
    int top() {
        return Queue.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return Queue.empty();
    }
};