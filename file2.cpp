#include <stdio.h>

int main()
{
  char str[10] = {};

  FILE *f = fopen ( "text.text", "r" );

  fscanf ( f, "%s", str );

  printf ( "%s", str );

  return 0;
}
