class Solution {
public:
    int len(ListNode*head){
        ListNode*curr=head;
        int len=0;
        while(curr){
            len++;
            curr=curr->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA,lenB,cnt=0;
        ListNode*currA,*currB,*common_node=NULL;
        lenA=len(headA);
        lenB=len(headB);
        if(lenA>lenB){
            currA=headA;
            cnt=0;
            while(currA){
                cnt++;
                if(lenA-lenB+1==cnt)
                    break;
                currA=currA->next;
            }
            
        }
        if(lenA<lenB){
            currB=headB;
            cnt=0;
            while(currB){
                cnt++;
                if(lenB-lenA+1==cnt)
                    break;
                currB=currB->next;
            }
            
        }
        while(currA && currB){
            
            if(currA==currB){
                common_node=currA;
                break;
            }
            currA=currA->next;
            currB=currB->next;
        }
        return common_node;
        
    }
};