import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] distance = new int[N + 1];
        boolean[] check = new boolean[N + 1];

        Arrays.fill(distance, Integer.MAX_VALUE);
        ArrayList<farm>[] farmList = new ArrayList[N + 1];

        for (int i = 0; i < N + 1; i++) {
            farmList[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            farmList[A].add(new farm(B, C));
            farmList[B].add(new farm(A, C));
        }
        distance[1] = 0;
        PriorityQueue<farm> pq = new PriorityQueue<>();
        pq.add(new farm(1, 0));

        loop:while (!pq.isEmpty()) {
            farm peek = pq.poll();
            int now = peek.dst;
            if(check[now]) continue;
            check[now] = true;
            if (now == N) {
                break loop;
            }
            for (farm f : farmList[now]) {
                if (distance[f.dst] > distance[now] + f.cow) {
                    distance[f.dst] = distance[now] + f.cow;
                    pq.add(new farm(f.dst, distance[f.dst]));
                }
            }
        }
        System.out.println(distance[N]);
    }

    static class farm implements Comparable<farm> {

        int dst;
        int cow;

        farm(int dst, int cow) {
            this.dst = dst;
            this.cow = cow;
        }

        @Override
        public int compareTo(farm o1) {
            return Integer.compare(this.cow, o1.cow);
        }
    }
}
