import java.util.*;
import java.io.*;

public class Main {

    static Vector<Integer> v;
    static boolean[] check;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        v = new Vector<>();
        check = new boolean[N+1];
        bt(N,M);
    }

    static void bt(int N, int M) {
        if(v.size() == M) {
            for (int i : v) {
                System.out.print(i + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (check[i]) {
                continue;
            }
            v.add(Integer.valueOf(i));
            check[i] = true;
            bt(N,M);
            v.remove(Integer.valueOf(i));
            check[i] = false;
        }
    }
}
