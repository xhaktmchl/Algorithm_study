#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
/*
[알고리즘잡스 ch11 11 X] 팰린드롬 만들기
풀이: dp , 최소 편집거리 알고리즘
  // 1.배열 입력
  //2.테이블 정의 dp[i][j] = i부터 j 문자열 까지 팰린드롬으로 만들기 위해 추가해야하는 문자의 최소갯수
  //점점화식 
  // if(a[i]==a[j]) { dp[i][j] = dp[i+1][j-1];} // 양 끝이 같으면 i+1부터 j-1 까지의 dp와 같음
  // if(a[i]!=a[j]){ dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1}// 다르면 왼쪽에 추가 , 오른쪽에 추가 하는 것 중 최소값을 선택
  //초초기값
시간복잡도: O(n*n)= 100만
*/
#define MAX 1010
string str;
int a[MAX][MAX];
int dp[MAX][MAX];

int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  
  // 1.배열 입력
  cin>>str;
  int len=str.size();
  //2.테이블 정의 dp[i][j] = i부터 j 문자열 까지 팰린드롬으로 만들기 위해 추가해야하는 문자의 최소갯수
  //점점화식 
  // if(a[i]==a[j]) { dp[i][j] = dp[i+1][j-1];} // 양 끝이 같으면 i+1부터 j-1 까지의 dp와 같음
  // if(a[i]!=a[j]){ dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1}// 다르면 왼쪽에 추가 , 오른쪽에 추가 하는 것 중 최소값을 선택
  //초초기값
  for(int i=0;i<len;i++){
    dp[i][i]=0;
  }
  for(int i=len-1;i>=0;i--){
    for(int j=i;j<len;j++){
      if(str[i]==str[j]) { dp[i][j] = dp[i+1][j-1];}
      else if(str[i]!=str[j]){ dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;}
    }
  }
  //출력: 팰린드롬을 만들기 위한 최소값
  /*for(int i=0;i<len;i++){
    for(int j=0;j<len;j++){
      cout<<dp[i][j]<<" ";
    }cout<<'\n';
  }*/
  cout<<dp[0][len-1]<<'\n';
  return 0;
}
