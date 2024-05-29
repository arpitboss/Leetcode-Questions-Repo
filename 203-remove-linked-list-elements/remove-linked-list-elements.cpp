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
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL) {
            return head;
        }
        // if (head->val!=val && head->next==NULL) {
        //     return head;
        // }
        ListNode *curr = head;
        ListNode *temp = head;
        ListNode *newHead = head;
        while (curr!=NULL) {
            if (curr->val==val) {
                if (temp==curr) {
                    ListNode *temp2=curr;
                    curr=curr->next;
                    temp=temp->next;
                    newHead = temp;
                    delete temp2;
                }
                else {
                    ListNode *temp1=curr;
                    curr=curr->next;
                    temp->next=curr;
                    delete temp1;
                }
                
            }
            else {
                temp=curr;
                curr = curr->next;
            }
        }
        return newHead;
    }
};