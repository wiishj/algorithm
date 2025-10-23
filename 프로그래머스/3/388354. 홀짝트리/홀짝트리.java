import java.util.*;
class Tree{
    private int cntOdd;
    private int cntEven;
    private int cntReverseOdd;
    private int cntReverseEven;
    
    public void setNode(int root, int child){
        if(root%2==1 && child%2==1) cntOdd++;
        else if(root%2==1 && child%2==0) cntReverseOdd++;
        else if(root%2==0 && child%2==1) cntReverseEven++;
        else if(root%2==0 && child%2==0) cntEven++;
    }
    public boolean getTree(){
        if((cntOdd==1 && cntEven==0) || (cntEven==1 && cntOdd==0)) return true;
        return false;
    }
    public boolean getReverseTree(){
        if((cntReverseOdd==1 && cntReverseEven==0) || (cntReverseEven==1 && cntReverseOdd==0)) return true;
        return false;
    }
}
class Solution {
    private Set<Integer> visited = new HashSet();
    private Map<Integer, List<Integer>> adj = new HashMap();
    private int[] answer = new int[2];
    public int[] solution(int[] nodes, int[][] edges) {
        for(int node:nodes) adj.put(node, new ArrayList<Integer>());
        for(int[] edge:edges){
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        
        for(int node:nodes){
            if(visited.contains(node)) continue;
            visited.add(node);
            Tree tree = new Tree();
            dfs(node, tree);
            if(tree.getTree()) answer[0]++;
            if(tree.getReverseTree()) answer[1]++;
        }
        return answer;
    }
    private void dfs(int node, Tree tree){
        tree.setNode(node, adj.get(node).size());
        for(int child:adj.get(node)){
            if(visited.contains(child)) continue;
            visited.add(child);
            dfs(child, tree);
        }
    }
}