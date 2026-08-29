class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector <pair<int,int> > vec;
        int n=nums.size();
        for(int i=0;i<n;i++)
        vec.push_back(make_pair(nums[i],i));
        sort(vec.begin(),vec.end());

        vector<int> ans(n,-1);
        for(int i=0;i<n;)
        {
            vector <int> temp={ vec[i].first},ind={vec[i].second};
            
            int j=i+1;
            for(;j<n && (vec[j].first-vec[j-1].first)<=limit;j++)
            {
                temp.push_back(vec[j].first);
                ind.push_back(vec[j].second);
            }
            sort(ind.begin(),ind.end());
            int m=temp.size();
            for(int j=0;j<m;j++)
            ans[ind[j]]=temp[j];
            i=j;
        }
        return ans;
    }
};