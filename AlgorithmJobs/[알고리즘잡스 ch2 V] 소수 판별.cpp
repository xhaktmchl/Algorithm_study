#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch2 V] 소수 판별
풀이: 
시간복잡도: O()
*/
#define MAX 20001
int n;
int prime[MAX];
// 에라토스 테네스 체
void eratos(){
  prime[0] = prime[1] = 1;
  for(int i=2;i*i<MAX;i++){
    for(int j=i*2;j<MAX;j+=i){
      prime[j]=1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>n;
  eratos();
  if(prime[n]== 1){cout<<"NO"<<'\n';}
  else {cout<<"YES"<<'\n';}
  return 0;
}
