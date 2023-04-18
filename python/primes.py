def print_primes(limit):
    primes = [True] * (limit+1)

    # 0 and 1 are not prime
    primes[0] = False
    primes[1] = False

    for i in range(2, limit+1):
        if primes[i]:
            print(i)
            j = i * i
            while j <= limit:
                primes[j] = False
                j += i

print_primes(100000000)
