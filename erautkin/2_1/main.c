#include <stdio.h>
int func1(int x);
int func2();
int (*ptr1)(int x);
int (*ptr2)(int (*ptr1)());
int x=2;
int main() {
    // Write C code here
    printf("Hello world");
   ptr1=func1;
   // ptr1(x);
   ptr2=func2;
   ptr2(func2);
   printf("%d", x);
    return 0;


}
int func1(int x) {
    ++x;
}

int func2() {
    ptr1(x);
}
