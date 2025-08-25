#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int lo=1;
    int hi=*max_element(stones.begin(), stones.end())+1;
    
    while(lo<=hi){
        int mid=(lo+hi)/2;
        int len=0;
        bool flag=false;
        for(int i=0; i<stones.size(); i++){
            if(stones[i]<mid){
                len++;
            }else{
                len=0;
            }
            //cout<<mid<<' '<<i<<' '<<len<<'\n';
            if(len>=k) {
                flag=true;
                break;
            }
        }
        
        //연속하는 mid미만의 수가 k이하면 건널 수 있다
        //저장 후 더 큰수에 대해 탐색
        //초과면 못건넌다 더 작은수에 대해 탐색
        if(flag){
            hi=mid-1;
        }else{
            answer=max(mid, answer);
            lo=mid+1;
        }
    }
    return answer;
}