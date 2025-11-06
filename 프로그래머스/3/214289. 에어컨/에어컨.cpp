#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
int dp[1001][60][60]; //i번째, 희망온도+10, 현재온도+10 = 최솟값
/*
현재 에어컨을 키면 다음 분에 온도가 변한다
*/
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer=INT_MAX; int sz=onboard.size();
    //init
    for(int i=0; i<sz; i++){
        for(int j=t1 ; j<=t2; j++){
            for(int k=-10; k<=40; k++){
                dp[i][j+10][k+10]=INT_MAX;
            }
        }
    }
    
    for(int j=t1 ; j<=t2; j++){
        dp[0][j+10][temperature+10]=0;
        //에어컨 키기
        if(j>temperature) dp[1][j+10][temperature+11]=a;
        else dp[1][j+10][temperature+9]=a;
        dp[1][j+10][temperature+10]=0;
        
    }
    for(int i=1; i<sz-1; i++){
        for(int j=t1 ; j<=t2; j++){//희망온도
            for(int k=-10; k<=40; k++){//현재온도
                if(dp[i][j+10][k+10]==INT_MAX) continue;
                if(onboard[i]==1 && (k<t1 || k>t2)) {
                    dp[i][j][k]=INT_MAX;
                    continue;
                }
                //에어컨 켜기
                if(j>k){
                    dp[i+1][j+10][k+11]=min(dp[i+1][j+10][k+11], dp[i][j+10][k+10]+a);
                }else if(j<k){
                    dp[i+1][j+10][k+9]=min(dp[i+1][j+10][k+9], dp[i][j+10][k+10]+a);
                }else{
                    dp[i+1][j+10][k+10]=min(dp[i+1][j+10][k+10], dp[i][j+10][k+10]+b);
                }
                //에어컨 끄기
                if(k>temperature){
                    dp[i+1][j+10][k+9]=min(dp[i+1][j+10][k+9], dp[i][j+10][k+10]);
                }else if(k<temperature){
                    dp[i+1][j+10][k+11]=min(dp[i+1][j+10][k+11], dp[i][j+10][k+10]);
                }else{
                    dp[i+1][j+10][k+10]=min(dp[i+1][j+10][k+10], dp[i][j+10][k+10]);
                }
                
            }
        }
    }
    for(int j=t1 ; j<=t2; j++){
        for(int k=-10; k<=40; k++){
            if(onboard[sz-1]==1 && (k<t1 || k>t2)) continue;
            answer=min(dp[sz-1][j+10][k+10],answer);
        }
    }
    // for(int i=0; i<sz; i++){
    //     for(int j=t1 ; j<=t2; j++){
    //         for(int k=-10; k<=40; k++){
    //             int val=dp[i][j+10][k+10];
    //             if(val==INT_MAX) cout<<"X ";
    //             else cout<<val<<' ';
    //         }
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }
    return answer;
}