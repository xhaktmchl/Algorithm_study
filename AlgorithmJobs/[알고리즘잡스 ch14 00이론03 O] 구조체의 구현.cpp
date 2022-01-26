#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch14 00이론03 O] 구조체의 구현
풀이:
시간복잡도: 
*/
/*
  ### 캠슐화
  : 내부구조가 어떻게 돌아가는지는 몰라도 된다
  
  ### 구조체
  1.개념
  - 캡슐화를 구현하기위한 방법
  - Type을 정의함
  */
  
typedef struct Point {
  int a;
  int b;
  
  int sum(){
    return a+b;
  }
}P;

int main() {

  P p1,p2;
  p1.a=1;
  p1.b=2;
  
  p2.a=2;
  p2.b=3;
  
  cout<<p1.sum()<<'\n';
  cout<<p2.sum()<<'\n';
  return 0;
}
