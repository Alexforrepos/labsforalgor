#define Deep 1000000
#include <iostream>
#include <vector>
using namespace std;

vector<int> findPrimes(int n) {
	vector<int> primes;
	for (int num = 2; num <= n; num++)
	{
		bool isPrime = true;
		for (int div = 2; div * div <= num; div++)
		{
			if (num % div == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primes.push_back(num);
		}
	}
	return primes;
}

vector<int> sieveOfEratosthenes(int n)
{
	vector<bool> isPrime(n + 1, true);
	vector<int> primes;
	isPrime[0] = isPrime[1] = false; 
	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i]) 
		{
			for (int j = i * i; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}
	return primes;
}

vector<int> segmentedSieve(int lower, int upper) 
{
	int limit = floor(sqrt(upper)) + 1;
	vector<int> primes = sieveOfEratosthenes(limit);
	vector<bool> isPrime(upper - lower + 1, true);

	for (int p : primes) 
	{
		int lowerBound = max(p * p, (lower + p - 1) / p * p);
		for (int j = lowerBound; j <= upper; j += p) {
			isPrime[j - lower] = false;
		}
	}

	vector<int> result;
	for (int i = lower; i <= upper; i++) {
		if (isPrime[i - lower]) {
			result.push_back(i);
		}
	}
	return result;
}

void Print(vector<int> obj)
{
	for (auto A : obj)
		cout << A << " ";
	cout << endl;
}



int main()
{
	//Print(findPrimes(Deep)); //1.758
	//Print(sieveOfEratosthenes(Deep)); // 1,56026
	//Print(segmentedSieve(1000, Deep)); // 1,11006a
	return 0;
}
