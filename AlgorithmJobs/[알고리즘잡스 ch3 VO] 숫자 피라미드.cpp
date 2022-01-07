#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch3 VO] 숫자 피라미드
풀이: 배열에 1~9 까지 저장하고 인덱스 미리 게산해서 역순, 정순 출력 -> 계산 복잡해짐
시간복잡도: O()=
풀이2: 출력될 숫자 배열에 저장시켜서 역순출력, 
시간복잡도: O(n*n)=10000
*/
int n,s,cur;
int a[201];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>n>>s;
  cur=s;
  // 1.1~n 번 줄 반복
  for(int i=1;i<=n;i++){
    // 빈칸출력
    for(int j=1;j<=n-i;j++){
      cout<<" ";
    }
    // 숫자 배열에 저장
    for(int j=1;j<=i*2-1;j++){
      a[j]=cur;
      cur++;
      if(cur==10) cur=1;
    } 
    // 홀수출 역순출력
    if(i%2==1){
      for(int j=i*2-1;j>=1;j--){
        cout<<a[j];
      }cout<<'\n';
    }//짝수출 정순출력
    if(i%2==0){
      for(int j=1;j<=i*2-1;j++){
        cout<<a[j];
      }cout<<'\n';
    }
  }
  return 0;
}
