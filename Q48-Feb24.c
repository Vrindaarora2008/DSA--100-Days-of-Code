struct ListNode* removeElements(struct ListNode* head, int val) {
    // Step 1: Remove nodes from the beginning if they match val
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    
    // Step 2: Now remove matching nodes from the rest of the list
    struct ListNode* current = head;
    
    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            // Skip the next node (remove it)
            current->next = current->next->next;
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    
    return head;
}