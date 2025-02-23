import java.io.*;
import java.util.*;

public class Main {

    public static BufferedReader br;
    public static String str;
    public static String rev;
    public static int start;
    public static boolean flag;

    public static void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
        rev = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            rev += str.charAt(i);
        }

        start = 0;
    }

    public static void solve() {
        while (start < str.length() - 1) {
            for (int i = start; i < str.length() - 1; i++) {
                if (str.charAt(i) != rev.charAt(i - start)) {
                    flag = false;
                    start++;
                    break;
                }
                flag = true;
            }
            if (flag) {
                break;
            }
        }
        System.out.println(start + str.length());
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}
