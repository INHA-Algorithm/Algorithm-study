import java.io.*;
import java.util.*;

public class Main {
    static final int MAX_SIZE = 200001;
    static long N, Q;
    static long[] distSum = new long[MAX_SIZE];
    static long[] numSum = new long[MAX_SIZE];
    static List<Village> city = new ArrayList<>();
    static List<Long> villageLoc = new ArrayList<>();

    static List<Long> candidates = new ArrayList<>();

    static BufferedReader br;

    static int lowerBound(List<Long> list, long key) {
        int idx = Collections.binarySearch(list, key);
        if (idx < 0) {
            idx = -(idx + 1);
        }
        return idx;
    }

    static class Village {
        Long loc;
        Long num;

        Village(Long loc, Long num) {
            this.loc = loc;
            this.num = num;
        }
    }
    public static void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Long.parseLong(st.nextToken());
        Q = Long.parseLong(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            long num = Long.parseLong(st.nextToken());
            long loc = Long.parseLong(st.nextToken());
            city.add(new Village(loc, num));
            villageLoc.add(loc);
        }


        for(int i=0;i< Q;i++){
            candidates.add(Long.parseLong(br.readLine()));
        }
    }

    public static void solve(){

        Collections.sort(city, Comparator.comparingLong(p -> p.loc));
        Collections.sort(villageLoc);

        for (int i = 1; i <= N; i++) {
            distSum[i] = distSum[i - 1] + city.get(i - 1).loc * city.get(i - 1).num;
            numSum[i] = numSum[i - 1] + city.get(i - 1).num;
        }

        for(long q : candidates) {
            int idx = lowerBound(villageLoc, q);
            long result = distSum[(int) N] - 2 * distSum[idx]
                - (q * (numSum[(int) N] - 2 * numSum[idx]));

            System.out.println(result);
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();

    }
    
}
