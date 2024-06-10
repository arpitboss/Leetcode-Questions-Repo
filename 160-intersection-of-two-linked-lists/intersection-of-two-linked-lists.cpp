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
        unordered_set<ListNode *> s;

        for (ListNode *p=headA;p!=nullptr;p=p->next) {
            s.insert(p);
        }

        for (ListNode *p=headB;p!=nullptr;p=p->next) {
            if (s.find(p)!=s.end()) {
                return p;
            }
        }
        return nullptr;
    }
};