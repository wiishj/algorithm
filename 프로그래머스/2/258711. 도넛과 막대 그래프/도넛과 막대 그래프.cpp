#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
/*
순환O
각 정점에서 간선이 1개 -> 도넛
간선이 2개 -> 8자
순환X -> 막대
*/
vector<vector<int>> adj(1000001);
vector<int> indegree(1000001);
vector<int> outdegree(1000001);
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int max_val=1;
    for(int i=0; i<edges.size(); i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        max_val=max(a, max_val);
        max_val=max(b,max_val); 
        outdegree[a]++;
        indegree[b]++;
    }
    //정점번호 찾기
    int end_point=0;
    for(int i=1; i<=max_val; i++){
        if(outdegree[i]>=2 && indegree[i]==0){
            end_point=i;
            break;
        }
    }
    
    //그래프 개수 찾기

    stack<int> s;
    vector<int> visited(max_val+1);
    
    int stick=0, eight=0, donut=0;
    
    for(auto start:adj[end_point]){
        s.push(start);
        visited[start]=1;
        int edge=0;
        int node=1;
        while(!s.empty()){
            int cur=s.top();
            s.pop();
            
            for(auto val:adj[cur]){
                edge++;
                if(visited[val]) continue;
                node++;
                s.push(val);
                visited[val]=1;
                }
        }
        if(edge==node) donut++;
        else if(edge==node+1) eight++;
        else if(edge+1==node) stick++;
     
    }
    
    answer.push_back(end_point);
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    return answer;
}