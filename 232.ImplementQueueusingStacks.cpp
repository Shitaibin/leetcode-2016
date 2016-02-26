class Queue {
private:
    vector<int> s1, s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (s1.size()) {
            s2.push_back(s1.back());
            s1.pop_back();
        }
        s2.pop_back();
        while (s2.size()) {
            s1.push_back(s2.back());
            s2.pop_back();
        }
    }

    // Get the front element.
    int peek(void) {
        while (s1.size()) {
            s2.push_back(s1.back());
            s1.pop_back();
        }
        int e = s2.back();
        while (s2.size()) {
            s1.push_back(s2.back());
            s2.pop_back();
        }
        return e;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
}