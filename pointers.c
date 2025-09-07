#include <stdio.h>

int main(){
 int a,b,*p;

 p = &a;

 if( p == &b)
    printf("%p == %p",p,&b);
 else
    printf("%p != %p", p, &b);   

return 0;
}
