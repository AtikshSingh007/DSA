class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int  mn=1e9,n=nums.size(),ans=1e9;
        for(int i=0;i<n;i++)
        {
        int  sum=0;
            for(int j=i;j<n;j++)
            {
                int sz=j-i+1;
                sum+=nums[j];
                if(sum>0 && sz>=l && sz<=r)
                {
                    ans =min(ans,sum);
                }
            }
        }
        if(ans==1e9)return -1;
        return ans;
    }
};