class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx=-1e9,mn=1e9,mxi=-1,mni=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mx)
            {
                mxi=i;
                mx=nums[i];
            }
            if(nums[i]<mn)
            {
                mni=i;
                mn=nums[i];
            }
        }
            if(mni>mxi)swap(mxi,mni);
            vector<int> vec={n-mxi, mni+1,mxi-mni};
            sort(vec.begin(),vec.end());
            cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;
            return (vec[0]+vec[1]);
        
    }
};