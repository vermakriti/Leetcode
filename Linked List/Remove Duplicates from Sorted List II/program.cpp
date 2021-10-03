/*

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

*/

// TC-O(N) SC-O(N)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        map<int,int> mp;
        ListNode*curr=head,*prev=NULL;
        while(curr){
            mp[curr->val]++;
            curr=curr->next;
        }
        curr=head;
        while(curr){
            
            if(mp[curr->val]>1){
                
                ListNode*dup_curr=curr;
                while(dup_curr && curr->val==dup_curr->val){
                    dup_curr=dup_curr->next;
                }
                if(!prev){
                    head=dup_curr; 
                }
                else prev->next=dup_curr;
                curr=dup_curr;
                continue;
            }
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};

// TC-O(N) SC-O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        bool check=false;
        ListNode*curr=head,*prev=nullptr;
        while(curr && curr->next){
            while(curr && curr->next && curr->val==curr->next->val){
                check=true;
                curr=curr->next;
            }
            if(check && !prev)
                head=curr->next;
            else if(check && prev)
                prev->next=curr->next;
            else
                prev=curr;
            curr=curr->next;
            check=false;
        }
        return head;
    }
};