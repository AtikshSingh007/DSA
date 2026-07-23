class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int msb=log2(n)+1;
        if(n<=2)return n;
        else return (1<<(msb));
    }
};