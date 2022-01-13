#include <iostream>
using namespace std;
/*
[알고리즘잡스 part5 OOO] bingo
풀이1: 완탐
시간복잡도: O(n^4)=5^4
주의: 빙고 5개로 착각해서 시간 걸림
*/
#define MAX 6
int a[MAX][MAX], b[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  // 배열 입력
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      cin>>a[i][j];
    }
  }
  // 1.반복으로 부르는 숫자 입력
  for(int i=0;i<25;i++){
    int num;
    cin>>num;
    // 2.숫자 탐색, 완탐
    for(int j=0;j<5;j++){
      for(int k=0;k<5;k++){
        if(a[j][k] == num){// 숫자 찾으면
          b[j][k]=1;// 3.빙고판 x 표시
        }
      }
    }
    // 가로빙고 탐색
    int bingo=0;
    for(int j=0;j<5;j++){
      int cnt=0;
      for(int k=0;k<5;k++){
        cnt+= b[j][k];
      }
      if(cnt==5){
        bingo++;
      }
    }
    // 세로빙고 탐색
    for(int j=0;j<5;j++){
      int cnt=0;
      for(int k=0;k<5;k++){
        cnt+= b[k][j];
      }
      if(cnt==5){
        bingo++;
      }
    }
    // 오른위 대각선 빙고 탐색
    if(b[4][0]==1 && b[3][1]==1 &&b[2][2]==1 &&b[1][3]==1 &&b[0][4]==1){
      bingo++;
    }
    // 왼 대각선 빙고 탐색
    if(b[0][0]==1 && b[1][1]==1 &&b[2][2]==1 &&b[3][3]==1 &&b[4][4]==1){
      bingo++;
    } 
    //빙고 3개 넘으면 저장
    if(bingo>=3){
      cout<<i+1<<'\n';
      return 0;
    }
  }
  return 0;
}
