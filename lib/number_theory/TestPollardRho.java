import java.io.*;
import java.util.*;
class TestPollardRho{
	
	List<Long> factorize(long n){
		List<Long> factors = new ArrayList<>();
		for(long i=3;(i*i)<=n;i+=2){
			if((n%i)!=0)continue;
			factors.add(i);
			while((n%i) == 0) n=n/i;
		}
		if( n != 1) factors.add(n);
		Collections.sort(factors);
		return factors;
	}	

	public static boolean areEqualLists(List<Long> a, List<Long> b){
		if(a.size() != b.size()) return false;
		for(int i=0;i<a.size();i++)if((long)a.get(i) != (long)b.get(i)) return false;
		return true;
	}

	public static void main(String args[]){
		PollardRho rho = new PollardRho();
		TestPollardRho testRho = new TestPollardRho();
		int failures = 0;
		for(long i=3;failures<100;i+=2){
			if((i%10000)==1)
				System.out.println("Reached "+i);
			rho.n = i;
			List<Long> rhoFactors = new ArrayList(rho.primeFactors());
			Collections.sort(rhoFactors);
			if(!areEqualLists(testRho.factorize(i),rhoFactors)){
				System.out.println("Failed for: "+i);
				System.out.println(rhoFactors.toString());
				System.out.println(testRho.factorize(i).toString());
                                failures++;
			}
		} 
	}
}
