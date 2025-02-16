import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException{


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] choo = new int[N];
        for (int i = 0; i < N; i++) {
            choo[i] = Integer.parseInt(st.nextToken());
        }

        int M = Integer.parseInt(br.readLine());
        int[] judge = new int[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            judge[i] = Integer.parseInt(st.nextToken());
        }

        boolean[] dp = new boolean[40001];

        ArrayList<Integer> numList = new ArrayList<>();
        dp[choo[0]] = true;
        numList.add(0);
        numList.add(choo[0]);

        for (int i = 1; i < N; i++) {
            int size = numList.size();
            for (int j = 0; j < size; j++) {
                if (!dp[choo[i] + numList.get(j)]) {
                    dp[choo[i] + numList.get(j)] = true;
                    numList.add(choo[i] + numList.get(j));
                }
                if(!dp[Math.abs(numList.get(j) - choo[i])]){
                    dp[Math.abs(numList.get(j) - choo[i])] = true;
                    numList.add(Math.abs(numList.get(j) - choo[i]));
                }
            }
        }

        for (int i : judge) {
            System.out.print((dp[i] ? "Y" : "N") + " ");
        }

    }
}
