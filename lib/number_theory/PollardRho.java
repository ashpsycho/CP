import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.stream.*;
import java.util.function.*;

public class PollardRho{
	public long n;
	
	long gcd(long a, long b){
		long c;
		if(b>a){
			c=b;
			b=a;
			a=c;
		}
		while(b!=0){
			c = a%b;
			a = b;
			b = c;
		}
		return a;
	}	

	long g(long x){
		return (x*x + 1)%n;
	}

	long g2(long x){
                return (x*x + n - 1)%n;
        }

 	private long getNext(int starter, Function<Long,Long> g){
		long x=starter,y=starter,d=1;
                while(d == 1){
                        x = g.apply(x);
                        y = g.apply(g.apply(y));
                        d = gcd(n,Math.abs(x-y));
                }
                return d;
	}

	long getNext(){
		int i,primes []= {2,3,4,5,6}; 
		long d;
		for(i=0;i<primes.length;i++){
			d = getNext(primes[i],this::g);
			if(d!=n)return d;
			d = getNext(primes[i],this::g2);
			if(d!=n)return d;
		}
		return n;
	}

	public List<Long> primeFactors(){
		List<Long> factors = new ArrayList<>();
		while(n!=1){
			long factor = getNext();
			
			factors.add(factor);
			while((n%factor)==0)n = n/factor;
		}
		return cleanUp(factors);
	}

	public static void main(String args[])throws Exception{
		Scanner scanner = new Scanner(System.in);
		PollardRho rho = new PollardRho();
		while(scanner.hasNextLong()){
			long n = scanner.nextLong();
			rho.n = n;
			List<Long> factors = rho.primeFactors();
			factors.stream().forEach(factor -> System.out.print(factor + " "));
			System.out.println();
		}
	}
}
