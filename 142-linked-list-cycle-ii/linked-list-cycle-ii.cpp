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
    ListNode *detectCycle(ListNode *head) {
        if (head==nullptr || head->next==nullptr) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast!=nullptr && fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (slow!=fast) {
            return nullptr;
        }
        slow=head;
        while (slow->next!=fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
        if (slow==fast) {
            return fast;
        }
        else {
            return fast->next;
        }
    }
};