class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        auto temp=nums;
        sort(temp.begin(),temp.end());
        int g=( (1<<30)-1);
        int n=nums.size();int f=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)g=(g&nums[i]);
            if(nums[i]==0 && temp[i]==0)f=1;  
        } 
        if(g>1e5)return 0;
        else
        return g;     
    }
};