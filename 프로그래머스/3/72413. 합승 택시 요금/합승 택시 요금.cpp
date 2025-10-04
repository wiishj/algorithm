#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
int map[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    //초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) {
            if(i==j) map[i][j]=0;
            else map[i][j]=INT_MAX;
        }
    }
    
    for(auto fare:fares){
        int x=fare[0], y=fare[1], cost=fare[2];
        map[x][y]=cost;
        map[y][x]=cost;
    }
    
    //플로이드-워셜
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(map[i][k]==INT_MAX || map[k][j]==INT_MAX) continue;
                map[i][j]=min(map[i][k]+map[k][j], map[i][j]);
            }
        }
    }
    
    answer=map[s][a]+map[s][b];
    for(int i=1; i<=n; i++){
        int val = map[s][i]+map[i][a]+map[i][b];
        answer=min(answer, val);
    }
    return answer;
}