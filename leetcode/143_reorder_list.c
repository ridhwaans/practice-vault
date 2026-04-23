/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode *head) {
  struct ListNode *fast = head;
  struct ListNode *slow = head;

  while (fast) {
    if (!fast->next)
      break;
    if (!fast->next->next)
      break;
    fast = fast->next->next;
    slow = slow->next;
  }

  // end of p1
  struct ListNode *p2Cur = slow->next;
  // moved line below to avoid cutting the list before saving the second half
  // error
  slow->next = NULL;

  // // reverse p2
  // // time limit exceeded flawed logic did a local pair swap, not a full
  // linked-list reversal while (p2Cur && p2Cur->next) {
  //     struct ListNode* p2Next =  p2Cur->next; // temp
  //     struct ListNode* nextPair = p2Next->next; // temp
  //     p2Cur->next = nextPair;
  //     p2Next->next = p2Cur;

  //     p2Cur = p2Next;
  // }

  // reverse p2
  struct ListNode *p2Prev = NULL;
  while (p2Cur) {
    struct ListNode *p2Next = p2Cur->next;

    p2Cur->next = p2Prev;
    p2Prev = p2Cur;
    p2Cur = p2Next;
  }

  struct ListNode *p1Cur = head;
  // p2Cur = slow->next; dont need to set to what is now NULL
  p2Cur = p2Prev;

  while (p1Cur && p2Cur) {
    struct ListNode *p1Next = p1Cur->next; // temp
    struct ListNode *p2Next = p2Cur->next; // temp
    p1Cur->next = p2Cur;
    p2Cur->next = p1Next;
    // move cur forward to original next that was saved
    p1Cur = p1Next;
    p2Cur = p2Next;
  }
}
