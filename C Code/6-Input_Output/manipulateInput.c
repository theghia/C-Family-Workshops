#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  printf("1st: %s\n", *argv);
  printf("2nd: %s\n", *(argv + 1));
  return 0;
}
