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
    void solve(ListNode *head) {
        if (head==nullptr || head->next==nullptr || head->next->next==nullptr) {
            return;
        }
        ListNode *curr=head;
        ListNode *temp=head;
        ListNode *temp2=temp->next;
        ListNode *temp3;
        while (curr->next!=nullptr) {
            if (curr->next->next==nullptr) {
                temp3=curr;
            }
            curr=curr->next;
        }
        temp3->next=nullptr;
        temp->next=curr;
        curr->next=temp2;
        solve(temp2);
    }
    void reorderList(ListNode* head) {
        solve(head);
    }
};