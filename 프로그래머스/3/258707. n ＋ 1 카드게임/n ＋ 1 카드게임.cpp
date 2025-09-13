#include <iostream>
#include <string>
#include <vector>

using namespace std;
int sz;
vector<int> cur(1000,0), candidate(1000,0);
bool promise(int coin){
    if(coin==0){
        for(int i=1; i<=sz/2; i++){
            if(cur[i]&&cur[sz+1-i]) {
                cur[i]=0;
                cur[sz+1-i]=0;
                return true;
            }
        }
        return false;
    }else if(coin==1){
        for(int i=1; i<=sz; i++){
            if(candidate[i]&&cur[sz+1-i]) {
                candidate[i]=0;
                cur[sz+1-i]=0;
                return true;
            }
        }
        return false;
    }else{ //coin==2
        for(int i=1; i<=sz; i++){
            if(candidate[i]&&candidate[sz+1-i]) {
                candidate[i]=0;
                candidate[sz+1-i]=0;
                return true;
            }
        }
        return false;
    }
}
int solution(int coin, vector<int> cards) {
    int answer = 1;
    candidate.clear();
    sz=cards.size();
    
    for(int i=0; i<sz/3; i++) cur[cards[i]]=1;
    for(int i=sz/3; i<sz; i+=2){
        // cout<<i<<' '<<idx<<' ';
        candidate[cards[i]]=1; candidate[cards[i+1]]=1;
        if(promise(0)){
            answer++;
            // cout<<0<<'\n';
        }else if(coin>=1 && promise(1)){
            // cout<<1<<' '<<idx<<'\n';
            answer++;
            coin--;
        }else if(coin>=2 && promise(2)){
            // cout<<2<<'\n';
            answer++;
            coin-=2;
        }else{
            break;
        }
    }
    return answer;
}