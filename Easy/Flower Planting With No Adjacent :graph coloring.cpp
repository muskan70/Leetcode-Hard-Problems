//Flower Planting With No Adjacent:graph coloring algorithm :https://leetcode.com/problems/flower-planting-with-no-adjacent/
vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> a[N];
        for(int i=0;i<paths.size();i++){
            a[paths[i][0]-1].push_back(paths[i][1]-1);
            a[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> ans(N,0);
        for(int i=0;i<N;i++){
            int col[5]={0};
            for(auto j:a[i])
                col[ans[j]]=1;
            for(int x=1;x<=4;x++){
                if(!col[x]){
                    ans[i]=x;
                    break;
                }
            }
        }
        return ans;
    }