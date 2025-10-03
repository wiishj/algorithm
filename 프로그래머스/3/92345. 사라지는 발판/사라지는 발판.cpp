#include <iostream>
#include <string>
#include <vector>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int dfs(vector<vector<int>> board, vector<int> now, vector<int> next){
    int y=now[0], x=now[1];
    if(board[y][x]==0) return 0; //같은 칸에 있다가 이전에서 상대방이 옮겨 갔을 때
    int result=0;
    for(int i=0; i<4; i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<0 || nx<0 || ny>=board.size() || nx>=board[0].size()) continue;
        if(board[ny][nx]==0) continue;
        board[y][x]=0;
        int val = dfs(board, next, {ny, nx})+1;
        board[y][x]=1;
        
        if(!(val%2) && !(result%2)) result=max(result, val);
        else if(val%2 && result%2) result=min(result, val);
        else if(val%2 && !(result%2)) result=val; 
    }
    return result;
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer=dfs(board, aloc, bloc);
    return answer;
}