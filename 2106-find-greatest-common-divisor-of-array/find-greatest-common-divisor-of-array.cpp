class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=-1,mn=1e9;
        for(auto i:nums)
        {
            mx=max(i,mx);
            mn=min(i,mn);
        }
        return __gcd(mx,mn);
    }
};