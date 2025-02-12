import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class Main {
    public static int n;
    public static List<meeting> meetings;

    public static class meeting {
        public int start;
        public int end;

        public meeting(int start, int end) {
            this.start = start;
            this.end = end;
        }

    }


    public static void init() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        meetings = new ArrayList<>();
        int start, end;
        for (int i = 0; i < n; i++) {
            start = sc.nextInt();
            end = sc.nextInt();
            meetings.add(new meeting(start, end));
        }
        meetings.sort(new Comparator<meeting>() {
            public int compare(meeting m1, meeting m2) {
                if (m1.end == m2.end) {
                    return Integer.compare(m1.start, m2.start);
                }
                if (m1.end < m2.end) {
                    return -1;
                }
                return 1;
            }
        });
    }

    public static void solve() {
        int ans = 0;
        meeting tmp = new meeting(-1, -1);
        for (meeting m : meetings) {
            if (m.start < tmp.end) {
                continue;
            }
            ans++;
            tmp = m;
        }
        System.out.println(ans);
    }


    public static void main(String[] args) {
        init();
        solve();
    }
}
