// Flatten a Multilevel Doubly Linked List 

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        Node* cans=NULL;
        Node* nans=flatten(head->next);
        if(head->child!=NULL) cans=flatten(head->child);
        if(cans!=NULL){
            head->child=NULL; //important step
            head->next=cans;
            cans->prev=head;
            while(cans->next!=NULL){
                cans=cans->next;
            }
            cans->next=nans;
            if(nans)
            nans->prev=cans;
        }
        else {
            head->next=nans;
            if(nans!=NULL)
            nans->prev=head;
        }
        
        return head;
        
    }
};
