import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static char[] str;
    public static int ans;
    public static char[] sound = {'q','u','a','c','k'};

    public static void init() throws IOException {
        str = br.readLine().toCharArray();
        ans = 0;
    }

    public static void countDuck() {
        int siz = str.length;
        while(siz != 0) {
            int cnt = 0;
            boolean flag = false;
            int idx = 0;
            int[] list = new int[5];
            while(idx < str.length) {
                if(str[idx] == sound[cnt]) {
                    list[cnt] = idx;
                    cnt++;
                    if(cnt == 5) {
                        siz -= 5;
                        flag = true;
                        cnt = 0;
                        for(int i = 0; i < 5; i++) {
                            str[list[i]] = '0';
                        }
                    }
                }
                idx++;
            }
            if(!flag) break;
            ans++;
        }
        if(siz != 0)ans = -1;
    }

    public static void solution() throws IOException {
        init();
        countDuck();
        StringBuilder sb = new StringBuilder();
        sb.append(ans);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
