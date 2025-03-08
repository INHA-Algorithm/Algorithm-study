import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static StringBuilder sb = new StringBuilder();

    public static int N;
    public static int cntP = 0, cntZ = 0, cntM = 0;
    public static int[][] paper;

    public static void cut(int x, int y, int z) {
        boolean minu = true, zero = true, pl = true;

        for (int i = y; i < y + x; i++) {
            for (int j = z; j < x + z; j++) {
                if (paper[i][j] == -1) {
                    zero = false;
                    pl = false;
                } else if (paper[i][j] == 0) {
                    minu = false;
                    pl = false;
                } else if (paper[i][j] == 1) {
                    zero = false;
                    minu = false;
                }
            }
        }

        if (minu) {
            cntM++;
        } else if (zero) {
            cntZ++;
        } else if (pl) {
            cntP++;
        } else {
            int newer = x / 3;
            cut(newer, y, z);
            cut(newer, y, z + newer);
            cut(newer, y, z + 2 * newer);

            cut(newer, y + newer, z);
            cut(newer, y + newer, z + newer);
            cut(newer, y + newer, z + 2 * newer);

            cut(newer, y + 2 * newer, z);
            cut(newer, y + 2 * newer, z + newer);
            cut(newer, y + 2 * newer, z + 2 * newer);
        }
    }
    
    public static void init() throws IOException {
        N = Integer.parseInt(br.readLine());
        paper = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                paper[i][j] = Integer.parseInt(stk.nextToken());
            }
        }    	
    }
    
    public static void solution() throws IOException {
    	init();
        cut(N, 0, 0);
        sb.append(cntM).append("\n").append(cntZ).append("\n").append(cntP);
        
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    public static void main(String[] args) throws IOException {
    	solution();
    }
}