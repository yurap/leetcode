// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        
        if (!headA || !headB) return nullptr;
        
        bool jump = false;
        while (curA != curB) {
            if (curA->next != nullptr) curA = curA->next;
            else {
                if (jump) return nullptr;
                curA = headB;
                jump = true;
            }
            
            if (curB->next != nullptr) curB = curB->next;
            else curB = headA;
        }
        
        return curA;
    }
};
