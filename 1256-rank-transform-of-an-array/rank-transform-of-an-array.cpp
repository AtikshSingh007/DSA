class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector <pair<int,int>> vec;
        for(int i=0;i<n;i++)
        vec.push_back({arr[i],i});

        sort(vec.begin(),vec.end());
        vector <int> ans(n,0);
        int rank=1;
        for(int i=0;i<n;i++){
            if(i>0 && vec[i].first!=vec[i-1].first)rank++;
        ans[vec[i].second]=rank;
        }
        // for(int i=0;i<n;i++)cout<<vec[i].first<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<vec[i].second<<" ";

        return ans;
        
    }
};