import static java.lang.Math.abs;

import java.util.Scanner;


public class Baekjoon {

    public static int n, m;
    public static int max;
    public static boolean[][] mem;
    public static int[] arr;

    public static int[] inputs;

    public static void init() {
        mem = new boolean[31][15001];
        arr = new int[31];

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            max += arr[i];
        }
        m = sc.nextInt();

        inputs = new int[m];
        for (int i = 0; i < m; i++) {
            inputs[i] = sc.nextInt();
        }
    }

    public static void dp(int idx, int val) {
        if (idx > n) {
            return;
        }
        if (mem[idx][val]) {
            return;
        }
        mem[idx][val] = true;

        dp(idx + 1, val);
        dp(idx + 1, val + arr[idx]);
        dp(idx + 1, abs(val - arr[idx]));
    }

    public static void solve() {
        dp(0, 0);

        for (int i = 0; i < m; i++) {
            if (inputs[i] > max) {
                System.out.print("N");
                continue;
            }
            if (mem[n][inputs[i]]) {
                System.out.print("Y");
                continue;
            }
            System.out.print("N ");
        }
    }


    public static void main(String[] args) {
        init();
        solve();
    }
}
