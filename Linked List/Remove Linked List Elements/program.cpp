class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return NULL;
        ListNode*curr=head,*prev=NULL;
        while(curr){
            if(curr->val==val){
                if(prev==NULL){
                    head=head->next;
                    curr=curr->next;
                }
                else{
                    prev->next=curr->next;
                    curr=prev->next;
                }
                
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};