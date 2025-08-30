#include <iostream>
#include <string>
#include <vector>

using namespace std;
int m, n;
int percent[4] = {10, 20, 30, 40};
vector<int> result;
int plus_num=0, cost=0;

void calculate(int cnt, vector<vector<int>> users, vector<int> emoticons){
    if(cnt==m){
        int tmp=0;
        
        int cur_plus=0, cur_cost=0;
        for(int i=0; i<n; i++){
            int tmp_cost=0;
            for(int j=0; j<m; j++){
                if(result[j]>=users[i][0]){
                    tmp_cost+=(emoticons[j]*(100-result[j])/100);
                }
            }
            if(tmp_cost>=users[i][1]){
                cur_plus++;
            }else{
                cur_cost+=tmp_cost;
            }
        }
        if(cur_plus>plus_num){
            plus_num=cur_plus;
            cost=cur_cost;
        }else if(cur_plus==plus_num){
            cost=max(cost, cur_cost);
        }
        return;
    }
    for(int i=0; i<4; i++){
        result.push_back(percent[i]);
        calculate(cnt+1, users, emoticons);
        result.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    n=users.size(); m=emoticons.size();
    calculate(0, users, emoticons);
    answer.push_back(plus_num);
    answer.push_back(cost);
    return answer;
}