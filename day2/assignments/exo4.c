#include <stdio.h>
main()
{
  int a;
  int b;
  int c;

  a = 16;
  b = 2;
  c = 10;

  c += a > 0 && a <= 15 ? ++a : a/b; //if(c+a>0 && a<=15) ++a; else a/b; 
  /*
   * What about the following expression? :
   * ----------------------------------
   */
  a > 30 ? b = 11 : c = 100; //if(a>30) b=11; else c=100;
}
