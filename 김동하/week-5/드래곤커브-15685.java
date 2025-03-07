import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int N;
    public static boolean isCurve[][] = new boolean[101][101];
    public static int dx[] = {1,0,-1,0};
    public static int dy[] = {0,-1,0,1};
    public static class Node{
        int x,y;
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void makeCurve(int x, int y, int d, int g) {
        List<Node> list = new ArrayList<>();
        list.add(new Node(x,y));
        x = x + dx[d];
        y = y + dy[d];
        list.add(new Node(x,y));
        for(int i = 0; i < g; i++) {
            int lSize = list.size();
            for(int j = lSize - 2; j >= 0; j--) {
                Node n = list.get(j);
                int tx = x - n.x;
                int ty = y - n.y;
                int nx = x + ty;
                int ny = y - tx;
                list.add(new Node(nx,ny));
            }
            Node tmp = list.get(list.size() - 1);
            x = tmp.x;
            y = tmp.y;
        }
        for(Node n : list) {
            isCurve[n.x][n.y] = true;
        }
    }

    public static void init() throws IOException{
        N = Integer.parseInt(br.readLine());
        int[] in;
        for(int i = 0; i < N; i++) {
            in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int x = in[0];
            int y = in[1];
            int d = in[2];
            int g = in[3];
            makeCurve(x, y, d, g);
        }

    }

    public static boolean isRect(int x, int y) {
        int tx[] = {1,0,1};
        int ty[] = {0,1,1};
        for(int i  = 0; i < 3; i++) {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if(!isCurve[nx][ny]) return false;
        }
        return true;
    }

    public static void solution() throws IOException{
        init();
        int cnt = 0;
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                if(isCurve[i][j]) {
                    if(isRect(i, j)) cnt++;
                }
            }
        }
        System.out.println(cnt);
    }

    public static void main(String[] args) throws IOException {
        solution();
    }

}
