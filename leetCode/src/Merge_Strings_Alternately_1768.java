public class Merge_Strings_Alternately_1768 {
    public static String mergeAlternately(String word1, String word2) {
        StringBuilder stringBuilder = new StringBuilder();
        int length1 = 0;
        int length2 = 0;
        boolean isFirst = true;

        while (length1 < word1.length() || length2 < word2.length()) {
            if (isFirst) {
                stringBuilder.append(word1.charAt(length1));
                length1++;
                if (length2 < word2.length()) {
                    isFirst = false;
                }
            } else {
                stringBuilder.append(word2.charAt(length2));
                length2++;
                if (length1 < word1.length()) {
                    isFirst = true;
                }
            }

        }

        return stringBuilder.toString();
    }

    public static void main(String[] args) {
        String one = "abcd";
        String two = "pq";
        System.out.println(mergeAlternately(one, two));
    }
}
