ListNode* oddEvenList(ListNode* head) {
       if(head==NULL) return NULL;
       if(head->next==NULL) return head;    
       ListNode* odd=head;
       ListNode* even=odd->next;
       ListNode* evenhead=odd->next;
       while(odd!=NULL && odd->next!=NULL && even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
       }
       if(odd->next==NULL || even->next==NULL){
        odd->next=evenhead;
       }
       return head;
    }
};
