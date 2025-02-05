import java.util.Scanner;


public class Main {
    public static int n, m;
    public static boolean[] visit;
    public static int[] ans;

    public static void dfs(int cnt) {
        if (cnt == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(ans[i] + " ");

            }System.out.println();
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                ans[cnt] = i;
                dfs(cnt + 1);
                visit[i] = false;
            }
        }
    }

    public static void solve() {
        dfs(0);
    }

    public static void init() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        ans = new int[m + 1];
        visit = new boolean[n+1];
    }

    public static void main(String[] args) {
        init();
        solve();
    }
}
