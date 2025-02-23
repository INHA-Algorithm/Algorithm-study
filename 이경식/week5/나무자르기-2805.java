import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        long M = Long.parseLong(st.nextToken());

        long[] arr = new long[N];
        long max = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
            max = Math.max(max, arr[i]);
        }

        long left = 0, right = max, h = 0;

        while (left <= right) {
            long mid = (left + right) / 2;
            long sum = 0;

            for (long tree : arr) {
                if (tree > mid) {
                    sum += (tree - mid);
                }
            }

            if (sum >= M) {
                h = Math.max(h, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        System.out.println(h);
    }
}