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
    bool hasCycle(ListNode *head) {
        if (head==nullptr || head->next==nullptr) {
            return false;
        }
        ListNode *slow_p = head;
        ListNode *fast_p = head;
        while (fast_p->next!=nullptr && fast_p->next->next!=nullptr) {
            slow_p=slow_p->next;
            fast_p=fast_p->next->next;
            if (slow_p == fast_p) {
                return true;
            }
        }
        return false;
    }
};