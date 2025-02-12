package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int n;
    public static int[][] dp = new int[503][503];
    public static Procession[] arr = new Procession[503];
    static class Procession {
        private int row,column;
        public Procession(int row, int column) {
            this.row = row;
            this.column = column;
        }
    }

    public static void init() throws IOException {
        n = Integer.parseInt(br.readLine());
        int[] in;
        for(int i = 1; i <= n; i++) {
            in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int x = in[0];
            int y = in[1];
            arr[i] = new Procession(x,y);
        }
    }

    public static void solution() {
        for(int i = 1; i < n; i++) {
            for(int j = 1; i + j <= n; j++) {
                dp[j][i + j] = Integer.MAX_VALUE;
                for(int k = j; k <= i + j; k++) {
                    dp[j][i + j] = Math.min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[j].row * arr[k].column * arr[i + j].column);
                }
            }
        }
        System.out.println(dp[1][n]);
    }

    public static void main(String[] args) throws IOException{
        init();
        solution();
    }
}
