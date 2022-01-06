#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch2 O] 짝수의 합 구하기
풀이: 
시간복잡도: O()
*/
int n,sum=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>n;
  for(int i=1;i<=n;i++){
    if(i%2==0){
      sum+= i;
    }
  }
  cout<<sum<<'\n';
  return 0;
}
