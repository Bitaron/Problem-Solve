import java.util.ArrayList;
import java.util.List;

public class Greatest_Number_of_Candies_1431 {
    public static List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = -1;
        for (int i = 0; i < candies.length; i++) {
            if (max < candies[i]) {
                max = candies[i];
            }
        }
        List<Boolean> results = new ArrayList<>();

        for (int i = 0; i < candies.length; i++) {
            if (max - candies[i] <= extraCandies) {
                results.add(true);
            } else {
                results.add(false);
            }
        }

        return results;
    }


    public static void main(String[] args) {
        int[] candies = {4,2,1,1,2};
        int extra = 1;
        System.out.println(kidsWithCandies(candies, extra));
    }
}
