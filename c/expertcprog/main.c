#include <stdio.h>

//#define peach int;
//unsigned peach i;

//typedef int banana;
//banana j;
//unsigned banana j;    // error

char ga[] = "aabbccdd";
void func_ca(char ca[])
{
    printf("&ca = %p, &(ca[0]) = %p, &(ca[1]) = %p\n", &ca, &(ca[0]), &(ca[1]));
}

void func_pa(char *pa)
{
    printf("&pa = %p, &(pa[0]) = %p, &(pa[1]) = %p, ++pa = %p\n", &pa, &(pa[0]), &(pa[1]), ++pa);
}

int main(int argc, char *argv[])
{
    char *p = "breadfruit";
//    float *pip = 3.14;    // error

    char ca[] = "abcde";
    char *pa = "xyz";

    int a;
    int b;
    printf("The stack top is near %p\n", &a);
    printf("The stack next is near %p\n", &b);

    printf("%lu\n", sizeof('a'));
    printf("%lu\n", sizeof(&a));
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(unsigned short));
    printf("%lu\n", sizeof(unsigned int));
    printf("%lu\n", sizeof(unsigned long));


    func_ca(ca);
    func_pa(pa);
    func_ca(ga);
    func_pa(ga);

    printf("Hello World!\n");
    return 0;
}
