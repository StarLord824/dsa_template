import java.util.*;
import java.io.*;
public class code {
    public static void main(String[] args) {
        boolean def=true;
        // def=false;
        if(def)
        {
            try{
                System.setIn(new FileInputStream("input.txt"));
                System.setOut(new PrintStream(new FileOutputStream("output.txt")));
            } 
            catch (FileNotFoundException e){
                e.printStackTrace();
                return;
            }
        }
        Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-- >0)
		{
            int n=sc.nextInt();
            System.out.println(n);            
		}
        sc.close();
    }
}
