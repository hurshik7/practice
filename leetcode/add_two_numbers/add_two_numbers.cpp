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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carryIn = 0;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            ptr1->val += carryIn + ptr2->val;
            if (ptr1->val > 9) {
                ptr1->val = ptr1->val - 10;
                carryIn = 1;
            } else {
                carryIn = 0;
            } 
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (ptr1 == nullptr && ptr2 == nullptr && carryIn == 1) {
            ListNode* newNode = new ListNode(1);
            ptr1 = l1;
            while (ptr1->next != nullptr) {
                ptr1 = ptr1->next;
            }
            ptr1->next = newNode;
            ptr1 = ptr1->next->next;
        }
        
        while (ptr1 != nullptr) {
            ptr1->val += carryIn;
            if (ptr1->val > 9) {
                ptr1->val = ptr1->val - 10;
                carryIn = 1;
            } else {
                carryIn = 0;
            }
            if (ptr1->next == nullptr && carryIn == 1) {
                ListNode* newNode = new ListNode(1);
                ptr1->next = newNode;
                break;
            }
            ptr1 = ptr1->next; 
        }
        ptr1 = l1;
        while (ptr1->next != nullptr) {
            ptr1 = ptr1->next;
        }
        
        if (ptr2 != nullptr) {
             ptr1->next = ptr2;   
        }
        while (ptr2 != nullptr) {
            ptr2->val += carryIn;
            if (ptr2->val > 9) {
                ptr2->val = ptr2->val - 10;
                carryIn = 1;
            } else {
                carryIn = 0;
            }
            if (ptr2->next == nullptr && carryIn == 1) {
                ListNode* newNode = new ListNode(1);
                ptr2->next = newNode;
                break;
            } 
            ptr2 = ptr2->next;
        }
        
        return l1;
    }
};
