class Solution {
public:
    ListNode*reverse(ListNode*head){
        
        ListNode*curr=NULL,*prev=NULL,*next=head;
        while(next){
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        head=curr;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head)return head;
        
        ListNode*prev=NULL,*curr=head,*next=NULL,*tail=NULL,*reverse_head=NULL;
        int count=0;
        
        while(curr){
            
            count++;
            if(left-1==count){
                prev=curr;
            }    
            if(left==count){
                tail=curr;
            }
            if(right==count){
                reverse_head=curr;
            }
            curr=curr->next;
        }
        next=reverse_head->next;
        reverse_head->next=NULL;
        reverse_head=reverse(tail);
        
        if(!prev){
            head=reverse_head;
        }
        else{
            prev->next=reverse_head;
        }
        tail->next=next;
        return head;
        

        
    }
};