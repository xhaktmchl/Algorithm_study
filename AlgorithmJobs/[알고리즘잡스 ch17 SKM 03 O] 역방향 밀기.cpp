#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch17 SKM 03 O] 역방향 밀기
풀이: 완탐
  //1.수열 입력
  //2.배열 1칸씩 왼쪽으로 밀기 k번 반복
  //a[0] 따로 저장
  //a[n-1]에 따로 저장해놓은 값 밀기
  //3. 출력: k번 밀린 배열 출력
시간복잡도: O(n*k)=100만 
*/
#define MAX 1010
int n,k;
int a[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

  //1.수열 입력
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i];  
  }
  //2.배열 1칸씩 왼쪽으로 밀기 k번 반복
  for(int i=0;i<k;i++){
    int tp=a[0];//a[0] 따로 저장
    for(int j=0;j<n;j++){
      a[j]=a[j+1];
    }a[n-1]=tp;//a[n-1]에 따로 저장해놓은 값 밀기
  }
  //3. 출력: k번 밀린 배열 출력
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
