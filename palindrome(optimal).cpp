public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2;
        if(fast==NULL){
            head2=reverseList(slow);
        }
        else if(fast->next==NULL){
            head2=reverseList(slow->next);
        }
        ListNode* temp1=head;
        ListNode* temp2=head2;
        while(temp2!=NULL){
            if(temp1->val!=temp2->val){
                return 0;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return 1;
    }
};
