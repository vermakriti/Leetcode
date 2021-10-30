/*

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return head;
        
        ListNode*curr=head->next,*newHead=head,*next,*temp;
        newHead->next=nullptr;
        
        while(curr){
            ListNode*newCurr=newHead,*prev=nullptr;
            bool flag=false;
            while(newCurr){
                if(curr->val <= newCurr->val){
                    next=curr->next;
                    if(prev==nullptr){
                        newHead=curr;
                        newHead->next=newCurr;
                    }
                    else{
                        prev->next=curr;
                        curr->next=newCurr;
                    }
                    flag=true;
                    break;
                }
                prev=newCurr;
                newCurr=newCurr->next;
            }
            if(!flag){
                next=curr->next;
                prev->next=curr;
                curr->next=nullptr;
                curr=next;
            }
            else curr=next;
            
        }
        return newHead;
    }
};