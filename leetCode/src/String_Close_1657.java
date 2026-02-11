import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class String_Close_1657 {

    public static boolean closeStrings(String word1, String word2) {
        Map<Character, Integer> charCount1 = new HashMap<>();
        Map<Character, Integer> charCount2 = new HashMap<>();
        for (int i = 0; i < word1.length(); i++) {
            if (charCount1.containsKey(word1.charAt(i))) {
                charCount1.put(word1.charAt(i), charCount1.get(word1.charAt(i)) + 1);
            } else {
                charCount1.put(word1.charAt(i), 1);
            }
        }
        for (int i = 0; i < word2.length(); i++) {
            if (charCount1.containsKey(word2.charAt(i))) {
                if (charCount2.containsKey(word2.charAt(i))) {
                    charCount2.put(word2.charAt(i), charCount2.get(word2.charAt(i)) + 1);
                } else {
                    charCount2.put(word2.charAt(i), 1);
                }
            } else {
                return false;
            }
        }


        for (Integer i : charCount1.values()) {
            if(!charCount2.values().remove(i)){
                return false;
            }
        }
        if (charCount2.values().isEmpty()) {
            return true;
        }
        return false;

    }

    public static void main(String[] args) {
        String w1 = "cabbba";
        String w2 = "abbccc";

        System.out.println(closeStrings(w1, w2));
    }
}

