

double myPow(double x, int n){
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    if (n % 2 == 0) {
        if (n < 0) {
            if (n == INT_MIN) {
                n += 1;
            }
            return 1 / (myPow(x * x, (-n) / 2));
        }
        return myPow(x * x, n / 2);
    }
    if (n < 0) {
        return 1 / (x * myPow(x, -n - 1));
    }
    return x * myPow(x, n - 1);
}
