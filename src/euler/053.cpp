#include "euler.h"
#include "util/range.h"
#include <array>
#include <gmpxx.h>
using namespace util;
using namespace math;

// There are exactly ten ways of selecting three from five, 12345:
//
//      123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
//
// In combinatorics, we use the notation, C(5, 3) = 10.
//
// In general,
//      C(n, r) = (n!) / (r! * (n−r)!)
// , where r ≤ n, n! = n × (n−1) × ... × 3 × 2 × 1, and 0! = 1.
//
// It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
//
// How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are
// greater than one-million?

enum { nmax = 100, nmin = 23 };
typedef std::array<mpz_class, nmax+1> array_t;

void precompute_factorials(array_t & fac)
{
    mpz_class F;
    for(int n = 0; n <= nmax; ++n)
    {
        mpz_fac_ui(F.get_mpz_t(), n);
        fac[n] = F;
    }
}

std::string euler053()
{
    array_t fac;
    mpz_class limit = 1000000;
    mpz_class C;
    int cnt = 0;

    precompute_factorials(fac);
    for(auto n : range<nmin, nmax+1>())
    {
        if(n % 2 == 0)
            --cnt;
        for(auto r : range(n / 2, 0, -1))
        {
            C = fac[n] / (fac[r] * fac[n-r]);

            if(C > limit)
                cnt += 2;
            else
                break;
        }
    }

    return std::to_string(cnt);
}

static bool reg_ = euler::set("53", euler053);
