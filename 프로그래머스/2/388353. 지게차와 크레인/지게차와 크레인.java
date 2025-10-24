import java.util.*;
class Solution {
    private int n;
    private int m;
    private int answer;
    private int[][] visited;
    private int[] dx = {0,0,-1,1};
    private int[] dy = {1,-1,0,0};
    
    public int solution(String[] storage, String[] requests) {
        n = storage.length;
        m = storage[0].length();
        visited = new int[n][m];
        answer = n*m;   
        for(String s : requests){
            char c = s.charAt(0);
            if(s.length()==2){
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(visited[i][j]==1) continue;
                        if(storage[i].charAt(j)==c){
                            visited[i][j]=1;
                            answer--;
                        }
                    }
                }
            }else{
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(visited[i][j]==1) continue;
                        if(storage[i].charAt(j)==c){
                            //System.out.println("******");
                            if(flag(i, j)){
                                //System.out.println(i+" "+j);
                                answer--;
                                visited[i][j]=-1;
                            }
                        }
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(visited[i][j]==-1) visited[i][j]=1;            
                }
            }
            //System.out.println(answer);
        }
        return answer;
    }
    private boolean flag(int row, int col){
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{row, col});
        int[][] check = new int[n][m]; check[row][col]=1;
        while(!q.isEmpty()){
            int[] cur = q.poll();
            int cx = cur[0], cy=cur[1];
            //System.out.println(cx+" "+cy);
            if(cx==0 || cy==0 || cx==(n-1) || cy==(m-1)) return true;
            for(int i=0; i<4; i++){
                int nx=cx+dx[i], ny=cy+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if(check[nx][ny]==1) continue;
                if(visited[nx][ny]!=1) continue;
                check[nx][ny]=1;
                q.offer(new int[]{nx, ny});
            }
        }
        return false;
    }
}