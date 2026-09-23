class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long target=accumulate(nums.begin(),nums.end(),0ll);
        target-=x;
        if(target<0)return -1;
        int ops=1e9;
        long long sum=0;
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(j<n && sum>target )
            {
                sum-=nums[j];
                j++;
            }
            if(sum==target)
            ops=min(ops,n- (i-j+1));

        }
        if(ops==1e9)return -1;
        return ops;


    }
};