#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch2 O] 짝수 판별하기
풀이: 
시간복잡도: O()
*/
int n;
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>n;
  if(n%2==0){cout<<"even"<<'\n';}
  else {cout<<"not even"<<'\n';}
  return 0;
}
