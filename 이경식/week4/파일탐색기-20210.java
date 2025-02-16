import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        List<String> sList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            sList.add(br.readLine().trim());
        }

        sList.sort(new customComparator());

        for (String s : sList) {
            System.out.println(s);
        }
    }


    static class customComparator implements Comparator<String> {

        @Override
        public int compare(String s1, String s2) {
            List<String> list1 = parseString(s1);
            List<String> list2 = parseString(s2);
            int idx = 0;
            while (idx < Math.min(list1.size(), list2.size())) {
                String str1 = list1.get(idx);
                String str2 = list2.get(idx);

                if (str1.equals(str2)) { //같은 경우 통과
                    idx++;
                    continue;
                }

                //숫자인지 확인
                boolean isNum1 = Character.isDigit(str1.charAt(0));
                boolean isNum2 = Character.isDigit(str2.charAt(0));

                if (isNum1 && !isNum2) return -1;
                if (!isNum1 && isNum2) return 1;

                if (!isNum1 && !isNum2) {
                    // 둘자 문자인 경우
                    int cmpIgnoreCase = str1.compareToIgnoreCase(str2); //대소문자를 무시하고 비교
                    if (cmpIgnoreCase != 0) return cmpIgnoreCase; // 같은 알파벳이 아닌경우

                    return str1.compareTo(str2); // 같은 알파벳인 경우 대문자 우선
                }

                if (isNum1 && isNum2) {
                    //둘다 숫자인 경우
                    BigInteger num1 = new BigInteger(str1);
                    BigInteger num2 = new BigInteger(str2);

                    if (num1.equals(num2)) {
                        return Integer.compare(str1.length(), str2.length()); //맨 앞에 0이 있는 경우 길이 비교
                    }
                    return num1.compareTo(num2);
                }
            }
            return Integer.compare(list1.size(), list2.size());
        }
    }

    private static List<String> parseString(String str) {
        List<String> result = new ArrayList<>();
        int i = 0;

        while (i < str.length()) {
            //숫자인지 문자인지 확인
            if (Character.isLetter(str.charAt(i))) {
                result.add(String.valueOf(str.charAt(i)));
                i++;
            } else {
                //숫자인 경우
                StringBuilder sb = new StringBuilder();
                while (i < str.length() && Character.isDigit(str.charAt(i))) {
                    sb.append(str.charAt(i));
                    i++;
                }
                result.add(sb.toString());
            }
        }
        return result;
    }
}