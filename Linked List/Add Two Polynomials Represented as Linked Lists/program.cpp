class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        
        PolyNode*tail=new PolyNode(),*head=tail;
        while(poly1 && poly2){
            if(poly1->power==poly2->power){
                int c = poly1->coefficient + poly2->coefficient;
                if(c){
                    PolyNode*node = new PolyNode(c,poly1->power);
                    tail->next=node; 
                    tail=tail->next;
                }
                poly1=poly1->next;
                poly2=poly2->next;
            }
            else if(poly1->power>poly2->power){
                PolyNode*node = new PolyNode(poly1->coefficient,poly1->power);
                tail->next=node;
                poly1=poly1->next;
                tail=tail->next;
            }
            else{
                PolyNode*node = new PolyNode(poly2->coefficient,poly2->power);
                tail->next=node;
                poly2=poly2->next;
                tail=tail->next;
            }
            
        }
        while(poly1){
            PolyNode*node = new PolyNode(poly1->coefficient,poly1->power);
            tail->next=node;
            poly1=poly1->next;
            tail=tail->next;
        }
        while(poly2){
            PolyNode*node = new PolyNode(poly2->coefficient,poly2->power);
            tail->next=node;
            poly2=poly2->next;
            tail=tail->next;
        }
        head=head->next;
        return head;
    }
};