import java.util.HashMap;
import java.util.LinkedHashMap;

public class Maximum_Vowel_1456 {

    public static int maxVowels(String s, int k) {
        HashMap<Character, String> vowels = new LinkedHashMap<>();
        vowels.put('a', "a");
        vowels.put('e', "a");
        vowels.put('i', "a");
        vowels.put('o', "a");
        vowels.put('u', "a");
        if (s.length() == 1) {
            if (vowels.containsKey(s.charAt(0))) {
                return 1;
            } else {
                return 0;
            }
        }

        int max = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.containsKey(s.charAt(i))) {
                max++;
            }
        }

        int start = 1;
        int end = k;
        int temp = max;
        while (end < s.length()) {
            if (vowels.containsKey(s.charAt(start - 1))) {
                temp--;
            }
            if (vowels.containsKey(s.charAt(end))) {
                temp++;
            }
            if (temp > max) {
                max = temp;
            }
            start++;
            end++;
        }

        return max;
    }

    public static void main(String[] args) {
        String s = "leetcode";
        int k = 3;

        System.out.println(maxVowels(s, k));
    }
}
