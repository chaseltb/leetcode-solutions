class HelloWorld {
    static ulong[] generateFibonaccis(int n) {
        ulong[] fib = new ulong[n];
        fib[0] = 1;
        fib[1] = 1;
        for (int i = 2; i < n; ++i) {
            fib[i] = fib[i - 2] + fib[i - 1];
        }
        return fib;
    }
    static void Main() {
        int n = 10;
        ulong[] fib = generateFibonaccis(n);
        for (int i = 0; i < n; i++) {
            System.Console.Write(fib[i] + " ");
        }
    }
}
