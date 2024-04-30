ll serie(int n){
    if (n == 1 || n == 0){
        return 1;
    }
        return serie(n-1) + serie(n-2);
}
