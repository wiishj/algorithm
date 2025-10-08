#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long timeTable[360000+5]; // 최대 99:59:59 = 3600*100 - 1 = 359999초

int toSec(string t){
    return stoi(t.substr(0,2))*3600 + stoi(t.substr(3,2))*60 + stoi(t.substr(6,2));
}
string toStr(int t){
    int h = t/3600; t%=3600;
    int m = t/60; t%=60;
    int s = t;
    char buf[10];
    sprintf(buf,"%02d:%02d:%02d",h,m,s);
    return string(buf);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int playSec = toSec(play_time);
    int advSec  = toSec(adv_time);

    // 1. 로그 처리 (시청자수 시작+1, 종료-1)
    for(auto &log: logs){
        int start = toSec(log.substr(0,8));
        int end   = toSec(log.substr(9,8));
        timeTable[start]++; 
        timeTable[end]--;   
    }

    // 2. 동시 시청자수 계산
    for(int i=1;i<=playSec;i++) timeTable[i]+=timeTable[i-1];

    // 3. 누적 시청 시간 계산
    for(int i=1;i<=playSec;i++) timeTable[i]+=timeTable[i-1];

    // 4. 광고 구간에서 최대값 찾기 (슬라이딩 윈도우)
    long long maxView = timeTable[advSec-1];
    int startTime = 0;
    for(int i=advSec; i<=playSec; i++){
        long long cur = timeTable[i] - timeTable[i-advSec];
        if(cur > maxView){
            maxView = cur;
            startTime = i-advSec+1;
        }
    }

    return toStr(startTime);
}
