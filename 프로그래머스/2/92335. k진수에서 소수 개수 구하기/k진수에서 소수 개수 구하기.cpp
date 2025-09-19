#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> p;
bool isPrime(long long n){
    if(n==1) return false;
    for(long long i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}
int solution(int n, int k) {
  
    //k진수 만들기
    string knum="";
    while(n>0){
        knum = to_string(n%k) + knum;
        n/=k;
    }
    knum += '0';
    //0기준 쪼개기
    long long cur=0;
    int answer=0;
    for(char c:knum){
        if(c=='0'){
            if(cur>1 && isPrime(cur)) answer++;
            cur=0;
        }else{
            cur = cur*10 + (c-'0');
        }
    }
    return answer;
}