 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        int sum=0;
        ListNode* dummynode=new ListNode(-1);
        ListNode* curr=dummynode;
        while(temp1 !=NULL || temp2 !=NULL){
            int val1=0;
            if(temp1!=NULL){
                val1=temp1->val;
            }
            int val2=0;
            if(temp2!=NULL){
                val2=temp2->val;
            }
            sum = val1+val2+carry;
            carry= sum/10;
            ListNode* sumnode=new ListNode(sum%10);
            curr->next=sumnode;
            curr=curr->next;


            if(temp1 !=NULL){
                temp1=temp1->next;
            }
            if(temp2 !=NULL){
                temp2=temp2->next;
            }
        }
        if(carry!=0){
            ListNode* final=new ListNode(carry);
            curr->next=final;
        }
        return dummynode->next;
    }
};
