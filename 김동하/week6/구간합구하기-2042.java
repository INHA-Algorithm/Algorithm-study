import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

import javax.print.DocFlavor.STRING;

public class Main {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringBuilder sb = new StringBuilder();
	
	public static int n,m,k;
	
	public static class SegTree{
		long tree[];
		int tSize;
		public SegTree(int aSize) {
			int h = (int)Math.ceil(Math.log(aSize) / Math.log(2));
			this.tSize = (int)Math.pow(2,h + 1);
			tree = new long[tSize];
		}
		public long init(long[] arr, int cur, int st, int ed) {
			if(st == ed) {
				return tree[cur] = arr[st];
			}
			return tree[cur] = init(arr, cur * 2, st, (st + ed) / 2) + init(arr, cur * 2 + 1, (st + ed) / 2 + 1, ed);
		}
		public void update(int cur, int idx, int st, int ed, long val) {
			if(idx < st || idx > ed) return;
			tree[cur] += val;
			if(st != ed) {
				update(cur * 2, idx, st, (st + ed) / 2, val);
				update(cur * 2 + 1, idx, (st + ed) / 2 + 1, ed, val);
			}
		}
		public long sum(int cur, int st, int ed, int l, int r) {
			if(ed < l || st > r) return 0;
			if(l <= st && ed <= r) return tree[cur];
			return sum(cur * 2, st, (st + ed) / 2, l,r) + sum(cur * 2 + 1, (st + ed) / 2 + 1, ed, l, r);
		}
	}
	
	
	
	public static void init() throws IOException{
		int[] in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		n = in[0];
		m = in[1];
		k = in[2];
		SegTree st = new SegTree(n);
		long[] in1;
		long arr[] = new long[n + 1];
		for(int i = 1; i <= n; i++) {
			arr[i] = Long.parseLong(br.readLine());
		}

		
		st.init(arr, 1, 1, n);
		for(int i = 0; i < m + k; i++) {
			in1 = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
			if(in1[0] == 1) {
				long val = in1[2] - arr[(int)in1[1]];
				st.update(1, (int)in1[1], 1, n, val);
				arr[(int)in1[1]] = in1[2];		
			}
			else {
				long ans = st.sum(1, 1, n, (int)in1[1], (int)in1[2]);
				sb.append(ans).append("\n");
			}
		}
	}
	
	public static void solution() throws IOException{
		init();
		
		
		bw.append(sb.toString());
		bw.flush();
		bw.close();
	}
	
    public static void main(String[] args) throws IOException {
    	solution();
    }

}