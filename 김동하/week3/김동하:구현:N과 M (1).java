import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();
    public static int n,m;
    public static int arr[] = new int[10];

    public static void init() throws IOException{
        int[] in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = in[0];
        m = in[1];
    }

    public static boolean[] contains = new boolean[10];

    public static void search(int cnt) {
        if(cnt == m) {
            for(int i = 0; i < m; i++) {
                sb.append(arr[i]).append(" ");
            }
            sb.append("\n");
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(!contains[i] && cnt < m) {
                contains[i] = true;
                arr[cnt] = i;
                search(cnt + 1);
                contains[i] = false;
            }
        }
    }

    public static void solution() throws IOException{
        init();
        search(0);
        bw.append(sb.toString());
        bw.flush();
        bw.close();
    }
    public static void main(String[] args)throws IOException {
        solution();
    }

}
