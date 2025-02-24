import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int n,m;
    public static int[] arr;

    public static void init() throws IOException {
        int[] in = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        n = in[0];
        m = in[1];
        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

    }


    public static void solution() throws IOException{
        init();
        Arrays.sort(arr);
        long st = 0;
        long ed = arr[arr.length - 1];
        long mid = 0;
        long sum = 0;
        while(st <= ed) {
            sum = 0;
            mid = (st + ed) / 2;
            for(int i = 0; i < n; i++) {
                if(arr[i] > mid) sum += arr[i] - mid;
            }
            if(sum >= m) {
                st = mid + 1;
            }
            else ed = mid - 1;
        }
        if(sum < m) mid --;
        System.out.println(mid);
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
