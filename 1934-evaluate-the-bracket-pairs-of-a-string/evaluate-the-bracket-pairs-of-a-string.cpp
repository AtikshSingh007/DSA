class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map <string,string> mp;
        for(auto i:knowledge)mp[i[0]]=i[1];
        string stack="",ans="";
        int n=s.size();
        int f=0;
        for(int i=0;i<n;i++)
        {
            if( s[i]!=')' && s[i]!='(')
            {
            if(f==1 )
            stack.push_back(s[i]);
            else ans.push_back(s[i]);
            }

            if(s[i]=='(')f=1;
            if(s[i]==')')
            {
               // cout<<stack<<endl;
                ans+=(mp.count(stack))?mp[stack]:"?";
                f=0;
                stack="";
            }
        }
        return ans;

    }
};