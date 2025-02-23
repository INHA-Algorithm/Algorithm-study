import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader br;
    public static int MAX = Integer.MAX_VALUE;
    public static int n, m;
    public static List<List<Road>> graph;
    public static PriorityQueue<Road> pq;
    public static int[] dist;

    public static class Road {
        public int dest;
        public int cost;

        public Road(int dest, int cost) {
            this.dest = dest;
            this.cost = cost;
        }
    }

    public static Integer[] input() throws IOException {
        return Arrays.stream(br.readLine().split(" "))
            .map(Integer::parseInt)
            .toArray(Integer[]::new);
    }

    public static void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        Integer[] input = input();
        n = input[0];
        m = input[1];

        graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            input = input();
            int a = input[0] - 1;
            int b = input[1] - 1;
            int c = input[2];
            graph.get(a).add(new Road(b, c));
            graph.get(b).add(new Road(a, c));
        }
        dist = new int[n + 1];
        Arrays.fill(dist, MAX);
        pq = new PriorityQueue<>(Comparator.comparingInt(r -> r.cost));
        pq.offer(new Road(0, 0));
        dist[0] = 0;
    }

    public static void solve() {

        while (!pq.isEmpty()) {
            Road cur = pq.poll();

            if (cur.dest == n - 1) {
                break;
            }

            if (cur.cost > dist[cur.dest]) {
                continue;
            }

            for (Road r : graph.get(cur.dest)) {
                int next = r.dest;
                int nextCost = cur.cost + r.cost;

                if (nextCost < dist[next]) {
                    dist[next] = nextCost;
                    pq.offer(new Road(next, nextCost));
                }
            }
        }
        System.out.println(dist[n - 1]);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
