// 열혈 자료구조 p.58
#include <stdio.h>

int Fibo(int n) {
    
    printf("func call param %d\n", n);

    if(n==1) {
        return 0;
    }

    else if(n==2) {
        return 1;
    }

    else /* n >= 3 */ {
        return (Fibo(n-1) + Fibo(n-2));
    }
}

int main(void) {

    Fibo(7);

    return 0;
}