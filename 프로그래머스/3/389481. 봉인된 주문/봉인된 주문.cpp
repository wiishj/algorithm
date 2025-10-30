#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
/*
aa -> 26*1+1
ba -> 52+1
aaa -> 26*26+1
bbb -> 26*26+26*26+26+2
*/
bool cmp(string a, string b){
    if(a.length()!=b.length()) return a.length()<b.length();
    return a<b;
}
ll find_order(string str){
    int idx=str.length()-1;
    ll ans=0; 
    ll twenty_six=1;
    while(idx>=0){
        ans+=twenty_six*(str[idx]-'a'+1);
        idx--;
        twenty_six*=26;
    }
    return ans;
}

string find_string(ll n){
    string ans="";
    // cout<<twenty_six<<'\n';
    while(n>0){
        n--;
        int remainder=n%26;
        ans=(char)('a'+remainder)+ans;
        n/=26;
    }
    
    return ans;
    
}

string solution(ll n, vector<string> bans) {
    sort(bans.begin(), bans.end(), cmp);
    
    for(int i=0; i<bans.size(); i++){
        ll order=find_order(bans[i]);
        //cout<<order<<' '<<n<<'\n';
        if(order<=n) n++;
        else break;
    }
    
    //cout<<n<<'\n';
    string answer=find_string(n);
    return answer;
    // return "";
}