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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        ListNode* ptrLeft = head;
        ListNode* ptr = head;
        int index = 1;
    
        while (index != left) {
            ptr = ptr->next;
            index++;
        } 
        ptrLeft = ptr;
        
        vector<int> values;
        while (index != right) {
            values.push_back(ptr->val);
            ptr = ptr->next;
            index++;
        }
        values.push_back(ptr->val);
        
        while (values.empty() == false) {
            ptrLeft->val = values.back();
            values.pop_back();
            ptrLeft = ptrLeft->next;
        }
        
        return head;
    }
};
