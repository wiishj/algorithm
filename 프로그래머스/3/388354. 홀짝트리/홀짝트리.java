import java.util.*;
class Visiter{
    private int oddNode; // 홀수 -> 역홀
    private int evenNode; // 짝수 -> 역짝
    private int inverseOddNode; //역홀 -> 홀수
    private int inverseEvenNode; // 역짝 -> 짝수
    
    public void setNode(int root, int num){
        int a = root%2;
        int b = num%2;
        if(a==0 && b==0){
            evenNode++;
        }
        else if(a!=0 && b!=0){
            oddNode++;
        }
        else if(a!=0 && b==0){
            inverseOddNode++;
        }
        else inverseEvenNode++;
    }
    
    public int getOddEvenTreeCnt(){
        if((oddNode==1 && evenNode==0) || (oddNode==0 && evenNode==1))
            return 1;
        return 0;
    }
    
    public int getInverseTreeCnt(){
        if((inverseOddNode==1 && inverseEvenNode==0) || 
           (inverseOddNode==0 && inverseEvenNode==1))
            return 1;
        return 0;
    }
}

class Solution {
    private int[] answer = new int[2];
    private Set<Integer> visited = new HashSet();
    private Map<Integer, List<Integer>> tree = new HashMap();
    
    public int[] solution(int[] nodes, int[][] edges) {
        
        for(int node : nodes){
            tree.put(node, new ArrayList());
        }
        
        for(int[] edge : edges){
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }
        
        for(int node : nodes){
            if(visited.contains(node)) continue;
            visited.add(node);
            Visiter visiter = new Visiter();
            dfs(node, visiter);
            answer[0] += visiter.getOddEvenTreeCnt();
            answer[1] += visiter.getInverseTreeCnt();
        }
        
        return answer;
    }
    
    private void dfs(int now, Visiter visiter){
        int cnt = 0;
        for(int next : tree.get(now)){
            cnt++;
            if(visited.contains(next)) continue;
            visited.add(next);
            dfs(next, visiter);
        }
        
        visiter.setNode(now, cnt);
    }
}