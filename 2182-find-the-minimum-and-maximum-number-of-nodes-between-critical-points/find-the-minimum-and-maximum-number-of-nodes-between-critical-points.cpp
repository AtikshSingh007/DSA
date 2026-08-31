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
        ListNode* curr=head;
        vector <int> vec;
        while(curr)
        {
            vec.push_back(curr->val);
            curr=curr->next;
        }
        int n=vec.size();
        vector<int> critical;
        for(int i=1;i<n-1;i++)
        if( (vec[i]>vec[i-1] && vec[i]>vec[i+1]) ||
         (vec[i]<vec[i-1] && vec[i]<vec[i+1]) )
         critical.push_back(i);

if(critical.size()<=1)return {-1,-1};

         int mn=1e9,mx=critical.back()-critical[0];
        int m=critical.size();
        for(int i=1;i<m;i++)mn=min(mn,critical[i]-critical[i-1]);
        return {mn,mx};
        

    }
};