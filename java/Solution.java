import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.stream.*;
import java.util.function.*;

class Solution{
	public long n,factor;
	
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

	long squar(long x){
		long breaker=1<<20, small_x = x>>20;
		return (x*(x&(breaker-1)) + (((x*small_x)%n)<<20));
	}

	long g(long x){
		return (squar(x) + 1)%n;
	}

	long g2(long x){
                return (squar(x) + n - 1)%n;
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
		int i,primes []= {2,4}; 
		long d;
		for(i=0;i<primes.length;i++){
			d = getNext(primes[i],this::g);
			if(d!=n)return d;
			d = getNext(primes[i],this::g2);
			if(d!=n)return d;
		}
		return n;
	}

	public Set<Long> primeFactors(){
		Set<Long> factors = new HashSet<>();
		Queue<Long> maybeFactors = new ArrayDeque<>();
		if((n%2)==0)factors.add(2L);
		while((n%2)==0)n/=2;
		if(n==1)return factors;
		maybeFactors.add(n);
		
		while(maybeFactors.size()>0){
			n = maybeFactors.remove();
			factor = getNext();
			if(n == factor){
				factors.add(n);
				continue;
			}
			while((n%factor)==0)n/=factor;
			if(n!=1)maybeFactors.add(n);
			maybeFactors.add(factor);
		}
		return factors;
	}

	public static void main(String args[])throws Exception{
		Scanner scanner = new Scanner(System.in);
		Solution rho = new Solution();
		int te = scanner.nextInt();
		long mod = 1000000007L;
		while(te>0){
			te--;
			long ans=1 , n = scanner.nextLong();
			rho.n = n;
			Set<Long> factors = rho.primeFactors();
			for(long factor: factors){
				ans=(ans*(factor+1))%mod;
			}
			System.out.println(ans);
		}
	}
}
