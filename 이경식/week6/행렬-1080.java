import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        boolean[][] a = new boolean[N][M];
        boolean[][] b = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            char[] arr = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                if (arr[j] == '0') {
                    a[i][j] = false;
                } else {
                    a[i][j] = true;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            char[] arr = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                if (arr[j] == '0') {
                    b[i][j] = false;
                } else {
                    b[i][j] = true;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 2; j++) {
                if(a[i][j] != b[i][j]) {
                    for (int t = 0; t < 3; t++) {
                        for (int r = 0; r < 3; r++) {
                            a[i+t][j+r] = !a[i+t][j+r];
                        }
                    }
                    count++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(a[i][j] != b[i][j]){
                    System.out.println(-1);
                    return;
                }
            }
        }
        System.out.println(count);
    }

}
