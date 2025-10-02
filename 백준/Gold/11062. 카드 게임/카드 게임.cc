#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#define ll long long

using namespace std;

int n, t;
int dp[1001][1001];
void init() {
	for (int i = 0; i <= 50; i++) {
		for (int j = 0; j <= 50; j++) dp[i][j] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		init();
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		/*현재 유리한 걸 고르는게 아니라 과거까지 고려야해한다 -> 과거부터 먼저 설정*/
		bool gnuTurn = n % 2 ? true : false;//홀수면 근우핑이 마지막에 뽑음
		for (int gap = 0; gap < n; gap++) {
			for (int l = 0; l < n; l++) { //l~l+gap까지
				int r = l + gap;
				if (r >= n) continue;
				if (!gap) {
					dp[l][r] = gnuTurn?v[l]:0;
					continue;
				}
				if (gnuTurn) {
					dp[l][r] = max(v[l] + dp[l + 1][r], v[r] + dp[l][r - 1]);
				}
				else {
					dp[l][r] = min(dp[l + 1][r],dp[l][r - 1]);
				}
			}
			gnuTurn = !gnuTurn;
		}
		cout << dp[0][n - 1] << '\n';
	}
	
}