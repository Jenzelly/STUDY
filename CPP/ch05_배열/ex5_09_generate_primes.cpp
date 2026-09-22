/*
문제 5.9
n보다 작은 모든 소수 나열하기
*/

#include <vector>
#include <deque>
#include <cmath>
using namespace std;

//n이 주어졌을 때, n보다 작거나 같은 모든 소수를 반환하라.
vector<int> GeneratePrimes(int n)
{
    vector<int> primes;

    //is_prime[p]는 p가 소수인지 아닌지 나타낸다.
    //초기에는 0과 1을 제외한 나머지를 모두 참으로 세팅한다.
    //그 다음에 소수가 아닌 숫자들을 걸러 낸다.
    deque<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p<=n; ++p)
    {
        if(is_prime[p])
        {
            primes.emplace_back(p);

            //p의 배수를 걸러 낸다.
            for (int i = p*2; i <= n; i +=p)
            {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}


//n이 주어졌을 때, n보다 작거나 같은 모든 소수를 반환하라.
vector<int> GeneratePrimes2(int n)
{
    if(n<2)
    {
        return {};
    }

    const int sieve_size = floor(0.5 * (n-3)) + 1;
    vector<int> primes;
    primes.emplace_back(2);

    deque<bool> is_prime(sieve_size, true);
    for(int i=0; i<sieve_size; ++i)
    {
        if(is_prime[i])
        {
            int p = (i*2) + 3;
            primes.emplace_back(p);

            for(long long j = 2LL*i*i+6*i+3; j<sieve_size; j+=p)
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}