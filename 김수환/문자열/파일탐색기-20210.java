import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static boolean isNum(char c) {
        return ('0' <= c && c <= '9');
    }

    public static boolean isNum(String str) {
        return isNum(str.charAt(0));
    }

    public static class Word implements Comparable<Word> {
        public List<String> seq;
        public String origin;

        public Word(String str) {
            origin = str;
            seq = new ArrayList<>();
            boolean isN = isNum(str.charAt(0));
            StringBuilder elem = new StringBuilder();
            for (int i = 0; i < str.length(); i++) {
                if(isNum(str.charAt(i))){
                    elem.append(str.charAt(i));
                    isN = true;
                    continue;
                }
                if(isN){
                    seq.add(elem.toString());
                    elem = new StringBuilder();
                }
                isN = false;
                seq.add(String.valueOf(str.charAt(i)));
            }
            if(isN){
                seq.add(elem.toString());
            }
        }

        public void print() {
            System.out.println(origin);
        }

        @Override
        public int compareTo(Word w) {
            int n = Math.min(this.seq.size(), w.seq.size());
            for (int i = 0; i < n; i++) {
                String me = this.seq.get(i);
                String you = w.seq.get(i);
                if (me.equals(you)) {
                    continue;
                }
                boolean isN = isNum(me);
                if (isN ^ isNum(you)) {
                    return isN ? -1 : 1;
                } else {
                    if(isN){
                        BigInteger mn = new BigInteger(me);
                        BigInteger yn = new BigInteger(you);

                        if (mn.equals(yn)) {
                            return me.length()-you.length();
                        }
                        return mn.compareTo(yn);
                    } else {
                        if(me.equalsIgnoreCase(you)){
                            return me.compareTo(you);
                        }
                        return me.compareToIgnoreCase(you);
                    }

                }
            }
            return this.seq.size() - w.seq.size();
        }
    }

    public static List<Word> words;
    public static int n;
    public static BufferedReader br;

    public static void init() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        words = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            words.add(new Word(str));
        }
    }

    public static void solve() {
        Collections.sort(words);
        words.forEach(Word::print);
    }

    public static void main(String[] args) throws Exception {
        init();
        solve();
    }
}