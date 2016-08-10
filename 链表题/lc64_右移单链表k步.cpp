/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //1. special case
        if(head==NULL || head->next==NULL || k==0) return head;
        
        ListNode* pis=head, *tail=0, *res=0;
        int len=0, i=1, mk;
        
        while(pis){ 
            if(pis->next==NULL) tail=pis;//record tail node.
            pis=pis->next; 
            len++;
        }
        
        pis=head;//reset pis
        mk=k%len;//steps
        if(mk==0) return head;//special case
		
        //2.move to the confront node: 3 in eg.
        while(i<=(len-mk-1)){
            pis=pis->next;
            ++i;
        }
        
        //3. concat tail part & leading part: 4->5  +  1->2->3
        res=pis->next;
        tail->next=head;
        pis->next=0;
        
        return res;
    }
};