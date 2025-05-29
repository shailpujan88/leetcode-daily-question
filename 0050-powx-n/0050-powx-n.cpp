class Solution {
public:

// pow(x,n)
    double myPow(double x, int n) {
        if (n == 0) return 1.0;

        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }

private:
    double power(double x, long long n) {
        if (n == 0) return 1.0;

        double half = power(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};

// power(2.0, 5)
//     → n = 5, not zero
//     → half = power(2.0, 2)

//         power(2.0, 2)
//             → n = 2
//             → half = power(2.0, 1)

//                 power(2.0, 1)
//                     → n = 1
//                     → half = power(2.0, 0)

//                         power(2.0, 0)
//                             → base case, return 1

//                     → half = 1
//                     → n is odd → return 1 * 1 * 2.0 = 2.0

//             → half = 2.0
//             → n is even → return 2.0 * 2.0 = 4.0

//     → half = 4.0
//     → n is odd → return 4.0 * 4.0 * 2.0 = 32.0
