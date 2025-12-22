ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode*fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
            ListNode* newhead=head->next;
            head->next==NULL;
            delete head;
            return newhead;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode* deletenode=slow->next;
        slow->next=slow->next->next;
        deletenode->next=NULL;
        delete deletenode;
        return head;

        
    }
};
