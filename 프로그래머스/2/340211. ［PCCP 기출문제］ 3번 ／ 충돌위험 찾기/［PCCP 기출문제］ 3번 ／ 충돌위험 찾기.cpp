#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int map[110][110][10001]={0,};
vector<vector<vector<pair<int,int>>>> visited(110, vector<vector<pair<int,int>>>(110, vector<pair<int,int>>()));

int answer=0;
struct node{
    int x;
    int y;
};
int bfs(vector<int> start, vector<int> dest, int startd, int order){
    int visited2[110][110]={0,};
    node parent[110][110];
    queue<node> q;
    visited2[start[0]][start[1]]=startd;
    parent[start[0]][start[1]]={-1,-1};
    q.push({start[0], start[1]});
    
    while(!q.empty()){
        node coor=q.front();
        q.pop();
        int x=coor.x, y=coor.y;
        if(x==dest[0] && y==dest[1]){
            break;
        }
        for(int i=0; i<4; i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx<1||ny<1||nx>100 || ny>100) continue;
            if(visited2[nx][ny]) continue;
            visited2[nx][ny]=visited2[x][y]+1;
            parent[nx][ny]={x, y};
            q.push({nx, ny});
        }
    }
    int x=dest[0], y=dest[1];
    int depth=visited2[x][y];
    while(1){
        if(x==-1 && y==-1) break;
        for(auto val:visited[x][y]){
            if(val.second==depth && map[x][y][val.second]==0 && val.first!=order) {
                answer++;
                
                map[x][y][val.second]=1;
            }
        }
        visited[x][y].push_back({order,depth});
        
        node p=parent[x][y];
        x=p.x; y=p.y;
        depth--;
        
    }
    return visited2[dest[0]][dest[1]];
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    for(int j=0; j<routes.size(); j++){
        auto route=routes[j];
        int startd=1;
        for(int i=1; i<route.size(); i++){
            startd=bfs(points[route[i-1]-1], points[route[i]-1], startd, j+1);
            
        }
       
    }
    
    return answer;
}