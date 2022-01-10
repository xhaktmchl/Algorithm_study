#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[알고리즘잡스 ch7 06 O] 문자열 정렬
풀이: sort 이용
시간복잡도: O(n)=100
*/
#define MAX 101
int n;
string s[MAX];
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  // 문자열 배열 입력
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  // 문자열 배열 정렬
  sort(s,s+n);
  for(int i=0;i<n;i++){
    cout<<s[i]<<'\n';
  }
  return 0;
} 
