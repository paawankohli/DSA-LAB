int length(node* head) 
{ 
    if(head == NULL)
        return 0; 
    
    node* temp = head; 
    return 1 + length(temp->next);  
} 

node* bubble_sort_LinkedList_itr(node* head) 
{ 
    for(int i = 0 ; i < length(head) ; i++) 
    { 
        node *curr = head; 
        
        while(curr->next != NULL) 
            if(curr->data > curr->next->data) 
                swap(curr->data, curr->next->data);
            else 
                curr = curr->next; 
    } 
    return head; 
}

