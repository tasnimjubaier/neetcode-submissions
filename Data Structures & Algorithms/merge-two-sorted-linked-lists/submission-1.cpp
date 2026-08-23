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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* now = new ListNode(0), nex;
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) {
            now->val = list2->val;
            now->next = mergeTwoLists(list1, list2->next);
            // now->next = nex;
            return now;
        }
        if(list2 == nullptr) {
            now->val = list1->val;
            now->next = mergeTwoLists(list1->next, list2);
            // now->next = nex;
            return now;
        }

        if(list1->val < list2->val) {
            now->val = list1->val;
            now->next = mergeTwoLists(list1->next, list2);
            // now->next = nex;
            return now;
        }
        else {
            now->val = list2->val;
            now->next = mergeTwoLists(list1, list2->next);
            // now->next = nex;
            return now;
        }

    }
};
