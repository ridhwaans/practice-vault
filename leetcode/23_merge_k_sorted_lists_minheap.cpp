/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <queue>
#include <vector>

using namespace std;

// wrong syntax
// struct Comparator()(ListNode* a, ListNode* b){
//     return a->val > b->val;
// }

struct Comparator {
  bool operator()(ListNode *a, ListNode *b) {
    // runtime error member access within misaligned address type 'ListNode'
    // UndefinedBehaviorSanitizer: undefined-behavior. fix is to stop pushing
    // null pointers to heap
    return a->val > b->val; // minheap
  }
};

class Solution {
public:
  // mistake - wrong syntax. for ListNode* use a struct comparator
  // bool comparator [](ListNode a, ListNode b){
  //     return a->val > b->val;
  // }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // takes in type, container, comparator (maxHeap less<T> comparator by
    // default)
    priority_queue<ListNode *, vector<ListNode *>, Comparator> minHeap;

    // mistake - dont need heads list
    // vector<ListNode*> heads;
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i])
        minHeap.push(lists[i]);
    }

    // mistake - new ListNode() returns ListNode* but dummy is an obj
    ListNode dummy('\0');
    // mistake - dont use extra memory, use &
    ListNode *cur = &dummy;

    // Heap keeps each list’s front node and auto-rotates by popping the
    // smallest. Pushing node->next advances that same list’s front node. dont
    // need for loop and heads list int size = heads.size(); while (1 < size){
    int j = 0;
    while (!minHeap.empty()) {

      // for (j = 0; j < size; j++){}
      // mistake - pop() returns void
      // cur->next = minHeap.pop();
      ListNode *node = minHeap.top();
      minHeap.pop();

      // move along the main linked list curNode
      cur->next = node;
      cur = cur->next;

      if (node->next)
        minHeap.push(node->next);
    }
    // didnt use -> because dummy is not a pointer
    return dummy.next;
  }
};
