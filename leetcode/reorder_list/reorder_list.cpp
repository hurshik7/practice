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
        ListNode* ptr = head;
        while (ptr != nullptr) {
            v.push_back(ptr);
            ptr = ptr->next;
        }
        if (v.size() <= 2) {
            return;
        }
        
        int front = 0;
        int back = v.size() - 1;
        
        while (front < back) {
            v[back]->next = v[front]->next;
            v[front]->next = v[back];
            front++;
            back--;
            if (front + 1 == back || front == back) {
                v[back]->next = nullptr;
                break;
            }
        }
    }
};
