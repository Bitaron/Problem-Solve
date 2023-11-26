import java.util.Arrays;
import java.util.List;

public class Reverse_Vowel_345 {

    public static String reverseVowels(String s) {
        int front = 0;
        int back = s.length()-1;
        boolean swap = false;
        StringBuilder stringBuilder = new StringBuilder(s);
        List<Character> vowels = Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
        while (front < back) {
            if (vowels.contains(stringBuilder.charAt(front))
                    && vowels.contains(stringBuilder.charAt(back))) {
                char frontChar = stringBuilder.charAt(front);
                stringBuilder.setCharAt(front, stringBuilder.charAt(back));
                stringBuilder.setCharAt(back, frontChar);
                front++;
                back--;
            } else {
                if (!vowels.contains(stringBuilder.charAt(front))) {
                    front++;
                }
                if (!vowels.contains(stringBuilder.charAt(back))) {
                    back--;
                }
            }
        }

        return stringBuilder.toString();
    }

    public static void main(String[] args) {
        String str1 = "rAce car";
        System.out.println(reverseVowels(str1));
    }
}
