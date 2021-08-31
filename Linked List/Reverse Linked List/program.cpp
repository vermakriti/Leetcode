class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head)return NULL;
        ListNode*curr=NULL,*prev=NULL,*next=head;
        
        while(next){
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        return curr;
        
    }
};