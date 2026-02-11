public class Container_With_Most_Water_11 {

    public static int maxArea(int[] height) {
        int currentMax = 0;
        int front = 0;
        int back = height.length - 1;
        while (front < back) {
            int area = Math.min(height[front], height[back]) * (back - front);
            if (area > currentMax) {
                currentMax = area;
            }
            if (height[front] < height[back]) {
                front++;
            } else {
                back--;
            }
        }
        return currentMax;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,1};

        System.out.println(maxArea(nums));
    }
}
