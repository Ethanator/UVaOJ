#include<bitset>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

bitset<1000001>bs;
vector<long>primes;
map<long,bool>isPrime;
 
void sieve(long upper_bound){
	bs.set();
	bs[0]=bs[1]=0;
	for(long i=2;i<=upper_bound+1;i++){
		if(bs[i]){
			for(long j=i*i;j<=upper_bound+1;j+=i)bs[j]=0;
			primes.push_back(i);
			isPrime[i] = true;
		}							    
	}
}

int main(){
	long n;
	sieve(1000000);
	for(;;){
		scanf("%ld",&n);
		if(!n)break;
		long i=1;
		for(;i<primes.size();i++){
			if(primes[i]>n/2)break;
			if(isPrime[n-primes[i]])break;
		}
		printf("%ld = %ld + %ld\n",n,primes[i],n-primes[i]);
	}
}
