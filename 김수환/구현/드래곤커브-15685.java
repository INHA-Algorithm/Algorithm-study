import java.io.*;
import java.util.*;

public class Main {
    static int[][] graph = new int[101][101];
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, -1, 0, 1};
    static int num, cnt;
    static List<Curve> curves = new ArrayList<>();

    static class Curve {
        int x, y, d, g;

        Curve(int x, int y, int d, int g) {
            this.x = x;
            this.y = y;
            this.d = d;
            this.g = g;
        }
    }

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        num = Integer.parseInt(br.readLine());

        for (int i = 0; i < num; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());

            curves.add(new Curve(x, y, d, g));
        }
    }

    public static void solve() {
        for (Curve curve : curves) {
            draw(curve);
        }

        countAnswer();

        System.out.println(cnt);
    }

    public static void draw(Curve c) {
        List<Integer> dir = new ArrayList<>();
        int x = c.x;
        int y = c.y;
        int d = c.d;
        int g = c.g;

        graph[x][y] = 1;

        x += dx[d];
        y += dy[d];
        graph[x][y] = 1;
        dir.add(d);

        for (int i = 0; i < g; i++) {
            int size = dir.size();
            for (int j = size - 1; j >= 0; j--) {
                int newDirection = (dir.get(j) + 1) % 4;
                x += dx[newDirection];
                y += dy[newDirection];
                graph[x][y] = 1;
                dir.add(newDirection);
            }
        }
    }

    public static void countAnswer() {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (graph[i][j] == 1 && graph[i][j + 1] == 1 && graph[i + 1][j] == 1 && graph[i + 1][j + 1] == 1) {
                    cnt++;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        init();
        solve();
    }
}
