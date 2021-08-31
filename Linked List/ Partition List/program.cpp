class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(!head)return nullptr;
        
        ListNode*before,*after,*before_tail=new ListNode(-1),*after_tail=new ListNode(-1);
        before=before_tail;
        after=after_tail;
        
        while(head){
            if(head->val<x){
                before_tail->next=head;
                before_tail=before_tail->next;
            }
            else{
                after_tail->next=head;
                after_tail=after_tail->next;
            }
            head=head->next;
        }
        before=before->next;
        after=after->next;
        before_tail->next=nullptr;
        after_tail->next=nullptr;
        if(before && after){
            before_tail->next=after;
            return before;
        }
        if(before)
            return before;
        return after;
    }
};