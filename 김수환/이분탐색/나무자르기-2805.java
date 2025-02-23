import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader br;
    public static int n, m;
    public static List<Integer> trees ;
    public static long mn = Long.MAX_VALUE;
    public static long mx;

    public static long count(long h) {
        long cnt = 0;
        for (int t : trees) {
            if (h <= t)
                cnt += (t - h);
        }
        return cnt;
    }

    public static void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        trees = trees = new ArrayList<>();
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        while (n-- > 0) {
            int w = Integer.parseInt(st.nextToken());
            trees.add(w);
            mn = Math.min(mn, w);
            mx = Math.max(mx, w);
        }
    }

    public static void solve() {
        long s = 0;
        long e = mx + 1;
        long mid;
        long ans = 0;

        while (s < e) {
            mid = (s + e) / 2;
            if (s == mid || e == mid) {
                ans = mid;
                break;
            }
            long cnt = count(mid);
            if (cnt == m)
                ans = Math.max(mid, ans);

            if (cnt >= m) s = mid;
            else e = mid;
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
