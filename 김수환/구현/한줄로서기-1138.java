import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static List<Integer> people;

    static Stack<Integer> condition;
    static BufferedReader br;

    static void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        condition = new Stack<>();
        for (int i = 0; i < n; i++) {
            condition.push(Integer.parseInt(st.nextToken()));
        }
    }

    static void solve() {
        people = new LinkedList<>();
        int cur = n;
        while (!condition.isEmpty()) {
            int idx = condition.peek();
            condition.pop();
            people.add(idx, cur);
            cur--;
        }
        for (int human : people) {
            System.out.print(human + " ");
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();

    }

}
