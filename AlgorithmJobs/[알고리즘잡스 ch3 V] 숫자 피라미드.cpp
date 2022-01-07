#include <iostream>
using namespace std;
/*
[알고리즘잡스 ch3 V] 숫자 피라미드
풀이: 배열에 1~9 까지 저장하고 인덱스 미리 게산해서 역순, 정순 출력
시간복잡도: O()=
풀이2: 출력될 숫자 배열에 저장시켜서 역순출력
시간복잡도: O(n*n)=10000
*/
int n,s;
int a[201];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  cin>>n>>s;
  for(int i=1;i<=n;i++){
    // 빈칸출력
    for(int k=1;k<=n-i;k++){
      cout<<" ";
    }
    // 숫자 출력
    // 짝수 행
    if(i%2 == 0){
      for(int k=1;k<=2*i-1;k++){
        cout<<s;
        s++;
        if(s >=10){s=1;}
      }
    }
    else{// 홀수행 
      for(int k=1;k<=2*i-1;k++){ // 배열에 저장
        a[k] = s;
        s++;
        if(s >=10){s=1;}
      }
      for(int k=2*i-1;k>=1;k--){ // 배열에 저장
        cout<<a[k];
      }
    }
    cout<<'\n';
  }
  return 0;
}
