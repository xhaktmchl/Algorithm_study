#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘 잡스] 선택정렬 구현
풀이:
시간복잡도: O(n*n)
*/
#define MAX 100
int n,a[MAX];
int main() {
  ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  // 선택정렬
  for(int i=0;i<n;i++){
    int minN = a[i],minIdx=i;
    for(int j=i;j<n;j++){
      if(minN > a[j]){ minN = a[j]; minIdx=j;}
    }
    swap(a[i],a[minIdx]);
  }
  // 정렬된 배열 출력
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
