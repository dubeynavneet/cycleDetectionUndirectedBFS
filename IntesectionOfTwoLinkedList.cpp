// without altering both lists
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> umap;
        ListNode *temp1,*temp2;
        temp1=headA;
        temp2=headB;
        while(temp1!=NULL){
            umap.insert(temp1);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            if(umap.find(temp2)!=umap.end()){
                break;
            }
            temp2=temp2->next;
        }
        return temp2;
    }
};



// with altering any one lists

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node *temp;
    temp=firstHead->next;
    while(firstHead->next!=NULL){
        firstHead->next=NULL;
        firstHead=temp;
        temp=firstHead->next;
    }
    while(secondHead->next!=NULL){
        secondHead=secondHead->next;
    }
    return secondHead;
}
