#include <string>
#include <vector>

using namespace std;
int timetable[25];
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for(int i=0; i<=23; i++){
        int server=players[i]/m;
        int cnt=server-timetable[i];
        if(cnt>0){
            answer+=cnt;
            for(int j=0; j<k; j++){
                if(i+j>=24) break;
                timetable[i+j]+=cnt;
            }
        }
    }
    
    return answer;
}