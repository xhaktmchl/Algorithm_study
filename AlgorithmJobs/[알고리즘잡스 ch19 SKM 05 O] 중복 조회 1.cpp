#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch19 SKM 05 O] 중복 조회 1
풀이: 구현 이동
  //1.사람 위치 입력
  //2.배열에 사람수 카운트
  //3.완탐으로 사람한명인곳 카운트
  //4.출력: 혼자있는 사람 수
시간복잡도: O(x*y)=10000 
주의: 이동 문제에선 if if if로 하면 갱신된 것이 다시 if 로 검사돼서 elseif로 해야 함
*/
#define MAX 110
int n,y,x,cnt=0;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.사람 위치 입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>y>>x;
    a[y][x]++;//2.배열에 사람수 카운트
  }
  
  
  //3.완탐으로 사람한명인곳 카운트d
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++){
      if(a[i][j]==1){
        cnt++;
      }
    }
  }
  //4.출력: 혼자있는 사람 수
  cout<<cnt<<'\n';
  return 0;
}
