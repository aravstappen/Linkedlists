ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        int length=0;
        ListNode*temp=head;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        ListNode* tail=head;
        k=k % length;
        if(k % length==0){
            return head;
        }
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=head;
        temp=head;

        int x=(length-k);
        while(x!=1){
            temp=temp->next;
            x--;
        }
        ListNode* newhead;
        newhead=temp->next;
        temp->next=NULL;
        return newhead;
    }
};
