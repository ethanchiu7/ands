//
//  LC_ListDelete.cpp
//  HelloWorld
//
//  Created by didi on 7/25/22.
//


//  Definition for singly-linked list.
//19. 删除链表的倒数第 N 个结点
//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            length ++;
            head = head->next;
        }
        return length;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        for (int i = 1; i < length - n + 1; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return dummy->next;
    }
};
