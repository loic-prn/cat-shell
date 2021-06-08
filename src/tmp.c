#include <stdio.h>
#include <stdarg.h>

int somme(int a, ...){
  int ret = 0, i = 0, max = a;
  va_list ap;
  va_start(ap, a);
  int c = 0;
  while(i < max){
    c = va_arg(ap, int);
	printf("%d\n",c);
    ret += c;
    ++i;
  }
  va_end(ap);
  return ret;
}

int main(){
  printf("la somme est : %d \n", somme(10,11,12,5,6));
  return 0;
}
