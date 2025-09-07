#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int len1=queue1.size(), len2=queue2.size();
    vector<int> q;
    long long target=0;
    long long sum1=0, sum2=0;
    for(int i:queue1){
        sum1+=i;
    }
    for(int i:queue2){
       sum2+=i;
    }
 
    target/=2;
    int cnt=0, idx1=0, idx2=0;
    while(sum1!=sum2 && cnt<=len1*2+len2*2){
        //cout<<idx1<<' '<<idx2<<'\n';
        cnt++;
        if(sum1<sum2){
            sum2-=queue2[idx2];
            sum1+=queue2[idx2];
            queue1.push_back(queue2[idx2++]);
        }else{ //sum1>sum2
            sum1-=queue1[idx1];
            sum2+=queue1[idx1];
            queue2.push_back(queue1[idx1++]);
        }
    }
    if(sum1==sum2) return cnt;
  
    return -1;
}