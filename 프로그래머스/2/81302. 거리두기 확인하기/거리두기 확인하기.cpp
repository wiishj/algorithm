#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

bool dfs(vector<vector<char>> room, vector<pair<int,int>>p){
    for(auto& coor:p){
        vector<vector<int>> visited(6, vector<int>(6, -1));
        stack<pair<int,int>> s;
        s.push(coor);
        visited[coor.first][coor.second]=0;
        while(!s.empty()){
            int row=s.top().first, col=s.top().second;
            s.pop();
            int depth=visited[row][col];
            if(room[row][col]=='P' && depth<=2 && depth>=1) return false;
            if(depth>=2) continue;
            for(int i=0; i<4; i++){
                int ny=row+dy[i], nx=col+dx[i];
                if(ny<0 || nx<0 || ny>=5 || nx>=5) continue;
                if(room[ny][nx]=='X') continue;
                if(visited[ny][nx]>=0) continue;
                visited[ny][nx]=depth+1;
                s.push({ny, nx});
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto& place: places){
        vector<vector<char>> room(5, vector<char>(5));
        vector<pair<int,int>> p;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++) {
                room[i][j]=place[i][j];
                if(room[i][j]=='P') p.push_back({i,j});
            }
        }
        if(dfs(room, p)) answer.push_back(1);
        else answer.push_back(0);
        
    }
    return answer;
}