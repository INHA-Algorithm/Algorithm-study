import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br;
    static BufferedWriter bw;
    static long DIVIDE = 10007;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        if (N == 0) {
            System.out.println(0);
            return;
        } else if (N == 1) {
            System.out.println(1);
            return;
        }

        long result = 1;
        int pow = 0;
        int last = 1;
        switch (N%3) {
            case 0:
                pow = N / 3;
                break;
            case 1:
                pow = N / 3 - 1;
                last = 4;
                break;
            case 2:
                pow = N / 3;
                last = 2;
                break;
        }
        while (true) {
            if (pow >= 9) {
                result = result * (long) Math.pow(3, 9) % DIVIDE;
                pow -= 9;
            } else if (pow <= 0) {
                break;
            } else {
                result = result * (long) Math.pow(3, pow) % DIVIDE;
                pow = 0;
            }
        }

        result = result * last % DIVIDE;
        bw.write(String.valueOf(result));
        bw.flush();
    }
}
