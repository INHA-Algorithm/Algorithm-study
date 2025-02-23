import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int TC = Integer.parseInt(st.nextToken());
        for (int t = 0; t < TC; t++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());
            long[] distance;
            ArrayList<Edge> edges = new ArrayList<>();
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int T = Integer.parseInt(st.nextToken());
                edges.add(new Edge(S, E, T));
                edges.add(new Edge(E, S, T));
            }
            for (int i = 0; i < W; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int T = Integer.parseInt(st.nextToken());
                edges.add(new Edge(S, E, -1 * T));
            }
            boolean cycle = false;
            distance = new long[N + 1];
            Arrays.fill(distance, 1919191919);
            distance[edges.get(0).src] = 0;
            for (int i = 1; i < N; i++) {
                for (Edge edge : edges) {
                    if (distance[edge.dst] > distance[edge.src] + edge.weight) {
                        distance[edge.dst] = distance[edge.src] + edge.weight;
                    }
                }
            }
            for (Edge edge : edges) {
                if (distance[edge.dst] > distance[edge.src] + edge.weight) {
                    cycle = true;
                    break;
                }
            }
            if(cycle){
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    static class Edge {
        int src;
        int dst;
        int weight;

        Edge(int src, int dst, int weight) {
            this.src = src;
            this.dst = dst;
            this.weight = weight;
        }
    }
}
