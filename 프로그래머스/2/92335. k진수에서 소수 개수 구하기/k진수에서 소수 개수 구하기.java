import java.util.*;

class Solution {
    public int solution(int n, int k) {
        String knum="";
        while(n>0){
            knum=Integer.toString(n%k)+knum;
            n/=k;
        }
        int answer = 0;
        String[] arr = knum.split("0");     
        for(String s: arr){
            if(s.length()==0) continue;
            //System.out.println(s);
            if(isPrime(Long.parseLong(s))) answer++;
        }
        return answer;
    }
    private boolean isPrime(long num){
        if(num==1) return false;
        if(num==2) return true;
        for(long i=2; i*i<=num ; i++){
            if(num%i==0) return false;
        }
        return true;
    }
}