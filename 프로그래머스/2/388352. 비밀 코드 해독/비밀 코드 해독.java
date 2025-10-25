import java.util.*;

class Solution {
    private List<int[]> combis = new ArrayList<>();
    
    public int solution(int n, int[][] q, int[] ans) {
        combi(1,n, new int[]{});
        
        for(int i=0; i<q.length; i++){
            List<int[]> tmp = new ArrayList<>(combis);
            for(int[] combi : tmp){
                if(promise(q[i], ans[i], combi)) continue;
                else combis.remove(combis.indexOf(combi));
            }
        }
        int answer = combis.size();
        return answer;
    }
    private void combi(int s, int n, int[] arr){
        if(arr.length==5){
            combis.add(arr);
            return;
        }
        if(5-arr.length>n-s+1) return;
        for(int i=s; i<=n; i++){
            int tmp[] = Arrays.copyOf(arr, arr.length+1);
            tmp[arr.length]=i;
            combi(i+1, n, tmp);
        }
    }
    private boolean promise(int[] query, int ans, int[] cur){
        int q_idx=0, cur_idx=0;
        int cnt=0;
        while(q_idx<5 && cur_idx<5){
            if(query[q_idx]==cur[cur_idx]){
                cnt++;
                q_idx++; cur_idx++;
            }else if(query[q_idx]<cur[cur_idx]){
                q_idx++;
            }else{
                cur_idx++;
            }
        }
        if(cnt==ans) return true;
        else return false;
    }
}