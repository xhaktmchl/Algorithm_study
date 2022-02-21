#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch23 SKM 01 O] 전장속으로 - A
풀이: 완탐
  //1.배열 입력
  //2.완탐: 왼쪽 위부터 
  //최솟값이면 좌표 저장, 갱신
  //3.출력: 최소값 행,렬
시간복잡도: O(n*n)=400
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n;
int a[30][30];
int resultMin=987987987;
int resultRow=0,resultCol=0;

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열 입력
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>a[i][j];
    }
  }
  //2.완탐: 왼쪽 위부터 
  //최솟값이면 좌표 저장, 갱신
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(a[i][j]!=0 && a[i][j] < resultMin){
        resultRow=i;
        resultCol=j;
        resultMin=a[i][j];
      }
    }
  }
  //3.출력: 최소값 행,렬
  cout<<resultRow<<" "<<resultCol<<'\n';
  return 0;
}
