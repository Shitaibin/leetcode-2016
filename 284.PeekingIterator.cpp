// 分析例子，我们可以得到以下的结果。
// 迭代器刚it开始在1处
// next: 得到1，it移动到2
// peek: 得到2，it不移动
// next: 得到2，it移动到3
// next: 得到3，it移动到NULL
// hasNext: 否
// 这就是PeekingIterator要实现的效果，要通过Iterator的接口实现。
// hasNext其实比较特殊，它实际上是检查的当前位置是否有效。
// peek的实现需要next，而Iterator::next会移动一个位置，所以peek要设计
// 标记和暂存结果。


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
	    bool hasPeek;
	    int peekedValue;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    hasPeek = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!hasPeek) {
            hasPeek = true;
            result = Iterator::next();
        }
        return result;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (!hasPeek) {
	        // move
	        return Iterator::next();
	    }
	    // reset flag, but without move
        hasPeek = false;
        return result;
	}

	bool hasNext() const {
	    return hasPeeked || Iterator::hasNext();
	}
};