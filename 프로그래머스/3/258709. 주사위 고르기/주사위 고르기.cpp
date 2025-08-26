#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> visited(11);
vector<vector<int>> dice_copy;
int row, col;
int win_max=0;
vector<int> answer;
vector<int> selectA;
vector<int> selectB;
vector<int> combinationA;
vector<int> combinationB;

void calculate_combinationA(int num, int cnt){
    if(cnt==row/2){
        combinationA.push_back(num);
        return;
    }
    for(int i=0; i<col; i++){
        calculate_combinationA(num+dice_copy[selectA[cnt]][i], cnt+1);
    }
}
void calculate_combinationB(int num, int cnt){
    if(cnt==row/2){
        combinationB.push_back(num);
        return;
    }
    for(int i=0; i<col; i++){
        calculate_combinationB(num+dice_copy[selectB[cnt]][i], cnt+1);
    }
}

void calculate_win_rate(){
    selectA.clear(); selectB.clear();
    combinationA.clear(); combinationB.clear();
    for(int i=0; i<row; i++){
        if(visited[i]) selectA.push_back(i);
        else selectB.push_back(i);
    }
    
    calculate_combinationA(0,0);
    calculate_combinationB(0,0);
    int win_rate=0;
    int cnt_com=combinationA.size();
    for(int i=0; i<cnt_com; i++){
        for(int j=0; j<cnt_com; j++){
            if(combinationA[i]>combinationB[j]) win_rate++;
        }
    }
    if(win_rate>win_max){
        win_max=win_rate;
        answer.clear();
        for(int i=0; i<selectA.size(); i++){
            answer.push_back(selectA[i]+1);
        }
    }
    return;
}

void select(int cnt, int last_num){
    if(cnt==row/2){
        calculate_win_rate();
        return;
    }
    for(int i=last_num; i<row; i++){
        if(visited[i]) continue;
       
        visited[i]=1;
        select(cnt+1, i);
        visited[i]=0;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    dice_copy=dice;
    row=dice.size(), col=dice[0].size();
    
    select(0, 0);
    
    return answer;
}