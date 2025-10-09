#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long timeTable[360000+5]; 

int toSec(string t){
    return stoi(t.substr(0,2))*3600 + stoi(t.substr(3,2))*60 + stoi(t.substr(6,2));
}
string toStr(int t){
    int h = t/3600; t%=3600;
    int m = t/60; t%=60;
    int s = t;
    
    string answer=""; 
    if(to_string(h).length()<2) answer+=to_string(0); 
    answer+=to_string(h); 
    answer+=":"; 
    if(to_string(m).length()<2) answer+=to_string(0); 
    answer+=to_string(m); 
    answer+=":"; 
    if(to_string(s).length()<2) answer+=to_string(0); 
    answer+=to_string(s);
    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int playSec = toSec(play_time);
    int advSec  = toSec(adv_time);

    
    for(auto &log: logs){
        int start = toSec(log.substr(0,8));
        int end   = toSec(log.substr(9,8));
        timeTable[start]++; 
        timeTable[end]--;   
    }
    
    for(int i=1;i<=playSec;i++) timeTable[i]+=timeTable[i-1]; //구간 표시
    for(int i=1;i<=playSec;i++) timeTable[i]+=timeTable[i-1]; //누적합
    
    //초기값 : 0초부터 시작할 때
    long long maxView = timeTable[advSec-1];
    int startTime = 0; 
    //1초부터 계산
    for(int i=0; i+advSec<=playSec; i++){
        long long cur = timeTable[i+advSec]-timeTable[i];
        if(cur > maxView){
            maxView = cur;
            startTime = i+1;
        }
    }

    return toStr(startTime);
}