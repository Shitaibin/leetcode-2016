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

// v2, custom stack, save memory
// from: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/minStack/minStack.cpp
template <typename T>
class Stack{
private:
    T* _stack;
    int _capacity;
    int _top;
public:
    Stack():_capacity(1), _top(-1) {
        _stack = (T*)malloc(_capacity*sizeof(T));
    }
    
    ~Stack() {
        free(_stack);
    }
    
    void push(T x) {
        _top++;
        if ( _top >= _capacity ) {
            _capacity *= 5;
            _stack = (T*)realloc(_stack, _capacity*sizeof(T));
        }
        _stack[_top] = x;
    }
    
    T pop() {
        if (_top >= 0) {
            return _stack[_top--];
        }
    }
    
    // reference 方便后续访问
    T& top() {
        if(_top >= 0) {
            return _stack[_top];
        }
        static T null;
        return null;
    }
    
    bool empty() {
        return _top == -1;
    }
    
    int size() {
        return _top+1;
    }
    
    void clear() {
        _top = -1;
    }
};

class MinStack {
private:
    struct minData {
        int min;
        int cnt;
        minData(): min(0), cnt(0){} //necessary
        minData(int m, int n): min(m), cnt(n){}
    };
    Stack<int> stack;
    Stack<minData> minStack;
    int min;
    
public:
    void push(int x) {
        stack.push(x);
        if (minStack.empty()) {
            minStack.push(minData(x, 1));
            min = x;
        } else {
            // 记录当前x作为min出现的次数，很巧妙
            if (min >= x) {
                min = x;
                if (minStack.top().min == x) {
                    minStack.top().cnt++;
                } else {
                    minStack.push(minData(x, 1));
                }
            }
        }
    }

    void pop() {
        if (stack.empty()){
            return ;
        }
        int x = stack.pop();
        if (x == minStack.top().min) {
            if (minStack.top().cnt > 1) {
                minStack.top().cnt--;
            } else {
                minStack.pop();
                min = minStack.top().min;
            }
        }
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return min;
    }
    
    void clear() {
        stack.clear();
        minStack.clear();
    }
};