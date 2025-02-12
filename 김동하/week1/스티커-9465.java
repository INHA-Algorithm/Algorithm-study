package org.example;

import java.util.Scanner;


public class Main {
    public static int sticker[][] = new int[3][100001];
    public static int dp[][] = new int[3][100001];
    public static Scanner sc = new Scanner(System.in);
    public static int n,t;
    public static void init() {
        n = sc.nextInt();
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= n; j++) {
                sticker[i][j] = sc.nextInt();
            }
        }
        dp[1][1] = sticker[1][1];
        dp[2][1] = sticker[2][1];
        dp[1][2] = sticker[2][1] + sticker[1][2];
        dp[2][2] = sticker[1][1] + sticker[2][2];
    }

    public static void solution() {
        init();
        for(int i = 3; i <= n; i++) {
            dp[1][i] = Math.max(dp[2][i - 1] + sticker[1][i],
                    dp[1][i - 2] + sticker[1][i]);
            dp[1][i] = Math.max(dp[1][i], dp[2][i - 2] + sticker[1][i]);
            dp[2][i] = Math.max(dp[1][i - 1] + sticker[2][i],
                    dp[2][i - 2] + sticker[2][i]);
            dp[2][i] = Math.max(dp[2][i], dp[1][i - 2] + sticker[2][i]);
        }
        int ans = Math.max(dp[1][n], dp[2][n]);
        System.out.println(ans);
    }
    public static void main(String[] args) {
        t = sc.nextInt();
        for(int i = 0; i < t; i++) {
            solution();
        }
    }
}
