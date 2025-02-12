import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        Pair[]arr=new Pair[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int value1 = Integer.parseInt(st.nextToken());
            int value2 = Integer.parseInt(st.nextToken());
            arr[i] = new Pair(value1,value2);
        }
        Arrays.sort(arr, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.value2==o2.value2){
                    return o1.value1 - o2.value1;
                }
                return o1.value2 - o2.value2;
            }
        });
        int count = 0;
        int end = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i].value1 >= end) {
                end = arr[i].value2;
                count++;
            }
        }
        System.out.println(count);
    }
}

class Pair{
    public int value1;
    public int value2;

    Pair(int value1, int value2) {
        this.value1 = value1;
        this.value2 = value2;
    }
}
