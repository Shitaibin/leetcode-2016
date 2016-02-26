class Stack {
private:
    queue<int> nums;
public:
    // Push element x onto stack.
    void push(int x) {
        nums.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int len = nums.size();
        while (--len > 0) {
            nums.push(nums.front());
            nums.pop();
        }
        nums.pop();
    }

    // Get the top element.
    int top() {
        return nums.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return nums.empty();
    }
};