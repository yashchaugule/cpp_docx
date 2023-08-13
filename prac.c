#include <stdio.h>

int main() {
  int n, i, t;
  int a[100];
  printf("How many numbers you want: ");
  scanf("%d", &n);
  printf("Enter %d numbers: \n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  t = a[n - 1];
  for (i = n - 1; i > 0; i--) {
    a[i] = a[i - 1];
  }
  a[0] = t;
  printf("Rotated array: \n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");
  return 0;
}
