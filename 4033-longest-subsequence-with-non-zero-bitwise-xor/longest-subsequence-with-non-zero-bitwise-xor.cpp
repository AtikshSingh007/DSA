class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr=0,n=nums.size();int nonzero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)nonzero=1;
            xorr^=nums[i];
        }
        if(!nonzero)return 0;
        if(xorr==0)return n-1 ;
        return n;

    }
};