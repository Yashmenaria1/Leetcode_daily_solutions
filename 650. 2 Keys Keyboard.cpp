class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    int isDiv(int num) {
        int largest = 1; 
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                largest = i;
            }
        }
        return largest;
    }

    int minSteps(int n) {
        if (n <= 1) return 0;
        if (isPrime(n)) return n;

        int a = isDiv(n); 
        return minSteps(a) + (n / a);
    }
};
