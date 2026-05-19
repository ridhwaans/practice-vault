/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

;
struct ListNode *mainHead = NULL;
struct ListNode *mainCurr = NULL;

void appendNode(struct ListNode *node) {
  if (mainHead == NULL) {
    mainHead = node;
    mainCurr = node;
  } else {
    mainCurr->next = node;
    mainCurr = node;
  }
}

void mergeTwoLists(struct ListNode *listA, struct ListNode *listB) {
  while (listA && listB) {
    // mainList(ListNode*) was an uninitialized pointer
    // mainList->val = listA->val;
    struct ListNode *nextNode =
        (struct ListNode *)malloc(sizeof(struct ListNode));

    if (listA->val <= listB->val) {
      nextNode->val = listA->val;
      listA = listA->next;
    } else {
      nextNode->val = listB->val;
      listB = listB->next;
    }

    nextNode->next = NULL;
    appendNode(nextNode);
  }

  while (listA) {
    struct ListNode *nextNode =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    // did not do nextNode = listA because it points to the same node in memory
    // as listA, its not creating anything, are aliases of the same object
    // explicitly copy values into a new node that is independent
    nextNode->val = listA->val;
    nextNode->next = NULL;

    appendNode(nextNode);
    listA = listA->next;
  }
  while (listB) {
    struct ListNode *nextNode =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    nextNode->val = listB->val;
    nextNode->next = NULL;

    appendNode(nextNode);
    listB = listB->next;
  }
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  if (listsSize == 0)
    return NULL; // [] in C
  if (listsSize == 1)
    return lists[0];

  /*
  taking one list at a time and repeatedly merging with a running main list
causes time limit exceeded. New solution is modifying the original lists and
changing pointers one pair at a time, not sequentially Before: lists = [l0, l1,
l2, l3, l4]

After one round:
lists = [merge(l0,l1), merge(l2,l3), l4, ...]
*/
  while (listsSize > 1) {
    int j = 0;
    for (int i = 1; i < listsSize; i += 2) {
      mainHead = NULL;
      mainCurr = NULL;

      struct ListNode *listA = lists[i - 1];
      struct ListNode *listB = lists[i];
      mergeTwoLists(listA, listB);
      lists[j++] = mainHead;
    }
    // odd list
    if (listsSize % 2 == 1) {
      lists[j++] = lists[listsSize - 1];
    }
    listsSize = j;
  }

  return lists[0];
}
