import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static int n,m;
    public static boolean[][] dp = new boolean[31][50001];
    public static int arr[] = new int[31];
    public static int[] in;

    public static void init() throws IOException{
        in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = in[0];
        in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for(int i = 0; i < n; i++) {
            arr[i] = in[i];
        }
        in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        m = in[0];
        in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    public static void rec(int idx, int weight) {
        if(idx > n || dp[idx][weight]) return;
        dp[idx][weight] = true;
        rec(idx + 1, weight + arr[idx]);
        rec(idx + 1, Math.abs(weight - arr[idx]));
        rec(idx + 1, weight);
    }

    public static void solution() throws IOException{
        init();
        rec(0, 0);
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < m; i++) {
            if(dp[n][in[i]]) sb.append("Y ");
            else sb.append("N ");
        }
        System.out.println(sb);
    }
    public static void main(String[] args)throws IOException {
        solution();
    }

}
