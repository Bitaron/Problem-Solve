import java.util.ArrayList;
import java.util.List;

public class Greatest_Common_Divisor_of_Strings_1071 {

    public static String gcdOfStrings(String str1, String str2) {

        String minStr = "";
        String maxStr = "";
        if (str1.length() < str2.length()) {
            minStr = str1;
            maxStr = str2;
        } else {
            minStr = str2;
            maxStr = str1;
        }

        StringBuilder cd = new StringBuilder();
        List<StringBuilder> maxCdList = new ArrayList<>();
        int count = 0;
        while (count < minStr.length()) {
            cd.append(minStr.charAt(count));
            int remaining = minStr.length() - cd.length();
            StringBuilder calcualatedCd = new StringBuilder(cd);
            for (int i = 0; i < remaining; i = i + cd.length()) {
                calcualatedCd.append(cd);
            }
            String cdStr = calcualatedCd.toString();
            if (minStr.equals(cdStr)) {
                maxCdList.add(new StringBuilder(cd));
            }
            count++;
        }

        boolean cdFound = false;
        StringBuilder foundCd = new StringBuilder();
        for (int c = maxCdList.size() - 1; c >= 0; c--) {
            int remaining = maxStr.length() - maxCdList.get(c).length();
            StringBuilder calcualatedCd = new StringBuilder(maxCdList.get(c));
            for (int i = 0; i < remaining; i = i + maxCdList.get(c).length()) {
                calcualatedCd.append(maxCdList.get(c));
            }
            String cdStr = calcualatedCd.toString();
            if (maxStr.equals(cdStr)) {
                cdFound = true;
                foundCd = maxCdList.get(c);
                break;
            }
        }

        if (cdFound) {
            return foundCd.toString();
        } else {
            return "";
        }
    }

    public static void main(String[] args) {
        String str1 = "AA";
        String str2 = "AAAA";
        System.out.println(gcdOfStrings(str1, str2));
    }
}
