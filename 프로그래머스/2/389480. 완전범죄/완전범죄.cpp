#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

vector<vector<int>> dp(45, vector<int>(130, 150));
int solution(vector<vector<int>> info, int n, int m) {
    dp[0][0]=0;
    int sz=info.size();
    for(int i=1; i<=sz; i++){
        int a=info[i-1][0];
        int b=info[i-1][1];
        for(int j=0; j<m; j++){
            //a가 훔침
            dp[i][j]=min(dp[i][j], dp[i-1][j]+a);
            //b가 훔침
            if(j+b<m) dp[i][j+b]=min(dp[i][j+b], dp[i-1][j]);
        }
    }
    int answer=INT_MAX;
    for(int j=0; j<m; j++) answer=min(answer, dp[sz][j]);
    return answer>=n?-1:answer;
}