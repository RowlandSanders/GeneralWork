#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
//N - Number of Pies
//F - Number of Friends
int N,F;
double pi = 3.141592653589793238462643383279;
// this is what doing a leetcode hard achieves
int helper(long double middle, long double array[]){
  int front = 0;
  if (middle == 0)
    return 0;
  for(int i = 0; i < N; i++)
    front += (int)(array[i]/middle);
  if (front >= F){
    return 1;
  }
  else
    return 0;
  
}

long double binarySearch(long double array[]){
  long double init = 0, last = array[N-1], max = 0.0;
  while(last - init >= 1e-6){
    long double middle = (init + last)/2;
    if (helper(middle, array) == 1){
      init = middle;
    }
    else{
      last = middle;
      } 
    }
   return init; 
}


int main() {
  //Cases
  int cases;
  scanf("%d", &cases);
  while(cases--){
    scanf("%d %d",&N,&F);
    F++;
    int largest[N];
    for(int i=0; i<N;i++)
      scanf("%d",&largest[i]);
    long double array[N];
    sort(largest,largest+N);
    for(int i = 0; i < N; i++){
      array[i] = largest[i] * largest[i] * pi;
      long double whatever = binarySearch(array);
      printf("%.4Lf\n", whatever);
    }
  }
  return 0;
}