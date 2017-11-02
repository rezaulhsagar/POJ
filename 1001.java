import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		BigDecimal b = new BigDecimal(1.0);
		int p;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			b = sc.nextBigDecimal();
			p = sc.nextInt();
			BigDecimal ans = b;
			for(int i=0;i<p-1;i++){
				ans = ans.multiply(b);
			}
			ans = ans.setScale(1000,RoundingMode.HALF_UP).stripTrailingZeros();
			String f = ans.toPlainString();
			f = f.replaceFirst("^0\\.", ".");
			System.out.println(f);
		}
		sc.close();
	}
}