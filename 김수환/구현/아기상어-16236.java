import java.util.ArrayDeque;

import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static int[][] map;
    public static int[] rd = {-1, 0, 0, 1};
    public static int[] cd = {0, -1, 1, 0};
    public static int map_size;

    public static Shark baby;

    public static class Location {
        public int r, c;

        public int d;

        public Location(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }
    }

    public static class Shark {
        int r, c; // 위치
        int size;

        int goal;
        int moving_dist;

        public Shark(int r, int c, int size, int moving_dist) {
            this.r = r;
            this.c = c;
            this.size = size;
            this.goal = size;
            this.moving_dist = moving_dist;
        }

        public void move(Location loc) {
            goal--;
            if (goal == 0) {
                size++;
                goal = size;
            }
            moving_dist += loc.d;
            map[r][c] = map[loc.r][loc.c] = 0;
            r = loc.r;
            c = loc.c;
        }
    }

    public static boolean out_of_bound(int r, int c) {
        return r < 0 || r >= map_size || c < 0 || c >= map_size;
    }

    public static void init() {
        Scanner sc = new Scanner(System.in);
        map_size = sc.nextInt();
        map = new int[map_size][map_size];
        for (int i = 0; i < map_size; i++) {
            for (int j = 0; j < map_size; j++) {
                map[i][j] = sc.nextInt();
                if (map[i][j] == 9) {
                    map[i][j] = 0;
                    baby = new Shark(i, j, 2, 0);
                }
            }
        }

    }

    public static Location decide() {
        Queue<Location> queue = new ArrayDeque<>();
        boolean[][] check = new boolean[map_size][map_size];
        Location ret = new Location(22, 22, 401);

        queue.offer(new Location(baby.r, baby.c, 0));
        check[baby.r][baby.c] = true;
        while (!queue.isEmpty()) {
            Location cur = queue.poll();

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + rd[i];
                int nc = cur.c + cd[i];
                int nd = cur.d + 1;
                if (out_of_bound(nr, nc)) {
                    continue;
                }
                if (check[nr][nc]) {
                    continue;
                }
                int next = map[cur.r + rd[i]][cur.c + cd[i]];
                if (next == 0 || next == baby.size) {
                    queue.offer(new Location(nr, nc, nd));
                    check[nr][nc] = true;
                    continue;
                }
                if (next < baby.size) {
                    if (ret.d < nd) {
                        continue;
                    }
                    if (ret.d == nd) {
                        if (ret.r < nr) {
                            continue;
                        }
                        if (ret.r == nr && ret.c < nc) {
                            continue;
                        }
                    }

                    ret = new Location(nr, nc, nd);
                }
            }
        }
        return ret;
    }

    public static void solve() {
        while (true) {
            Location next = decide();
            if (next.d == 401) {
                break;
            }
            baby.move(next);
        }
        System.out.println(baby.moving_dist);
    }


    public static void main(String[] args) {
        init();
        solve();
    }
}
