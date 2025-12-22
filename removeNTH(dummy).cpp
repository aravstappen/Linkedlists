ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy= new ListNode(-1);
        dummy->next=head;
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        dummy->next=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* deleten=slow->next;
        slow->next=slow->next->next;
        delete deleten;
        return dummy->next;
    }
