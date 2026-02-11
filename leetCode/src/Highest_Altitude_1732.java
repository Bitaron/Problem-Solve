public class Highest_Altitude_1732 {

    public static int largestAltitude(int[] gain) {
       int max =0;
       int height=0;
       for(int i=0; i<gain.length; i++){
           height = height+ gain[i];
           if(height>max){
               max = height;
           }
       }
       return max;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,1};

        System.out.println(largestAltitude(nums));
    }
}
