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
    bool isIn(vector<ListNode*> v, ListNode* value) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == value) {
                return true;
            }
        }
        return false;
    }
    
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        vector<ListNode*> v;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            if (isIn(v, ptr) == false) {
                v.push_back(ptr);
            } else {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
};
