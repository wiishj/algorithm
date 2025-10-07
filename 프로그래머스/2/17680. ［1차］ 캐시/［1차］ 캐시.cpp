#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(vector<string> cache, string city){

    for(int i=0; i<cache.size(); i++){
        
        if(cache[i]==city){
            return i;
        }
    }
    return -1;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize==0) return cities.size()*5;
    vector<string> cache;
    for(auto city:cities){
        //소문자 변환
        for(int i=0; i<city.length(); i++){
            if(city[i]<97){
                city[i]=city[i]+32;
            }
        }
        int idx=find(cache, city);
        if(idx!=-1){
            answer++;
            cache.erase(cache.begin()+idx);
            cache.push_back(city);
        }else{
            answer+=5;
            if(cache.size()>=cacheSize) cache.erase(cache.begin());
            cache.push_back(city);
        }
    }
    return answer;
}