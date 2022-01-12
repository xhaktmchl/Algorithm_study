#include <iostream>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch8 01 O] 팩토리얼
풀이: 팩토리얼 재귀: n!=n*(n-1)!
시간복잡도: O(n)=10???
*/
int n;

// 재귀 팩토리얼
int factorial(int i){
  // 기저사례
  if(i == 1){
    return 1;
  }
  else{//재귀
    return i*factorial(i-1);
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  cin>>n;
  cout<<factorial(n)<<'\n';
  return 0;
}
