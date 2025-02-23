import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] line = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] result = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            line[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N; i++) {
            int j = 1;
            int cnt = 0;
            while (cnt <= line[i]) {
                if (result[j] == 0) {
                    cnt++;
                    j++;
                } else {
                    if (result[j] < i) {
                        j++;
                    } else {
                        cnt++;
                        j++;
                    }
                }
            }
            result[j-1] = i;
        }

        for (int i = 1; i <= N; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
