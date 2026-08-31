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
        if(head->next->next==NULL || head->next==NULL || head==nullptr)
        {
            return {-1,-1};
        }
        int min=INT_MAX;
        vector<int>ans;
        vector<int>output;
        ListNode*p=head;
        ListNode*dummy=head;
        dummy=dummy->next->next;
        head=head->next;
        int count=2;
        while(head->next!=NULL)
        {
           if(head->val<dummy->val && head->val<p->val)
           {
              ans.push_back(count);
           }
           else if(head->val>dummy->val && head->val>p->val)
           
             {
              ans.push_back(count);
           }
           p=p->next;
           head=head->next;
           dummy=dummy->next;
           count++;
           
        }
        if(ans.size()<2)
        {
            return {-1,-1};
        }
        for(int i=0;i<ans.size()-1;i++)
        {
           if(ans[i+1]-ans[i]<min)
           {
            min=ans[i+1]-ans[i];
           }
        }
         output.push_back(min);
        output.push_back(ans[ans.size()-1]-ans[0]);
       
       
        return output;
        }
};