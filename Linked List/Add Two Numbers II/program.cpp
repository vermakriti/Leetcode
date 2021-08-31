class Solution {
public:
    ListNode*reverse(ListNode*head){
        ListNode*curr=nullptr,*prev=nullptr,*next=head;
        while(next){
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        return curr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head,*tail=new ListNode(-1);
        head=tail;
        int c=0;
        l1=reverse(l1);
        l2=reverse(l2);
        while(l1 && l2){
            
            ListNode *node=new ListNode((l1->val+l2->val+c)%10);
            c = (l1->val+l2->val+c)/10;
            tail->next=node;
            tail=node;
            l1=l1->next;
            l2=l2->next;
            
        }
        while(l1){
            ListNode *node = new ListNode((l1->val+c)%10);
            c = (l1->val+c)/10;
            tail->next=node;
            tail=node;
            l1=l1->next;
        }
        while(l2){
            ListNode *node = new ListNode((l2->val+c)%10);
            c = (l2->val+c)/10;
            tail->next=node;
            tail=node;
            l2=l2->next;
        }
        
        if(c){
             ListNode *node = new ListNode(c);
             tail->next=node;
        }

        head=head->next;
        head=reverse(head);
        return head;
    }
};