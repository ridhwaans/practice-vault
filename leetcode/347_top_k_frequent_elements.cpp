#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Comparator {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    // mistake - return a.second > b.second meant minHeap :S
    return a.second < b.second;
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // mistake - wrong syntax
    // priority_queue<int> maxHeap(int, vector<int>);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> maxHeap;
    unordered_map<int, int> freq;

    for (int &n : nums) {
      freq[n] += 1;
    }

    for (auto [k, v] : freq) {
      maxHeap.push(make_pair(k, v));
    }
    vector<int> kFrequent;
    for (int i = 0; i < k; i++) {
      pair<int, int> p = maxHeap.top();
      kFrequent.push_back(p.first);
      maxHeap.pop();
    }
    return kFrequent;
  }
};
