#include <string>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = INT_MAX;
    int len1=queue1.size(), len2=queue2.size();
    vector<int> q;
    long long target=0;
    for(int i:queue1){
        target+=i;
        q.push_back(i);
    }
    for(int i:queue2){
        target+=i;
        q.push_back(i);
    }
    target/=2;
    int lo=0, hi=0;
    long long val=q[0];
    
    while(lo<=hi && hi<len1+len2){
        //cout<<lo<<' '<<hi<<' '<<val<<'\n';
        
        if(target==val){
            int cnt=0;
            if(hi>=len1){
                if(lo>=len1){ //lo, hi가 queue2
                    cnt+=(hi+1);
                    cnt+=lo-len1;
                }else{ //hi는 queue2, lo는 queue1
                    cnt+=lo;
                    cnt+=(hi-len1+1);
                }
            }else{ //hi가 queue1, lo도 queue1
                if(hi==len1-1){
                    cnt+=lo;
                }else{
                    cnt+=len2;
                    cnt+=(hi-lo+1);    
                }
                
            }
            //cout<<cnt<<'\n';
            answer=min(cnt, answer);
            val-=q[lo];
            lo++;
            hi++;
            if(hi==len1+len2) break;
            val+=q[hi];
        }else if(target>val){
            hi++;
            if(hi==len1+len2) break;
            val+=q[hi]; 
        }else{
            val-=q[lo];
            lo++;
        }   
    }
    if(answer==INT_MAX) answer=-1;
    return answer;
}