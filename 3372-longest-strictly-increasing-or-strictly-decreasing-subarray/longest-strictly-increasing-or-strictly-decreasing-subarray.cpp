class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1,ans=1,n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                inc=1;
                dec++;
            }
            else if(nums[i]>nums[i-1])
            {
                dec=1;
                inc++;
            }
            else 
            {
                dec=1;
                inc=1;
            }
            ans=max(ans,max(inc,dec));

        }
        return ans;

    }
};