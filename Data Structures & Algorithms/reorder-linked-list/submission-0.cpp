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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* now = head; 
        while(now) v.push_back(now), now = now->next;
        int n = v.size();
        for(int i = 0; i < n/2; i++) {
            v[i]->next = v[n-i-1];
            v[n-i-1]->next = v[i+1];
        }

        if(n&1) {
            v[n/2]->next = nullptr;
        }
        else {
            v[n/2]->next = nullptr;
            v[n/2-1]->next = v[n/2];
        }
        
    }
};
