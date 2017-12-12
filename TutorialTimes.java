import java.util.*;
public class TutorialTimes {
    
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int rows = scan.nextInt();

    int arr[][] = new int[rows][2];

    for(int i = 0; i<rows; i++){
      for(int j = 0; j<2; j++){
        arr[i][j] = scan.nextInt();
      }
    }

    sort(arr);

    int left = arr[1][0];
    int max = arr[0][1];
    int count = 1;
    int right = arr[1][1];

    for(int i = 0; i<rows; i++){
      left = arr[i][0];
      right = arr[i][1];

      if(left>max) {
        count++;
        max = right;
      }
    }

    System.out.println(count);



  }

  public static void sort(int arr[][]){
    for(int i = 1; i<arr.length; i++){
      for(int j = 0; j<arr.length-1; j++){
        if(arr[j][1]>arr[j+1][1]){
          int l = arr[j][0];
          int r = arr[j][1];
          arr[j][0] = arr[j+1][0];
          arr[j][1] = arr[j+1][1];
          arr[j+1][0] = l;
          arr[j+1][1] = r;
        }
      }
    }
  }
}