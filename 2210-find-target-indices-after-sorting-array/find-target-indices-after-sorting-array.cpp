class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller=0,cnt=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<target)smaller++;
            if(nums[i]==target)cnt++;
        }
        vector<int> ans;
        for(int i=1;i<=cnt;i++)
        ans.push_back(smaller+i-1);
        return ans;
    }
};