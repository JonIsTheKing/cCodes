#include <stdio.h>
// function to calculate whether prime or not
int isPrime(int n);

int main() {
  // N = user input, num = value of each cell
  // x,y to iterate 2D array 
  int N,x,y, num=0;
  printf("Enter the size of array\n");
  scanf("%d", &N);

  // declaration of 2D array with user input size
  int arr[N][N]; 

  // assigning each cell in array a value 
  for(x=0;x<N;x++) {
    for(y=0;y<N;y++) {
      num = num + 1;
      arr[x][y] = num;
    }
  }
  // l = left, r= right, t= top, d= down
  int l,r,t,d, beautyScore;
  beautyScore = 0;

  for(x=0;x<N;x++) {
    for(y=0;y<N;y++) {
      if((x-1)<N && (x-1)>=0) {
        // top value of cell
        t = arr[x-1][y];
        beautyScore = beautyScore + isPrime(t);
      }
      if((x+1)<N) {
        // down value of cell
        d = arr[x+1][y];
        beautyScore = beautyScore + isPrime(d);
      }
      if((y-1)<N && (y-1)>=0) {
        // left value of cell
        l = arr[x][y-1];
        beautyScore = beautyScore + isPrime(l);
      }
      if((y+1)<N) {
        // right value of cell
        r = arr[x][y+1];
        beautyScore = beautyScore + isPrime(r);
      }
    }
  }
  printf("b=%d\n",beautyScore);
  return 0;
}

// function checks a number prime or not 
// returns 1 if true, 0 if not a prime 
int isPrime(int num) {
  int i, check=0;
  for (i = 2; i <= num / 2; ++i) {
    if (num % i == 0) {
      check = 1;
      break;
    }
  }

  if (num == 1) {
    // 1 is not a prime number
    return 0;
  }
  else {
    if (check == 0){
      // is a prime number
      return 1;
    }
    else
      // not a prime number
      return 0;
  }
}
