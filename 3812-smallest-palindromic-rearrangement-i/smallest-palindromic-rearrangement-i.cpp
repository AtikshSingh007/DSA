class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        char ch;
        vector<int> alpha(26,0);
        for(int i=0;i<(n+1)/2;i++)
        {
            if(n&1 && i==(n/2) )
            ch=s[i];
            else
            alpha[s[i]-'a']++;
        }
        string ans;
        for(int i=0;i<26;i++)
        {
            while(alpha[i]>0)
            {
                alpha[i]--;
                ans.push_back(char(97+i) );
            }
        }
cout<<ans<<endl;
        auto temp=ans;
        reverse(temp.begin(),temp.end());
        if(n&1)ans+=ch;
        ans+=temp;
        return ans;
       
    }
};