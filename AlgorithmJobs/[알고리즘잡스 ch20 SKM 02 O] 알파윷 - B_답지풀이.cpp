#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch20 SKM 02 O] 알파윷 - B_답지풀이
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
int a[MAX]={0,5,10,15,20,50,30,35,40,45,100,55,60,65,70,75,80,85,90,95,500,1000};
int dist[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.판 배열 저장
  //2.입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>dist[i];
  }
  //3.n번 이동
  int idx=0;
  for(int i=0;i<n;i++){//판에서 idx+이동할 칸 수 로 이동 
    idx+=dist[i]; // 인덱스 이동
    if(idx>=21){ idx=21;} 
    cout<<a[idx]<<" ";
    if(idx==21){ break;} // 도착지 넘어가면 중지
  }
  // 출력
  return 0;
}
