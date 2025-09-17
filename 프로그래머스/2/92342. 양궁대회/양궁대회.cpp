#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> info;
vector<int> answer;
int max_diff=0;
void dfs(int cnt, int cur_score, int ryan, int apeach, vector<int> ryan_info){
    if(cur_score<0){ // 탈출조건
        //cout<<ryan<<' '<<apeach<<'\n';
        
        if(ryan>apeach && max_diff<=ryan-apeach){
            if(cnt) ryan_info[10]=cnt;
            if(max_diff<ryan-apeach){
                max_diff=ryan-apeach;
                answer=ryan_info;    
            }else{
                for(int i=10; i>=0; i--){
                    if(ryan_info[i] || answer[i]){
                        if(ryan_info[i] && answer[i]){
                            if(answer[i]<ryan_info[i]) answer=ryan_info;
                        }else if(ryan_info[i]){
                            answer=ryan_info;
                        }
                        break;   
                    }
                }
            }
            
        }
        return;
    }
    int idx=10-cur_score;
    //ryan이 현재 점수 따는 경우
    if(info[idx]+1<=cnt){
        ryan_info[idx]=info[idx]+1;
        dfs(cnt-info[idx]-1, cur_score-1, ryan+cur_score, apeach, ryan_info);    
    }
    
    //ryan이 현재 점수 안 따는 경우
    ryan_info[idx]=0;
    if(info[idx]) apeach+=cur_score;
    dfs(cnt, cur_score-1, ryan, apeach, ryan_info);
}
vector<int> solution(int n, vector<int> info) {
    ::info=info;
    vector<int> ryan_info(11, 0);
    dfs(n, 10, 0, 0, ryan_info);
    if(answer.empty()) answer.push_back(-1);
    return answer;
}