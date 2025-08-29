#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int delivery=0, pickup=0;
    
    for(int i=n-1; i>=0; i--){
        delivery-=deliveries[i];
        pickup-=pickups[i];
        int cnt=0;
        while(delivery<0 || pickup<0){
            delivery+=cap;
            pickup+=cap;
            cnt++;
        }
        answer+=(i+1)*cnt;
    }
    answer*=2;
    return answer;
}