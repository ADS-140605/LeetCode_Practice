/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos=1;
        int first=-1,prev=-1;
        int mn=INT_MAX;
        ListNode* p=head;
        ListNode* c=head->next;
        while(c && c->next){
            ListNode* n=c->next;
            if((c->val>p->val && c->val>n->val) ||
               (c->val<p->val && c->val<n->val)){
                if(first==-1){
                    first=pos;
                }
                else{
                    mn=min(mn,pos-prev);
                }
                prev=pos;
            }
            p=c;
            c=n;
            pos++;
        }
        if(first==-1 || first==prev)
            return {-1,-1};
        return {mn,prev-first};
    }
};