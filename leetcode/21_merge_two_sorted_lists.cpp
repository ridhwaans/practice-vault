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
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *list1Cur = list1;
    ListNode *list2Cur = list2;
    ListNode dummy(0);
    ListNode *mergedCur = &dummy;
    ListNode *mergedHead = dummy.next;

    while (list1Cur && list2Cur) {
      // flawed logic - doesnt need to be in a loop
      // if (!list1Cur){
      //     while (list2Cur){
      //         mergedCur = mergedCur->next;
      //         mergedCur->next = list2Cur;
      //         list2Cur = list2Cur->next;
      //     }
      // }
      // if (!list2Cur){
      //     while (list1Cur){
      //         mergedCur = mergedCur->next;
      //         mergedCur->next = list1Cur;
      //         list1Cur = list1Cur->next;
      //     }
      // }
      if (list1Cur->val >= list2Cur->val) {
        // need a dummy node initially
        mergedCur->next = list2Cur;
        list2Cur = list2Cur->next;
      } else {
        mergedCur->next = list1Cur;
        list1Cur = list1Cur->next;
      }
      // flawed logic
      // if (!mergedHead) {
      //     mergedHead = mergedCur;
      // }
      mergedCur = mergedCur->next;
    }

    if (list1Cur)
      mergedCur->next = list1Cur;
    if (list2Cur)
      mergedCur->next = list2Cur;

    // mergedHead doesnt change but dummy.next changes once to the real head
    return dummy.next;
  }
};
