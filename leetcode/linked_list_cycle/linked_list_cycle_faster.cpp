bool hasCycle(ListNode* head)
{
    if (head == nullptr) {
        return false;
    }
    int count = 0;
    ListNode* ptr = head;
    while (ptr != nullptr) {
        count++;
        if (count > 10000) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}
