import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int N,Q;
    public static long sumA[];
    public static long sumX[];

    public static List<Home> homes;

    public static class Home implements Comparable<Home>{
        long a,x;
        public Home(long a, long x) {
            this.a = a;
            this.x = x;
        }

        @Override
        public int compareTo(Home o) {
            return Long.compare(this.x, o.x);
        }
    }

    public static void init() throws IOException{
        int[] in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        N = in[0];
        Q = in[1];
        sumA = new long[N + 1];
        sumX = new long[N + 1];
        homes = new ArrayList<>();
        for(int i = 0; i < N; i++) {
            long[] inL = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
            homes.add(new Home(inL[0],inL[1]));
        }
        Collections.sort(homes);
        sumA[0] = homes.get(0).a;
        sumX[0] = homes.get(0).x * homes.get(0).a;
        for(int i = 1; i < N; i++) {
            sumA[i] = sumA[i - 1] + homes.get(i).a;
            sumX[i] = sumX[i - 1] + homes.get(i).x * homes.get(i).a;
        }
    }

    public static int binary_search(long q) {
        int st = 0;
        int ed = N - 1;
        int mid = (st + ed) / 2;
        while(st <= ed) {
            mid = (st + ed) / 2;
            long x = homes.get(mid).x;
            if(x >= q) ed = mid - 1;
            else st = mid + 1;
        }

        return st;
    }

    public static void solution() throws IOException{
        init();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < Q; i++) {
            long q = Long.parseLong(br.readLine());
            int idx = binary_search(q);
            long idxSumA = 0;
            long nSumA = 0;
            long idxSumX = 0;
            long nSumX = 0;
            if(idx == 0) {
                idxSumA = 0;
                idxSumX = 0;
            }
            else {
                idxSumA = sumA[idx - 1];
                idxSumX = sumX[idx - 1];
            }
            nSumA = sumA[N - 1] - idxSumA;
            nSumX = sumX[N - 1] - idxSumX;

            long ans = idxSumA * q - idxSumX + nSumX - nSumA * q;
            sb.append(ans + "\n");
        }
        bw.append(sb.toString());
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }

}
