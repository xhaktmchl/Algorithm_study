#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch20 SKM 02 O] 알파윷 - B
풀이: 구현,완탐
  //1.판 배열 저장
  //2.입력
  //3.n번 이동
  //판에서 idx+이동할 칸 수 로 이동 
  // 마지막 칸 넘어가는 경우
  // 칸 이동하는 경우
  // 인덱스 갱신
  // 출력
시간복잡도: O()=
런타임 에러 원인 유형
1.입력 잘못
2.선언하지 않은 배열 참조
3.무한루프
*/
#define MAX 100
int n,sum=0;
int a[MAX];
int dist[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.판 배열 저장
  a[0]=0; a[1]=5; a[2]=10; a[3]=15; a[4]=20; a[5]=50; a[6]=30; a[7]=35; a[8]=40; 
  a[9]=45; a[10]=100; a[11]=55; a[12]=60; a[13]=65; a[14]=70; a[15]=75; a[16]=80;
  a[17]=85; a[18]=90; a[19]=95; a[20]=500; a[21]=1000;
  //2.입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>dist[i];
  }
  //3.n번 이동
  int idx=0;
  for(int i=0;i<n;i++){//판에서 idx+이동할 칸 수 로 이동 
    if(idx+dist[i]>=21){ // 마지막 칸 넘어가는 경우
      cout<<a[21]<<" ";
      break;
    } 
    // 칸 이동하는 경우
    cout<<a[idx+dist[i]]<<" ";
    idx+=dist[i];// 인덱스 갱신
  }
  // 출력
  return 0;
}
