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
        vector<ListNode*> v;
        ListNode* now = head;
        while(now) v.push_back(now), now = now->next;

        int m = v.size();
        n = m - n;
        if(n == 0) {
            if(m <= 1) return nullptr;
            return v[1];
        }

        v[n-1]->next = v[n]->next;
        return head;
    }
};
