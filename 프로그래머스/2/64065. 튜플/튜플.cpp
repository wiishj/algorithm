#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a.size()<b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> map;
    vector<int> tmp;
    int idx=0;
    for(int i=1; i<s.length()-1; i++){
        char c = s[i];
        if(c=='{'){
            idx=i+1;
        }
        else if(c=='}'){
            tmp.push_back(stoi(s.substr(idx, i-idx)));
            map.push_back(tmp);
            tmp.clear();
            
        }else if(c==',' && s[i-1]!='}'){
         
            tmp.push_back(stoi(s.substr(idx, i-idx)));
            idx=i+1;
        }
    }
   
    sort(map.begin(), map.end(), cmp);
    answer.push_back(map[0][0]);
    for(int i=1; i<map.size(); i++){//i번째 튜플 채우기
        for(int j=0; j<map[i].size(); j++){ //집합의 i번째 요소 하나씩 돌기
            bool flag=false;
            for(int k=0; k<i; k++){ //0~i-1까지 중복 검사  
                if(map[i][j]==answer[k]){
                    flag=true;
                }
            }
            if(!flag){
                answer.push_back(map[i][j]);
                continue;
            }
        }
    }
    return answer;
}