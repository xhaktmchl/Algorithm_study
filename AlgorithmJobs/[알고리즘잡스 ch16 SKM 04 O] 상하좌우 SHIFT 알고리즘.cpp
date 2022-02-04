#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch16 SKM 04 O] 상하좌우 SHIFT 알고리즘
풀이: 
  //1.배열입력
  //2.출력: 방향에 따라 동서남북 +r 원소값 출력
시간복잡도: O(1) 
*/
#define MAX 110
int n,m,y,x,d,r;
int a[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  //1.배열입력
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  cin>>y>>x>>d>>r;
  //2.출력: 방향에 따라 동서남북 +r 원소값 출력
  if(d==0){//동
    cout<<a[y][x+r]<<'\n';
  }
  if(d==1){//서
    cout<<a[y][x-r]<<'\n';
  }
  if(d==2){//남
    cout<<a[y+r][x]<<'\n';
  }
  if(d==3){//북
    cout<<a[y-r][x]<<'\n';
  }
  return 0;
}
