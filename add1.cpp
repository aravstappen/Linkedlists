 public:
        Node* reverseList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
            return head;
        }
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        head=prev;
        return head;
    }

    Node* addOne(Node* head) {
        // Your Code here
        head=reverseList(head);
        Node*dummy=new Node(-1);
        Node*prev=dummy;
        int carry=1;
        int sum=0;
        Node*temp=head;
        while(temp!=NULL){
            int val=temp->data+carry;
            sum=val%10;
            carry=val/10;
            Node* curr=new Node(sum);
            prev->next=curr;
            prev=curr;
            temp=temp->next;
        }
        if(carry==1){
            Node* extra=new Node(carry);
            curr->next=extra;
        }
        Node* newhead=reverseList(dummy->next);
        return newhead;
