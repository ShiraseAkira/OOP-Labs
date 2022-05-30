#include "GeneratePrimeNumbersSet.h"
#include <vector>
#include <set>

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::set<int> primeNumbers;
	std::vector<bool> sieve(upperBound + 1, true);

	if (upperBound > 1) {
		sieve[0] = false;
		sieve[1] = false;

		for (int i = 2; i <= upperBound; i++) {
			if (sieve[i]) {
				primeNumbers.insert(i);
				for (int j = 2 * i; j <= upperBound; j += i) {
					sieve[j] = false;
				}
			}
		}
	}
	
	return primeNumbers;
}