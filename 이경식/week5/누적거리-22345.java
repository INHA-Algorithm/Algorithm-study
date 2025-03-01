import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        long[] people = new long[N];
        long[] location = new long[N];
        long[] peopleSum = new long[N + 1];
        long[] sum = new long[N + 1];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            people[i] = Long.parseLong(st.nextToken());
            location[i] = Long.parseLong(st.nextToken());
        }

        long[][] temp = new long[N][2];
        for (int i = 0; i < N; i++) {
            temp[i][0] = location[i];
            temp[i][1] = people[i];
        }
        Arrays.sort(temp, Comparator.comparingLong(l -> l[0]));

        for (int i = 0; i < N; i++) {
            location[i] = temp[i][0];
            people[i] = temp[i][1];
        }

        for (int i = 1; i < N + 1; i++) {
            peopleSum[i] = people[i - 1] + peopleSum[i - 1];
            sum[i] = people[i - 1] * location[i - 1] + sum[i - 1];
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < Q; i++) {
            long input = Long.parseLong(br.readLine());

            int start = 0;
            int end = location.length;
            while (start < end) {
                int mid = (start + end) / 2;
                if (location[mid] >= input) {
                    end = mid;
                } else {
                    start = mid + 1;
                }
            }

            long left = peopleSum[start];
            long leftSum = sum[start];
            long leftLoc = input * left - leftSum;

            long right = peopleSum[N] - left;
            long rightSum = sum[N] - leftSum;
            long rightLoc = rightSum - input * right;


            bw.write(leftLoc + rightLoc + "\n");
        }
        bw.flush();
        bw.close();
    }
}