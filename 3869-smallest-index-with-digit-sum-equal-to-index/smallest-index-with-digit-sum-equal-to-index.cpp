class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=0;
        for(auto i=0;i<nums.size();i++)
        {
            int temp=nums[i],sum=0;
            while(temp>0)
            {
            sum+=temp%10;
            temp/=10;
            }
            if(sum==i)return i;
        }
        return -1;
    
    }
};