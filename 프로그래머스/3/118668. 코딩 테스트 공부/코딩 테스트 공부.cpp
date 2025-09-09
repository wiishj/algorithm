#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp=0, max_cop=0;
    for(auto val:problems){
        max_alp=max(max_alp, val[0]);
        max_cop=max(max_cop, val[1]);
    }
    alp=min(alp, max_alp);
    cop=min(cop, max_cop);
    vector<vector<int>> dp(max_alp+1, vector<int>(max_cop+1, INT_MAX));
    dp[alp][cop]=0;
    for(int i=alp; i<=max_alp; i++){
        for(int j=cop; j<=max_cop; j++){
            if(i+1<=max_alp) dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
            if(j+1<=max_cop) dp[i][j+1]=min(dp[i][j+1], dp[i][j]+1);
            for(auto p:problems){
                if(i>=p[0] && j>=p[1] ){
                    int ni=min(i+p[2], max_alp), nj=min(j+p[3], max_cop);
                    dp[ni][nj]=min(dp[ni][nj], dp[i][j]+p[4]);
                }
            }
        }
    }
    return dp[max_alp][max_cop];
}
