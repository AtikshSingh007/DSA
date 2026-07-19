class Solution {
public:
    string smallestSubsequence(string s) {
       vector <int> cnt(26,0),f(26,0);
       string ans="";
       int n=s.size();
       for(auto i:s)cnt[i-'a']++;

       for(int i=0;i<n;i++)
       {
        while(ans.size() && ans.back()>s[i] && cnt[ans.back()-'a']>0 && f[s[i]-'a']==0 )
        {
            auto rem=ans.back();
            f[rem-'a']=0;
            ans.pop_back();
           // cnt[rem-'a']--;
        }

        if(f[s[i]-'a']==0)
        {
              f[s[i]-'a']=1;
              
              ans.push_back(s[i]);  
        }
        cnt[s[i]-'a']--;
       }
       return ans;
    }
};