function printPrimes(limit) {
    const primes = new Array(limit+1).fill(true);
  
    // 0 and 1 are not prime
    primes[0] = false;
    primes[1] = false;
  
    for (let i = 2; i <= limit; i++) {
      if (primes[i]) {
        console.log(i);
        let j = i * i;
        while (j <= limit) {
          primes[j] = false;
          j += i;
        }
      }
    }
  }
  
  printPrimes(100000000);
  