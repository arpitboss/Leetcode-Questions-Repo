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
            // TLE
    // ListNode* removeNodes(ListNode* head) {
    //     if (head==nullptr || head->next==nullptr) {
    //         return head;
    //     }
    //     ListNode *temp=head;
    //     ListNode *curr;
    //     bool first=true;
    //     while (temp->next!=nullptr) {
    //         if (first==true) {
    //             curr=temp->next;
    //             first=false;
    //         }
    //         else {
    //         temp=temp->next;
    //         curr=temp->next;
    //         }
    //         while (curr!=nullptr) {
    //             if (temp->val<curr->val) {
    //                 if (head==temp) {
    //                     ListNode *temp1=head;
    //                     temp=temp->next;
    //                     head=head->next;
    //                     curr=temp->next;
    //                     delete temp1;
    //                 }
    //                 else {
    //                     temp->val=temp->next->val;
    //                     ListNode *temp2=temp->next;
    //                     temp->next=temp->next->next;
    //                     curr=temp->next;
    //                     delete temp2;
    //                     first=true;
    //                     break;
    //                 }
    //             }
    //             else {
    //                 curr=curr->next;
    //             }
    //         }
    //     }
    //     return head;
    // }


    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* reversedHead = reverseList(head);

        ListNode* current = reversedHead;
        int maxValue = INT_MIN;
        ListNode* prev = nullptr;

        while (current != nullptr) {
            if (current->val < maxValue) {
                prev->next = current->next;
            } else {
                maxValue = current->val;
                prev = current;
            }
            current = current->next;
        }

        return reverseList(reversedHead);
    }
};