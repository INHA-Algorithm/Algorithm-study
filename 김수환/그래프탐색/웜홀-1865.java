import java.io.*;
import java.util.*;

public class Main {

    public static final int INF = 5000000;
    public static int tc;
    public static BufferedReader br;
    public static StringTokenizer st;
    public static int n, m, w;
    public static int[][] graph;

    public static void init() throws IOException {

        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        graph = new int[n + 1][n + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = i == j ? 0 : INF;
            }
        }

        int s, e, t;

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken()) - 1;
            e = Integer.parseInt(st.nextToken()) - 1;
            t = Integer.parseInt(st.nextToken());
            if (graph[s][e] > t) {
                graph[s][e] = t;
                graph[e][s] = t;
            }
        }
        for (int i = 0; i < w; i++) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken()) - 1;
            e = Integer.parseInt(st.nextToken( )) - 1;
            t = Integer.parseInt(st.nextToken());
            if (graph[s][e] > -t) {
                graph[s][e] = -t;
            }
        }
    }

    public static void solve() {
        for (int i = 0; i < n; i++) {
            for (int src = 0; src < n; src++) {
                for (int dst = 0; dst < n; dst++) {
                    int og = graph[src][dst];
                    int mz = graph[src][i] + graph[i][dst];
                    if (og > mz) {
                        graph[src][dst] = mz;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (graph[i][i] < 0) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        tc = Integer.parseInt(br.readLine());

        while ((tc--) > 0) {
            init();
            solve();
        }
    }
}
