#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
/*
dp[cur_alp][cur_cop][target_alp][target_cop]=cost
=min(problems에서 온 값, alp_cost-초기alp + cop_cost-초기cop)
dp[0][3]=3
dp[2][1]=2
dp[2][4]=min(6, dp[0][3]+2)
dp[4][2]=4
dp[6][3]=6 
dp[4][5]=min(9, dp[2][4]+2)
dp[0][0][10][11]
*/
int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = 0, max_cop = 0;
    for (auto &p : problems) {
        max_alp = max(max_alp, p[0]);
        max_cop = max(max_cop, p[1]);
    }
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);

    vector<vector<int>> dp(max_alp+2, vector<int>(max_cop+2, INT_MAX));
    dp[alp][cop] = 0;

    for (int i = alp; i <= max_alp; i++) {
        for (int j = cop; j <= max_cop; j++) {
            if (i+1 <= max_alp)
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1); // 알고력 1 증가
            if (j+1 <= max_cop)
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1); // 코딩력 1 증가

            for (auto &p : problems) {
                if (i >= p[0] && j >= p[1]) {
                    int ni = min(max_alp, i + p[2]);
                    int nj = min(max_cop, j + p[3]);
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + p[4]);
                }
            }
        }
    }
    return dp[max_alp][max_cop];
}
