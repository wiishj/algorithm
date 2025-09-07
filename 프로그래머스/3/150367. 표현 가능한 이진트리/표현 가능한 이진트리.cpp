#include <iostream>
#include <string>
#include <vector>
#include <deque>
#define ll long long
using namespace std;
//0001000
//1110111
vector<int> answer;
bool flag = true;
bool dfs(deque<int> &dq, int start, int end){
    if(start == end){
        return dq[start] == 1;  // 리프: 1이면 true, 0이면 false
    }
    int mid = (start + end) / 2;
    bool left = dfs(dq, start, mid-1);
    bool right = dfs(dq, mid+1, end);
    
    if((left || right) && dq[mid] == 0) {
        flag = false; // 부모가 0인데 자식 중에 1 있음
    }
    return dq[mid] || left || right;
}

deque<int> make_binary_num(ll val){
    ll num=1, cnt=0;
    while(num<=val) {
        num*=2; //val 이하의 2의 제곱수
        cnt++; //num이 2의 몇제곱인지+1
    }
    num/=2; 
    ll len=0, tmp=1; //len : 포화 이진트리의 길이
    while(len<cnt){
        len+=tmp;
        tmp*=2;
    }
    
    deque<int> result;
    while(val>0){
        if(val>=num){
            result.push_back(1);
            val-=num;
        }else{
            result.push_back(0);
        }
        num/=2;
    }
    while(num){
        result.push_back(0);
        num/=2;
    }
    for(int i=0; i<len-cnt; i++) result.push_front(0);
    return result;
}
vector<int> solution(vector<ll> numbers) {
    
    for(ll val:numbers){
        deque<int> binary=make_binary_num(val);
   
        flag=true;
        dfs(binary, 0, binary.size()-1);
        if(flag) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}