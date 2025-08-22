#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    private:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

    public:
        MedianFinder() {
        }

        void addNum(int num) {
            if(!minHeap.empty() && minHeap.top() < num) {
                minHeap.push(num);
            } else maxHeap.push(num);

            int n = maxHeap.size();
            int m = minHeap.size();

            if(n - m > 1) {
                int top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
            } else if(m - n > 1) {
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }
        }

        double findMedian() {
            if(maxHeap.size() == minHeap.size()) {
                int n1 = maxHeap.top();
                int n2 = minHeap.top();

                return (n1 + n2) / 2.0;
            }

            if(minHeap.size() > maxHeap.size()) return minHeap.top();

            return maxHeap.top();
        }
};

int main() {
    MedianFinder md;

    md.addNum(1);
    cout << md.findMedian() << endl;
    md.addNum(2);
    cout << md.findMedian() << endl;
    md.addNum(3);
    cout << md.findMedian() << endl;

    return 0;
}
