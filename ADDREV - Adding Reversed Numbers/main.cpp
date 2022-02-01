#include <iostream>
#include <string>
using namespace std;



int reverser(int n){
  int reversedNum = 0;
  int remainder = 0;
  while (n != 0) {
    remainder = n%10;
    reversedNum = reversedNum*10+remainder;
    n = n/10;
  }
  return reversedNum;
}

int main() {
  int num;
  cin>>num;
  string* x = new string[num];

  for(int i = 0; i < num; i++)
  {
    getline(cin,x[i]);
  }
  for(int i = 0, i < num, i++) 
  {
    for(int j = 0; j < x[i].len; j++)
    cout<<reverser(reverser(x)+reverser(y));
  }
  return 0;
}