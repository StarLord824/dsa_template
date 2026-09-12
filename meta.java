import java.util.Scanner;
public class meta {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int product = 1, sum = 0;
        while(true){
            System.out.println("Enter the number:");
            int n = sc.nextInt();
            if(n==0){
                break;
            }else{
                if(n>=0){
                    product*=n;
                }else{
                    sum+=n;
                }
            }
        }
        System.out.println("Product of positive integers: "+product);
        System.out.println("Sum of negative integers: "+sum);
    }    
}