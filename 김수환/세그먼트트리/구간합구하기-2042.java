import java.io.*;
import java.util.*;

public class Main {
    static int n, m, k;
    static long[] values;

    static BufferedReader br;
    static Tree tree;

    public static class Node {
        public long val;
        public Node par, lc, rc;
        int start, end;

        public Node(int start, int end) {
            this.start = start;
            this.end = end;
            this.val = 0;
            this.par = this.lc = this.rc = null;
        }

        public void update(long ov, long nv) {
            this.val = this.val - ov + nv;
        }

        public boolean isRoot() {
            return (this.par == null);
        }
    }

    public static class Tree {
        public Node root;
        public Node[] leaves;

        public Tree(int n, long[] values) {
            this.leaves = new Node[n];
            this.root = create(0, n - 1, null, values);
        }

        Node create(int start, int end, Node parent, long[] values) {
            Node node = new Node(start, end);
            node.par = parent;

            if (start == end) {
                node.val = values[start];
                leaves[start] = node;
            } else {
                int mid = (start + end) / 2;
                node.lc = create(start, mid, node, values);
                node.rc = create(mid + 1, end, node, values);
                node.val = node.lc.val + node.rc.val;
            }
            return node;
        }

        public void update(int i, long nv) {
            Node cur = leaves[i];
            long ov = cur.val;
            cur.update(ov, nv);

            while (!cur.isRoot()) {
                cur = cur.par;
                cur.update(ov, nv);
            }
        }

        public long getSum(int start, int end) {
            return find(root, start, end);
        }

        long find(Node node, int start, int end) {
            if (node == null || end < node.start || start > node.end) {
                return 0;
            }

            if (start <= node.start && node.end <= end) {
                return node.val;
            }

            return find(node.lc, start, end) + find(node.rc, start, end);
        }
    }

    public static void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        values = new long[n];
        for (int i = 0; i < n; i++) {
            values[i] = Long.parseLong(br.readLine());
        }
        tree = new Tree(n, values);

    }


    public static void process() throws Exception {
        for (int i = 0; i < m + k; i++) {
            StringTokenizer cmd = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(cmd.nextToken());
            int b = Integer.parseInt(cmd.nextToken());
            long c = Long.parseLong(cmd.nextToken());
            if (a == 1) {
                values[b - 1] = c;
                tree.update(b - 1, c);
            } else {
                System.out.println(tree.getSum(b - 1,(int)c - 1));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        process();
    }
}
