import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br;
    static int n;
    static int[][] paper;
    static boolean[][] visit;
    static int[] ans;

    public static void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        paper = new int[n][n];
        visit = new boolean[n][n];
        ans = new int[3];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static boolean chk(int r, int c, int l, int flag) {
        for (int i = r; i < l + r; i++) {
            for (int j = c; j < l + c; j++) {
                if (paper[i][j] != flag) {
                    return false;
                }
            }
        }

        return true;
    }

    public static void dfs(int r, int c, int l) {
        int lbl = paper[r][c];
        if (chk(r, c, l, lbl)) {
            ans[lbl + 1]++;
            visit[r][c] = true;
            return;
        }
        for (int i = r; i < r + l; i += l / 3) {
            for (int j = c; j < c + l; j += l / 3) {
                if (visit[i][j]) {
                    continue;
                }
                dfs(i, j, l / 3);
            }
        }
    }

    public static void solve() {
        dfs(0, 0, n);
        Arrays.stream(ans).forEach(System.out::println);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
