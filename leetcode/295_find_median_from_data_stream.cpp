#include <queue>
#include <vector>

using namespace std;

struct Comparator {
  bool operator()(int a, int b) {
    return a > b; // smaller element takes priority
  }
};
class MedianFinder {
private:
  priority_queue<int, vector<int>> maxHeap;
  priority_queue<int, vector<int>, Comparator> minHeap;

public:
  MedianFinder() {}

  void addNum(int num) {
    // mistake - need to check and action on both order and size invariant
    // if (maxHeap.size() > minHeap()){
    //     minHeap.push(num);
    // } else {
    //     maxHeap.push(num);
    // }

    // fix order
    // runtime error: reference binding to null pointer of type 'const int'
    // (stl_iterator.h). fix is to check if empty first mistake - order was
    // reversed and moves the wrong way
    if (maxHeap.empty() || num <= maxHeap.top()) {
      maxHeap.push(num);
    } else {
      minHeap.push(num);
    }

    // fix size by moving root elements
    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian() {
    if ((minHeap.size() + maxHeap.size()) % 2 == 0) {
      int a = minHeap.top(); // smallest of the largest half
      int b = maxHeap.top(); // largest of the smallest half
      // mistake - did not cast as double before division
      // return (double)((a + b)/2);
      return ((double)(a + b)) / 2;
    } else if (maxHeap.size() > minHeap.size()) {
      return maxHeap.top();
    } else {
      return minHeap.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
