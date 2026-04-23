#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode *leftP = head;
  struct ListNode *rightP = head;

  // without dummy node method
  // go n steps to check if head is to be removed
  for (int gap = 0; gap < n; gap++) {
    if (gap >= n)
      leftP = leftP->next;
    rightP = rightP->next;
  }

  if (rightP == NULL) {
    struct ListNode *newHead = leftP->next;
    free(head);
    head = NULL;
    return newHead;
  }

  // go remaining steps. while rightP->next, not just rightP otherwise leftP
  // goes 1 step too far
  while (rightP->next) {
    leftP = leftP->next;
    rightP = rightP->next;
  }

  // confirmed that if wrapper is unnecessary because leftP->next should never
  // be null
  if (leftP->next) {
    struct ListNode *next = leftP->next->next;

    struct ListNode *nodeToRemove = leftP->next;
    free(nodeToRemove);
    nodeToRemove = NULL;

    leftP->next = next;
  }

  return head;
}
