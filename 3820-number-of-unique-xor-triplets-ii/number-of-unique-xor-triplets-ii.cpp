class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s1, s2;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                s1.insert(nums[i] ^ nums[j]);
        for (auto i : s1)
            for (int j = 0; j < n; j++)
                s2.insert(i ^ nums[j]);
        return s2.size();
    }
};