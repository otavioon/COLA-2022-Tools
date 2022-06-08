#include <bits/stdc++.h>

using prime_factors_t = std::multiset<int64_t>;

int digitCount(int64_t n) {
  int ret = 1;
  while (n >= 10) {
    n /= 10;
    ret++;
  }
  return ret;
}

template <size_t N, size_t MaxPrimeSize>
struct primes_t {
  constexpr static size_t maxPrimeSize = MaxPrimeSize;
  constexpr primes_t() : primes(), count(), notSieves() {
    primes[count++] = 2;
    notSieves[0] = notSieves[1] = true;
    for (int i = 2; i < N; i++) {
      if (notSieves[i]) {
        continue;
      }
      primes[count++] = i;
      for (int64_t j = 2; i * j < N; j++) {
        notSieves[i * j] = true;
      }
    }
  }
  int64_t primes[MaxPrimeSize];
  int count;

 private:
  bool notSieves[N];
};

static constexpr auto primes = primes_t<100001, 9593>{};

prime_factors_t primeFactors(int64_t n) {
  prime_factors_t ret;
  int const maxPrimeCandidate = static_cast<int>(ceil(sqrt(n * 1.0)));
  for (int i = 0; n > 1 && i < primes.count; i++) {
    auto const prime = primes.primes[i];
    if (prime > maxPrimeCandidate) {
      break;
    }
    while (n % prime == 0) {
      ret.insert(prime);
      n /= prime;
    }
  }
  if (n > 1) {
    ret.insert(n);
  }
  return ret;
}

int solve(int64_t n) {
  if (n == 1) {
    return 1;
  }
  prime_factors_t factorsOfN = primeFactors(n);
  if (factorsOfN.size() == 1) {
    return std::max(digitCount(n), digitCount(1));
  }
  for (int i = static_cast<int>(ceil(sqrt(n * 1.0)));; i--) {
    prime_factors_t const factors = primeFactors(i);
    bool intersects = true;
    for (auto const factor : factors) {
      if (factorsOfN.count(factor) < factors.count(factor)) {
        intersects = false;
        break;
      }
    }
    if (intersects) {
      return std::max(digitCount(i), digitCount(n / i));
    }
  }
}

int main() {
  int64_t n;
  std::cin >> n;
  static_assert(primes.count <= primes.maxPrimeSize);
  std::cout << solve(n) << std::endl;
  return 0;
}
