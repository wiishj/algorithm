#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;
    }
};//가중치에 대해 오름차순

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> bool_summits(n+1, false);
    vector<bool> bool_gates(n+1, false);
    for(int i=0; i<paths.size(); i++){
        int a=paths[i][0];
        int b=paths[i][1];
        int w=paths[i][2];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    for(auto val:gates){
        bool_gates[val]=true;
    }
    for(auto val:summits){
        bool_summits[val]=true;
    }
 
    //다익스트라
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    vector<int> dist(n+1, INT_MAX);
    for(auto start:gates){
        pq.push({start, 0});
        dist[start]=0;
    }
    while(!pq.empty()){
        int to=pq.top().first;
        int weight=pq.top().second;
        pq.pop();
        if(dist[to]<weight || bool_summits[to]) continue;
        for(auto val:adj[to]){
            
            int new_weight=max(weight,val.second);
            if(dist[val.first]>new_weight){
                dist[val.first]=new_weight;
                pq.push({val.first, new_weight});
            }
        }
    }
    sort(summits.begin(), summits.end());
        for(int summit:summits){
            if(dist[summit]==INT_MAX) continue;
            int min_intensity=dist[summit];
            if(answer.empty() || answer[1]>min_intensity){
                answer={summit, min_intensity};
        }
    }
    
    return answer;
}