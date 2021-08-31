class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head,*fast=head,*prev=nullptr;
        n--;
        while(n--){
            fast=fast->next;
        }
        while(fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(prev==nullptr)
            head=head->next;
        else prev->next=slow->next;
        return head;
    }
};