#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string, vector<int>> map;

void insert(int mask, string key[4], int score){
    /*
    mask 몇
    key의 i번째 정보를 쓸지 말지 결정
    0이면 정보쓰기 1이면 -
    2*2*2*2 가지의 경우의 수
    */
    string s="";
    for(int i=0; i<4; i++){
        s+=(mask & (1<<i))?string("-"):key[i];
    }
    map[s].push_back(score);
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string key[4], tmp;
    int score;
    
    for(auto& in: info){
        istringstream iss(in);
        iss>>key[0]>>key[1]>>key[2]>>key[3]>>score;
        for(int i=0; i<16; i++) insert(i, key, score);
    }
    for(auto& m:map) sort(m.second.begin(), m.second.end());//ascending
    for(auto& q:query){
        int ans=0;
        string s;
        istringstream iss(q);
        iss>>key[0]>>tmp>>key[1]>>tmp>>key[2]>>tmp>>key[3]>>score;
        for(int i=0; i<4; i++) s+=key[i];
        
        ans+=(map[s].end()-lower_bound(map[s].begin(), map[s].end(), score));
        answer.push_back(ans);
    }
    
    
    
    return answer;
}