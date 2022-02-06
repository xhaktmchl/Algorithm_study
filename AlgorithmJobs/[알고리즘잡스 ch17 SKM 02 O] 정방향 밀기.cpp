#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch17 SKM 02 O] 정방향 밀기
풀이: 
  //1.수열입력
  //2.배열 한칸씩 밀기
  //n-1인덱스 원소값은 따로 저장
  // 0번째에 저장한 값 넣기
  //3.밀린 배열 출력
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
  //2.배열 한칸씩 밀기
  int tp=a[n-1];
  for(int i=n-1;i>=0;i--){
    a[i+1]=a[i];
  }
  a[0]=tp;
  //n-1인덱스 원소값은 따로 저장
  // 0번째에 저장한 값 넣기
  //3.밀린 배열 출력
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
