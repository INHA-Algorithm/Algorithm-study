import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StringBuilder sb;
	public static int n;
	public static String str;
	public static List<String> l = new ArrayList<>();
	
	public static void init() throws IOException {
		n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++) {
			l.add(br.readLine());
		}
	}
	
	public static class StringComparator implements Comparator<String> {
		@Override
		public int compare(String s1, String s2) {
			int len1 = s1.length();
			int len2 = s2.length();
			
			int idx1 = 0, idx2 = 0;
			while(idx1 < len1 && idx2 < len2) {
				char c1 = s1.charAt(idx1);
				char c2 = s2.charAt(idx2);
				
				//둘다 숫자
				if('0' <= c1 && c1 <= '9' && '0' <= c2 && c2 <= '9') {
					int nCnt1 = 0;
					int nCnt2 = 0;
					while(idx1 < len1&& s1.charAt(idx1) == '0') {
						nCnt1++;
						idx1++;
					}
					while(idx2 < len2 && s2.charAt(idx2) == '0') {
						nCnt2++;
						idx2++;
					}
					StringBuilder sb1 = new StringBuilder();
					StringBuilder sb2 = new StringBuilder();
					while(idx1 < len1 && '0' <= s1.charAt(idx1) && s1.charAt(idx1) <= '9') {
						sb1.append(s1.charAt(idx1));
						idx1++;
					}
					while(idx2 < len2 && '0' <= s2.charAt(idx2) && s2.charAt(idx2) <= '9') {
						sb2.append(s2.charAt(idx2));
						idx2++;
					}
					String num1 = sb1.toString();
					String num2 = sb2.toString();
					if(num1.length() > num2.length()) return 1;
					else if(num2.length() > num1.length()) return -1;
					int i = 0,j = 0;
					while(i < num1.length() && j < num2.length()) {
						if(num1.charAt(i) > num2.charAt(j)) return 1;
						else if(num2.charAt(j) > num1.charAt(i)) return -1;
						i++;
						j++;
					}
					if(nCnt1 != nCnt2) return nCnt1 - nCnt2;
				}
				
				//둘다숫자아님
				if(('0' > c1 || c1 > '9') && ('0' > c2 || c2 > '9')){
					if(c1 == c2) {
						idx1++;
						idx2++;
						continue;
					}
					if((Character.isUpperCase(c1) && Character.isUpperCase(c2)) 
							|| (!Character.isUpperCase(c1) && !Character.isUpperCase(c2))) {
						if(c1 != c2) {
							return c1-c2;
						}
						idx1++;
						idx2++;
						continue;
					}
					if(Character.isUpperCase(c1)) {
						c1 = Character.toLowerCase(c1);
						if(c1 == c2) return -1;
						return c1 - c2;
					}
					if(Character.isUpperCase(c2)) {
						c2 = Character.toLowerCase(c2);
						if(c1 == c2) return 1;
						return c1 - c2;
					}
					idx1++;
					idx2++;
				}
				if(('0' <= c1 && c1 <= '9') && ('0' > c2 || c2 > '9')) return -1;
				if(('0' > c1 || c1 > '9') && ('0' <= c2 && c2 <= '9')) return 1;
			}
			if(idx1 != len1 && idx2 == len2) return 1;
			else if(idx1 == len1 && idx2 != len2) return -1;
			return 0;
		}
	}

	public static void solution() throws IOException{
		init();
		Collections.sort(l,new StringComparator());
		for(String s : l) {
			System.out.println(s);
		}
	}
	public static void main(String[] args) throws IOException {
		solution();
	}
}
