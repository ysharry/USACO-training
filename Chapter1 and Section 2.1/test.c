#include <stdio.h>
#include <stdlib.h>

struct inside{
    int c;
};

struct something{
    int a;
    int b;
    struct inside c;
};

void function(struct something ST){
    printf("%d\n", ST.a);
}

int main(){
    struct something ST;
    struct inside IN;
    IN.c = 3;
    ST.a = 1;
    ST.b = 2;
    ST.c = IN;
    function(ST);
    struct something ST2 = ST;
    ST2.c.c = 10;
    printf("%d\n", ST2.c.c);

}