#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int lo=1, hi=1e5, sz=diffs.size();
    while(lo<=hi){
        int mid=(lo+hi)/2;
        ll t=times[0];
        //시간 계산
        for(int i=1; i<sz; i++){
            if(diffs[i]<=mid){
                t+=times[i];
            }else{
                t+=(diffs[i]-mid)*(times[i]+times[i-1]);
                t+=times[i];
            }
        }
        //cout<<mid<<' '<<t<<'\n';
        //조건 확인
        if(t<=limit){
            answer=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
    
        }
    }
    return answer;
}