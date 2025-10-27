import java.util.*;


class Solution {
    
    static class Node implements Comparable<Node>{
        int index;
        int weight;
        Node(int index, int weight){
            this.index = index;
            this.weight=weight;
        }
        @Override
        public int compareTo(Node o){
            return this.weight-o.weight;
        }
    }
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        List<List<Node>> adj = new ArrayList<>();
        for(int i=0; i<=N; i++) adj.add(new ArrayList<>());
        for(int[] r: road){
            int a=r[0], b=r[1], c=r[2];
            adj.get(a).add(new Node(b, c));
            adj.get(b).add(new Node(a, c));
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int dist[] = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        pq.offer(new Node(1, 0));
    
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            int to = cur.index;
            int weight = cur.weight;
            
            if(dist[to]<=weight) continue;
            System.out.println(to+" "+weight);
            dist[to]=weight;
            for(Node node:adj.get(to)){
                pq.offer(new Node(node.index, weight + node.weight));
            }
        }
        for(int i=1; i<=N; i++){
            if(dist[i]<=K) {
                answer++;
                System.out.println(i);
            }
        }
        return answer;
    }
}