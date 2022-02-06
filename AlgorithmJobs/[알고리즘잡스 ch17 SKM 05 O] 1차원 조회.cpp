#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch17 SKM 05 O] 1차원 조회
풀이: 완탐
  //1.수열입력
  //2.0~n-1 까지 바로다음 인덱스와 일치하는지 탐색
  //3.범위 안에 있고 일치하면 1출력 아님 0출력
시간복잡도: O(n)=1000
*/
#define MAX 1010
int n;
int a[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.수열입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  //2.0~n-1 까지 i-1,i+1인덱스와 일치하는지 탐색
  for(int i=0;i<=n-1;i++){
    //3.범위 안에 있고 일치하면 1출력 아님 0출력
    if((i<=n-2 && a[i]==a[i+1]) || (i>=1 && a[i]==a[i-1])){
      cout<<1<<" ";
    }
    else { cout<<"0 ";}
  }
  return 0;
}
