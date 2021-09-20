class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *curr1=l1,*curr2=l2,*head,*tail=new ListNode();
        head=tail;
        int c=0;
        
        while(curr1 && curr2){
            
            ListNode *node=new ListNode((curr1->val+curr2->val+c)%10);
            c = (curr1->val+curr2->val+c)/10;
            tail->next=node;
            tail=node;
            curr1=curr1->next;
            curr2=curr2->next;
            
        }
        while(curr1){
        
            ListNode *node = new ListNode((curr1->val+c)%10);
            c = (curr1->val+c)/10;
            tail->next=node;
            tail=node;
            curr1=curr1->next;
        }
        while(curr2){
        
            ListNode *node = new ListNode((curr2->val+c)%10);
            c = (curr2->val+c)/10;
            tail->next=node;
            tail=node;
            curr2=curr2->next;
        }
        
        
        if(c){
             ListNode *node = new ListNode(c);
             tail->next=node;
        }

        head=head->next;
        return head;
        
       
    }
};