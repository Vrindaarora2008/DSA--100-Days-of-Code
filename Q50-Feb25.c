struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *current = head;
    struct ListNode *visited[100000];
    int i = 0;
    while(current != NULL)
    {
        for(int j=0; j<i; j++)
        {
            if(visited[j]==current)
            return current;
        }
        visited[i++] = current;
        current = current->next;
    }
    return NULL;
}