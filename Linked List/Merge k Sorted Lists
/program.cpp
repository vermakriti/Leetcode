/*

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []
 
*/


// TC- O(NlogN) SC-O(N) where N is number of nodes in linkedlist.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
            return nullptr;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> q;
        ListNode*head=nullptr,*tail=new ListNode(-1);
        head=tail;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                 q.push({lists[i]->val,lists[i]});
        }
        while(!q.empty()){
            ListNode*curr=q.top().second;
            q.pop();
            tail->next=curr;
            tail=curr;
            curr=curr->next;
            if(curr)
                q.push({curr->val,curr});
        }
        
        head=head->next;
        return head;
        
    }
};