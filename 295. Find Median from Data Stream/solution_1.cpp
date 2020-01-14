class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> left;   //大根堆，用来存储较小的一半
    priority_queue<int, vector<int>, greater<int>> right;   //小根堆，用来存储较大的一半
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
        if (left.size() - right.size() >= 2) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        else
            return static_cast<double>(left.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */