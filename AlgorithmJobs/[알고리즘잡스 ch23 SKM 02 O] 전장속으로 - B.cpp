#include <iostream>
#include <algorithm>
#include <cmath> // abs
using namespace std;
/*
[알고리즘잡스 ch23 SKM 02 O] 전장속으로 - B
풀이: 완탐
  //1.배열 입력
  //2.완탐: 적의 위치에서 요원의 위치까지 최단거리 계산, 저장,
  // 요원의 위치는 *로 저장
  //3.출력:
시간복잡도: O(n*n)=400
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
int n;
int a[30][30];
int curRow=0,curCol=0;// 요원의 위치

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열 입력
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>a[i][j];
      if(a[i][j]==9){// 요원이면 좌표 저장
        curRow=i;
        curCol=j;
      }
    }
  }
  //2.완탐: 적의 위치에서 요원의 위치까지 최단거리 계산, 저장,
  // 요원의 위치는 *로 저장
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(a[i][j]!=0){
        if(a[i][j]==9){
          cout<<"* ";
        }
        else{
          int dist= abs(i-curRow)+abs(j-curCol);
          cout<<dist<<" ";
        }
      }
      else {cout<<"0 ";}
    }cout<<'\n';
  }
  //3.출력:
  return 0;
}
