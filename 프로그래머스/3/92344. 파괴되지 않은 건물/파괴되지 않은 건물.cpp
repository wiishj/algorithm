#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
0 0 0 0 0
2 2 0 0 0
2 2 0 0 0
0 0 0 0 0

*/
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> tmp(board.size(), vector<int>(board[0].size(), 0));
    for(vector<int> s : skill){
        int r1=s[1], c1=s[2], r2=s[3], c2=s[4], degree=s[5];
        if(s[0]==1){ //적
            tmp[r1][c1]-=degree;
            if(c2!=board[0].size()-1) tmp[r1][c2+1]+=degree;
            if(r2!=board.size()-1) {
                tmp[r2+1][c1]+=degree;
                if(c2!=board[0].size()-1) tmp[r2+1][c2+1]-=degree;
            }
            
        }else{ //아군
            tmp[r1][c1]+=degree;
            if(c2!=board[0].size()-1) tmp[r1][c2+1]-=degree;
            if(r2!=board.size()-1) {
                tmp[r2+1][c1]-=degree;
                if(c2!=board[0].size()-1) tmp[r2+1][c2+1]+=degree;
            }
        }
    }
    
    //가로더하기
    for(int i=0; i<tmp.size(); i++){
        for(int j=1; j<tmp[0].size(); j++){
            tmp[i][j]+=tmp[i][j-1];
        }
    }
    //세로더하기
    for(int i=1; i<tmp.size(); i++){
        for(int j=0; j<tmp[0].size(); j++){
            tmp[i][j]+=tmp[i-1][j];
        }
    }
   
    //답 구하기
    for(int i=0; i<tmp.size(); i++){
        for(int j=0; j<tmp[0].size(); j++){
            if(board[i][j]+tmp[i][j]>0) answer++;
        }
    }
    return answer;
}