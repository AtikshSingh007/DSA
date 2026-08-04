class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx=-1e9,mn=1e9;
        vector <int> ans;
        for(auto i:nums)mx=max(i,mx);
        for(auto i:nums)mn=min(i,mn);
        int zero=-mn;
        vector <int> f(zero+mx+1,0);
        for(auto i:nums)f[zero+i]=1;
        for(int i=mn;i<=mx;i++)if(f[zero+i]==0)ans.push_back(i);
return ans;
    }
};