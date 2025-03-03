import java.io.*;
import java.util.*;

public class Main {
    static int[][] paper;
    static int[] result;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        paper = new int[N][N];
        result = new int[3];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        recursive(0, 0, N);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public static void recursive(int x,int y, int size) {
        int num = paper[x][y];
        boolean flag = false;
        loop: for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (num != paper[i][j]) {
                    flag = true;
                    break loop;
                }
            }
        }

        if (flag) {
            recursive(x, y, size / 3);
            recursive(x + (size / 3), y, size / 3);
            recursive(x + (size / 3) * 2, y, size / 3);
            recursive(x, y + (size / 3), size / 3);
            recursive(x + (size / 3), y + (size / 3), size / 3);
            recursive(x + (size / 3) * 2, y + (size / 3), size / 3);
            recursive(x, y + (size / 3) * 2, size / 3);
            recursive(x + (size / 3), y + (size / 3) * 2, size / 3);
            recursive(x + (size / 3) * 2, y + (size / 3) * 2, size / 3);
        } else {
            result[num + 1]++;
        }
    }
}
