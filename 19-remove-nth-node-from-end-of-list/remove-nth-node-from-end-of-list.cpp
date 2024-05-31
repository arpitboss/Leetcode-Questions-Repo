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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next==nullptr && n==1) {
            delete head;
            return nullptr;
        }
        ListNode *first = head;
        ListNode *second = head;
        for (int i=0;i<n;i++) {
            second=second->next;
        }
        if (second!=nullptr) {
            while (second->next!=nullptr) {
                first=first->next;
                second=second->next;
            }
            ListNode *temp=first->next;
            first->next=first->next->next;
            delete temp;
        }
        else {
            ListNode *temp1=head;
            head=head->next;
            delete temp1;
        }
        return head;
    }
};