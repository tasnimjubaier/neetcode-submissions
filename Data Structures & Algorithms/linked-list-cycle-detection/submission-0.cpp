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
    bool hasCycle(ListNode* head) {
        map<ListNode*, bool> m;
        ListNode* now = head;
        while(now) {
            if(m.find(now) != m.end()) return 1;
            m[now] = 1;
            now = now->next; 
        }
        return 0;
    }
};
