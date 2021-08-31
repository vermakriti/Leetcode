class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode*curr=head,*prev=nullptr,*next=nullptr;
        while(curr && curr->next){
            next=curr->next->next;
            if(prev==nullptr){
                head=curr->next;
            }
            else{
                prev->next=curr->next;
            }
            curr->next->next=curr;
            curr->next=next;
            prev=curr;
            curr=next;
        }
        return head;
    }
};