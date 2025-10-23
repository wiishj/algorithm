import java.util.*;

class Solution {
    private int[] dx = {0, 0, 1, -1};
    private int[] dy = {1, -1, 0, 0};
    
    public int solution(String[] maps) {
        int row = maps.length;
        int col = maps[0].length();
        
        int sx = 0, sy = 0, lx = 0, ly = 0, ex = 0, ey = 0;
        
        // S, L, E 좌표 찾기
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                char ch = maps[i].charAt(j);
                if(ch == 'S') { sx = i; sy = j; }
                else if(ch == 'L') { lx = i; ly = j; }
                else if(ch == 'E') { ex = i; ey = j; }
            }
        }
        
        int dist1 = bfs(maps, sx, sy, lx, ly);
        if(dist1 == -1) return -1;
        
        int dist2 = bfs(maps, lx, ly, ex, ey);
        if(dist2 == -1) return -1;
        
        return dist1 + dist2;
    }
    
    private int bfs(String[] maps, int sx, int sy, int tx, int ty) {
        int row = maps.length;
        int col = maps[0].length();
        boolean[][] visited = new boolean[row][col];
        Queue<int[]> q = new ArrayDeque<>();
        
        q.offer(new int[]{sx, sy, 0});
        visited[sx][sy] = true;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1], dist = cur[2];
            
            if(x == tx && y == ty) return dist;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
                if(maps[nx].charAt(ny) == 'X' || visited[nx][ny]) continue;
                
                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny, dist + 1});
            }
        }
        return -1; // 목표에 도달 불가
    }
}
