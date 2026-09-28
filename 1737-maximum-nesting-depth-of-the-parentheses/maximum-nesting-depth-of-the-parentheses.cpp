class Solution {
public:
    int maxDepth(string s) {
       int op=0,n=s.size(),ans=0;
       for(int i=0;i<n;i++)
       {
        if(s[i]=='(')op++;
        else if(s[i]==')') op--;
        ans=max(ans,op);
       }
       return ans;
        
    }
};