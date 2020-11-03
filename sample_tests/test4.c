int nest(int x) {
  int i;
  int j;
  int k;
  k = 0;
  for ( i = 1; i <= 5; i += 1) {
    for (j = 1; j <= 5; j += 1) {
      if (j % 2 == 0) {
        k = k - i + j;
      } else {
        while (k < 50) {
          k = k + i + j;
        }        
      }
      
    }
  }
  do {
    k -= 2;
  } while (k > 0);
  return k;
}

main() {
  printf("==> %d\n",nest(3));
}
