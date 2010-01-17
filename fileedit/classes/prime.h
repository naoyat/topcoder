///
/// primes
///
vector<int> primes;
char *is_prime = NULL;

void dealloc_sieve() {
  if (is_prime) { free((void*)is_prime); is_prime = NULL; }
}

int prepare_primes_until(int till) {
  is_prime = (char *)malloc(1+till);
  if (!is_prime) return -1;
  memset((void*)is_prime, 1, 1+till);
  primes.clear();

  for (int i=2; i<=till; i++){
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j=i*2; j<=till; j+=i) is_prime[j] = false;
    }
  }
  return primes.size();
}

//
// 素数判定（Miller-Rabin)
//
long long random(long long n)
{
  return (long long)rand() % n;
}

long long check_nontrivial_sqrt_1(long long m, long long a)
{
  long long r = (a * a) % m;
  return (1LL < a && a < m-1 && r == 1)? 0LL : r;
}

long long expmod(long long base, long long exp, long long m)
{
  if (exp == 0)
    return 1LL;
  else if (!(exp & 1))
    return check_nontrivial_sqrt_1(m,expmod(base,exp/2,m));
  else
    return (base*expmod(base,exp-1,m)) % m;
}

bool miller_rabin_test(long long n)
{
  return expmod((1LL+random(n-1)),n-1,n) == 1LL;
}

bool fast_prime(long long n, int times=3)
{
  if (n == 1) return false;
  if (n == 2) return true;
  else if (!(n & 1)) return false;

  for (int i=times; i>0; i--)
        if (!miller_rabin_test(n)) return false;
  return true;
}
