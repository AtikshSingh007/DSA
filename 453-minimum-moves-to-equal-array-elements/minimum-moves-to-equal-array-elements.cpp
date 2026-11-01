class Solution {
public:
    int minMoves(vector<int>& nums) {
       int n=nums.size();
       int mn=1e9;
    int ans=0;
       for(int i=0;i<n;i++)mn=min(mn,nums[i]);
        for(int i=0;i<n;i++)ans+=(nums[i]-mn);
        return ans;
    }
};