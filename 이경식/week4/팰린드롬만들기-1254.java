import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer(br.readLine());
        StringBuffer reverseSb = new StringBuffer(sb).reverse();

        int len = sb.length();

        if (sb.compareTo(reverseSb) == 0) {
            System.out.println(sb.length());
            return;
        }

        int delCnt = 0;
        for (int i = 0; i < len; i++) {
            sb.deleteCharAt(0);
            reverseSb.deleteCharAt(reverseSb.length() - 1);
            delCnt++;
            if (sb.compareTo(reverseSb) == 0) {
                break;
            }
        }

        System.out.println(len + delCnt);
    }
}
