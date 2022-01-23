/* 
* Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
*/ 

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode iterator = head;
        if (iterator == null) {
            return head;
        }

        while (iterator != null && iterator.val == val) {
            head = iterator.next;
            iterator = head;
        }

        ListNode previousLink = iterator;
        while (iterator != null) {
            if (iterator.val == val) {
                previousLink.next = iterator.next;
            } else {
                previousLink = iterator;
            }
            iterator = iterator.next;
        }
        return head;
    }
}
