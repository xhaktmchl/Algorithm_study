#include <iostream>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch5 V] baseball game
풀이: 완탐 , 123부터 987까지 모든 숫자가 주어진 스트라이크 볼 맞는지 검사
시간복잡도: O(1000*n*3*3)=90만
*/
#define MAX 102
int n,result=0;
string num[MAX];
int strike[MAX];
int ball[MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  // 1.숫자 문자열 배열에 저장
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>num[i]>>strike[i]>>ball[i];
  }
  // 2. 123부터 987 까지 완탐
  for(int i=123;i<=987;i++){
    string curNum = to_string(i);
    // 예외처리: 서로다른 1~9 숫자 아닌것
    if(curNum[0]=='0' || curNum[1]=='0' ||curNum[2]=='0' || curNum[0]==curNum[1]||curNum[0]==curNum[2] ||curNum[1]==curNum[2]){
      continue;
    }
    // 3.현재 숫자가 n개의 숫자의 힌트와 같은지 검사
    int c=0;
    for(int j=0;j<n;j++){
      int stcnt=0, bacnt=0;
      // 각 숫자당 스트라이크 ,볼 맞는지 검사
      for(int k=0;k<3;k++){
        for(int p=0;p<3;p++){
          if(curNum[k] == num[j][p] && k==p){ stcnt++;} // 스트라이크 카운트
          if(curNum[k] == num[j][p] && k!=p){ bacnt++;} // 볼 카운트
        }
      }
      if(stcnt==strike[j] && bacnt==ball[j]){ c++;}
    }
    // 조건 다 맞으면카운트
    if(c == n){ result++;}
  }
  cout<<result<<'\n';
  return 0;
}
