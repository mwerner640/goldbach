#include <primesieve.hpp>
#include <iostream>
#include <vector>
#include <ctime>

int main()
{
  unsigned long long x;
  
  std::cout << "Which number would you like to check? ";	
  std::cin >> x;
 
  clock_t begin = clock();

  if (x%2==1) {
	  std::cout << "This number is not a Goldbach number as it is odd." << std::endl;
	  return 0;
  }

  std::vector<int> primes;
  primesieve::generate_primes(x, &primes);

  primesieve::iterator lower;
  uint64_t lower_prime = lower.next_prime();

  primesieve::iterator higher;
  higher.skipto(x);
  uint64_t higher_prime = higher.prev_prime();

  while (lower_prime < higher_prime) {
	  uint64_t sum = lower_prime + higher_prime;
	  if (sum==x) {
		  clock_t end = clock();
		  std::cout << lower_prime << "+" << higher_prime << "\n Elaspsed time: " << double(end-begin) << " ticks" << std::endl;
		  return 0;
	  }
	  else if (sum<x) lower_prime = lower.next_prime();
	  else higher_prime = higher.prev_prime();
  }
  if (lower_prime*2==x) {
	  clock_t end = clock();
	  std::cout << lower_prime << "+" << lower_prime << "\n Elaspsed time: " << double(end-begin) << " ticks" << std::endl;
	  return 0;
  } else if (higher_prime*2==x) {
	  clock_t end = clock();
	  std::cout << higher_prime << "+" << higher_prime  << "\n Elaspsed time: " << double(end-begin) << " ticks" << std::endl;
	  return 0;
  } else {
	  std::cout << "It seems something went wrong." << std::endl;
  }
  
  //for (; prime < x; prime = it.next_prime())
    //std::cout << prime << std::endl;

  return 0;
}
