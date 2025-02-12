import java.io.*;
import java.sql.Array;
import java.util.*;

public class Main {

    static int[] bfs_x = {-1, 0, 0, 1};
    static int[] bfs_y = {0, -1, 1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[][] space = new int[N][N];
        int babySharkSize = 2;
        int cnt = 0;
        Point babyShark = null;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                space[i][j] = Integer.parseInt(st.nextToken());
                if (space[i][j] == 9) {
                    babyShark = new Point(i, j, 0);
                    space[i][j] = 0;
                }
            }
        }

        int totalTime = 0;

        while (true) {
            Queue<Point> q = new ArrayDeque<>();
            boolean[][] check = new boolean[N][N];
            q.add(new Point(babyShark.x, babyShark.y,0));
            check[babyShark.x][babyShark.y] = true;

            PriorityQueue<Point> pq = new PriorityQueue<>();
            int distance = Integer.MAX_VALUE;

            while (!q.isEmpty()) {
                Point now = q.poll();

                for (int i = 0; i < 4; i++) {
                    int next_x = now.x + bfs_x[i];
                    int next_y = now.y + bfs_y[i];

                    if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) {
                        continue;
                    }
                    if (check[next_x][next_y]) {
                        continue;
                    }
                    if (space[next_x][next_y] > babySharkSize) {
                        continue;
                    }
                    check[next_x][next_y] = true;
                    q.add(new Point(next_x, next_y, now.dist + 1));

                    if (space[next_x][next_y] > 0 && space[next_x][next_y] < babySharkSize) {
                        if (now.dist + 1 < distance) {
                            distance = now.dist + 1;
                            pq = new PriorityQueue<>();
                            pq.add(new Point(next_x, next_y, distance));
                        } else if (now.dist + 1 == distance) {
                            pq.add(new Point(next_x, next_y, distance));
                        }
                    }
                }
            }

            Point fish = pq.isEmpty() ? null : pq.peek();

            if (fish == null) break;
            
            totalTime += fish.dist;

            babyShark = new Point(fish.x, fish.y, 0);
            space[fish.x][fish.y] = 0;

            cnt++;
            if (cnt == babySharkSize) {
                babySharkSize++;
                cnt = 0;
            }
        }

        System.out.println(totalTime);
    }


    static class Point implements Comparable<Point> {
        int x;
        int y;
        int dist;

        Point(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }

        @Override
        public int compareTo(Point p) {
            if (this.dist > p.dist) {
                return 1;
            } else if (this.dist == p.dist) {
                if (this.x > p.x) {
                    return 1;
                } else if (this.x == p.x) {
                    if (this.y > p.y) {
                        return 1;
                    } else {
                        return -1;
                    }
                } else {
                    return -1;
                }
            } else {
                return -1;
            }
        }
    }
}
