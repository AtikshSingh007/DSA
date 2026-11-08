
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue < vector<long long > , vector<vector<long long >> , greater <vector<long long >> > we,wait;
        int n=servers.size(),m=tasks.size();
        vector<int> ans(m);
        for(int i=0;i<n;i++)we.push({servers[i],i,0}); // { weight , i , time }

        for(long long  i=0;i<m;i++)
        {
                while (!wait.empty() && wait.top()[0]<=i)
                {
                    auto vec=wait.top();
                    wait.pop();
                    we.push({servers[vec[1]] ,vec[1] , vec[0] });
                   // cout<<vec[1]<<endl;
                }
                if( !we.empty() )
                {
                    auto temp=we.top();
                    we.pop();
                    ans[i]=temp[1];
                    wait.push({max(temp[2],i)+tasks[i],temp[1]});
                }
                else 
                {
                  //  cout<<" empty "<<endl;
                    auto waittop=wait.top();
                    while(!wait.empty() && wait.top()[0]==waittop[0])
                    {

                        auto front=wait.top();
                        wait.pop();
                        
                        we.push({servers[front[1]],front[1] , front[0]});
                      // cout<< front[i]<<endl;
                    }
                    waittop=we.top();
                    we.pop();
                    ans[i]=waittop[1];
                    wait.push({max(waittop[2],i)+tasks[i], waittop[1]});
                }
        }
        return ans;

    }
};
