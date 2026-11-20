class Solution {
public:
    int maxSelectedElements(vector<int> nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)cout<<nums[i]<<" ";
       vector<int> dp(n,1),dpi(n,1);
unordered_map<int,int> mp,mpi;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1] ) 
            {
                dpi[i]=dp[i-1]+1;
                
            }
            else if( nums[i]==(nums[i-1]+1) )
            {
                dp[i]=dp[i-1]+1;
                dpi[i]=dpi[i-1]+1;
            }
            else if( nums[i]==(nums[i-1]+2))
            {
                dp[i]=dpi[i-1]+1;
            }
            mp[nums[i]]=max( dp[i],mp[nums[i]] );
            mp[nums[i]+1]=max(dpi[i],mp[nums[i]+1] );
            dp[i]=mp[nums[i]];
            dpi[i]=mp[nums[i]+1];
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,max(dp[i],dpi[i]));
        return ans;
    }
};