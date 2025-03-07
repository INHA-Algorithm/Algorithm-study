import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int n;
    public static int arr[];
    public static void init() throws IOException {
        n = Integer.parseInt(br.readLine());
        arr = new int[n + 1];
        int[] in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for(int i = 1; i <= n; i++) {
            arr[i] = in[i - 1];
        }
    }
    public static int[] ans;

    public static void solution() throws IOException{
        init();
        ans = new int[n + 1];
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            for(int j = 1; j <= n; j++) {
                if(ans[j] == 0) {
                    if(cnt == arr[i]) {
                        ans[j] = i;
                        break;
                    }
                    cnt++;
                }
            }

        }
        for(int i = 1; i <= n; i++) {
            System.out.print(ans[i] + " ");
        }
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
