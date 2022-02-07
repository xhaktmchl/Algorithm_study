#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch18 SKM 03 O] 1차원 확산
풀이: 완탐,구현
  //1.배역입력
  //경계처리: 양끝 -1채우기
  //2.완탐 0부터 n-1까지 좌우, 0인지 검사
  // 0있으면 1 정답배열에 저장 
  //3.정답배열 출력
시간복잡도: O(n)= 1000
*/
#define MAX 1010
int n;
int a[MAX],answer[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배역입력
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    answer[i]=a[i];
  }
  //경계처리 패딩: 양끝 -1채우기
  a[0]=-1; a[n+1]=-1;
  //2.완탐 0부터 n-1까지 좌우, 0인지 검사
  for(int i=1;i<=n;i++){
    if(a[i]==1){// 0있으면 1 정답배열에 저장 
      if(a[i-1]==0){ answer[i-1]=1;}
      if(a[i+1]==0){ answer[i+1]=1;}
    }
  }
  
  //3.정답배열 출력
  for(int i=1;i<=n;i++){
    cout<<answer[i]<<" ";
  }
  return 0;
}
