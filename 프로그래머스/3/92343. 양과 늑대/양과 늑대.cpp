#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
vector<int> info;
int answer=0;
int visited[20][20][20];
vector<vector<int>> adj(20);
void dfs(int sheep, int wolf, int node){
    answer=max(answer, sheep);
    for(int child:adj[node]){
        //cout<<node<<' '<<child<<'\n';
        if(visited[child][sheep][wolf]) continue;
        
        if(info[child]==0){
            visited[child][sheep][wolf]=1;
            info[child]=-1;
            dfs(sheep+1, wolf, child);
            info[child]=0;
            visited[child][sheep][wolf]=0;
        }else if(info[child]==1){
            if(sheep<=wolf+1) continue;
            info[child]=-1;
            visited[child][sheep][wolf]=1;
            dfs(sheep, wolf+1, child);
            info[child]=1;
            visited[child][sheep][wolf]=0;
        }else if(info[child]==-1){
            visited[node][sheep][wolf]=1;
            dfs(sheep, wolf, child);
            visited[node][sheep][wolf]=0;
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    ::info = info;
    //인접 행렬 만들기
    for(vector<int> e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    visited[0][0][0]=1;
    ::info[0]=-1;
    dfs(1,0,0);
    
    return answer;
}