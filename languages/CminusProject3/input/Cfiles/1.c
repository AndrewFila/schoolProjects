#include <stdio.h>

int a;

int main() {
  printf("enter a: ");
  scanf("%d", &a);

  if (a != 0) {
    printf("%d is not 0\n", a);
  }
  printf("complete\n");
}
