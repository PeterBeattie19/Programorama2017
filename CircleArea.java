import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        
        int n = Integer.parseInt(br.readLine()); 
        
        System.out.print(n*n +" pi"); 
    }
}