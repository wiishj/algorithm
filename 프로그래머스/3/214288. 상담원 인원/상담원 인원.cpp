#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
/*
70 90
0
0 0
*/
vector<vector<int>> candidate;
int ss(vector<vector<int>> reqs, vector<priority_queue<int, vector<int>, greater<>>> list){
    int ans=0;
    for(auto req:reqs){
        int s=req[0]; int e=req[1]; int ty=req[2];
        int el=list[ty].top(); list[ty].pop();
        
        if(el>s){
            ans+=(el-s);
            
            list[ty].push(el+e);
        }else{
            list[ty].push(s+e);
        }
        
     
    }
    return ans;
}
void cal_combi(vector<int> combi, int type, int cnt, int k){
    if(type>k){
        if(cnt==0) candidate.push_back(combi);
        return;
    }
    for(int i=0; i<=cnt; i++){
        combi[type]+=i;
        cal_combi(combi, type+1, cnt-i, k);
        combi[type]-=i;
    }
}


int solution(int k, int n, vector<vector<int>> reqs) {
    vector<int> combi(k+1, 1);
    n-=k;
    cal_combi(combi, 1, n, k);
    int answer = INT_MAX;
    for(auto c:candidate){
        vector<priority_queue<int, vector<int>, greater<>>> list(k+1);
        for(int i=1; i<=k; i++){
            int sz=c[i];
            for(int j=0; j<sz; j++) list[i].push(0);
        }
        answer=min(answer, ss(reqs, list));
        
    }
    
    return answer;
}