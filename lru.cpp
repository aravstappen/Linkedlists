class Node{
    public:
    int key1;
    int data;
    Node* next;
    Node* prev;
    Node(int key,int val){
        key1=key;
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:
    void deletenode(Node* node){
        Node* afternode=node->next;
        Node*beforenode=node->prev;
        beforenode->next=afternode;
        afternode->prev=beforenode;
        node->next=NULL;
        node->prev=NULL;
    }
    void insertathead(Node* node){
        Node* curr=head->next;
        head->next=node;
        node->next=curr;
        node->prev=head;
        curr->prev=node;
    }
    int cap;
    Node* head;
    Node* tail;
    map<int,Node*> mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node* node=mpp[key];
        deletenode(node);
        insertathead(node);
        return node->data;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            deletenode(node);
            insertathead(node);
            node->data=value;
        }
        else{
            if(mpp.size()==cap){
                Node* node=tail->prev;
                deletenode(node);
                mpp.erase(node->key1);
                delete node;
            }
            Node* newnode = new Node(key,value);
            mpp[key]=newnode;
            insertathead(newnode);
        }
    }
};
