/*

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int count=0,length=0,rem;
        ListNode*curr=head,*next;
        while(curr){
            count++;
            curr=curr->next;
        }
        length=count/k;
        curr=head;
        rem=count%k;
        count=0;
        while(curr){
            count++;
            if(count==1)
                ans.push_back(curr);
            if(count==length+1 && rem>0){
                next=curr->next;
                curr->next=nullptr;
                curr=next;
                rem--;
                count=0;
                continue;
            }
            else if(count==length && rem==0){
                next=curr->next;
                curr->next=nullptr;
                curr=next;
                count=0;
                continue;
            }
            curr=curr->next;
        }
        while(ans.size()<k)
            ans.push_back(nullptr);
        return ans;
    }
};