class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
      int n = nums.size();
       vector<int> mx(n), mn(n); 
       
       mx[0] = nums[0];
       mn[n-1] = nums.back();
       
       for(int i = 1; i < n; i++)
       {
        mx[i] = max(nums[i], mx[i-1]);
        mn[n-1-i] = min(nums[n-1-i], mn[n-i]);
       }
       
       for(int i = 0; i < n; i++)
       {
        if( (mx[i] - mn[i]) <= k )
            return i;
       } 
       return -1;
    }
};