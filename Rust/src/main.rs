fn main() {
    let limit = 100000000;
    let mut primes = vec![true; limit+1];

    // 0 and 1 are not prime
    primes[0] = false;
    primes[1] = false;

    for i in 2..limit+1 {
        if primes[i] {
            println!("{}", i);
            let mut j = i * i;
            while j <= limit {
                primes[j] = false;
                j += i;
            }
        }
    }
}
