// https://leetcode.com/problems/merge-two-sorted-lists/

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
    bool pick_first(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return false;
        if (l2 == nullptr) return true;
        return l1->val < l2->val;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode h(0);
        ListNode* cur = &h;
        
        while (l1 != nullptr || l2 != nullptr) {
            if (pick_first(l1, l2)) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        return h.next;
    }
};
