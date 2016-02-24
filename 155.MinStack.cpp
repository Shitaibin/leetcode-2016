// v1, easy
class MinStack {
private:
    vector<int> stack;
    vector<int> minValues;
public:
    void push(int x) {
        stack.push_back(x);
        if (minValues.size() == 0 || minValues.back() > x) {
            minValues.push_back(x);
        } else {
            minValues.push_back(minValues.back());
        }
    }

    void pop() {
        stack.pop_back();
        minValues.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return minValues.back();
    }
};

