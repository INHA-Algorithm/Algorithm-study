import java.io.*;
import java.util.*;

public class Main {

    static long[] segmentTree;
    static int size;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int pow = 0;
        int tmp = N;
        while (tmp > 0) {
            tmp /= 2;
            pow++;
        }

        size = (int) Math.pow(2, pow) * 2;
        segmentTree = new long[size];
        int idx = size / 2;
        for (int i = 0; i < N; i++) {
            segmentTree[idx + i] = Long.parseLong(br.readLine());
        }
        for (int i = idx - 1; i > 0; i--) {
            segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
        }

        for (int i = 0; i < M + K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            switch (a) {
                case 1:
                    changeValue(b, c);
                    break;
                case 2:
                    System.out.println(getSum(b, (int)c));
                    break;
            }
        }
    }

    static long getSum(int start, int end) {
        long sum = 0;
        int start_idx = start + size / 2 - 1;
        int end_idx = end + size / 2 - 1;
        while (start_idx <= end_idx) {
            if (start_idx % 2 == 1) {
                sum += segmentTree[start_idx];
                start_idx++;
            }
            if ((end_idx % 2) == 0) {
                sum += segmentTree[end_idx];
                end_idx--;
            }
            start_idx /= 2;
            end_idx /= 2;
        }
        return sum;
    }

    static void changeValue(int idx, long value) {
        int change_idx = idx + size / 2 - 1;
        long diff = value - segmentTree[change_idx];
        while (change_idx > 0) {
            segmentTree[change_idx] += diff;
            change_idx /= 2;
        }
    }
}
