Node* reverse(Node *head) {
    if (!head || !head->next) return head;
    
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}