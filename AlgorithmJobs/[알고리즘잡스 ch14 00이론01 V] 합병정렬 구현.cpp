#include <iostream>
#include <algorithm>
using namespace std;
/*
[알고리즘잡스 ch14 00이론01 V] 합병정렬 구현
풀이: 
시간복잡도: O(nlogn) 
*/
#define MAX 110
int numbers[MAX];

// s부터 e까지 정렬하며 합병
void merge(int ar[],int s1,int e1,int s2,int e2){
  int p=s1,q=s2;
  int tp[MAX]={0,};
  int tpIdx=0;
  // 두 구간 모두 원소 있을 때 둘이 비교
  while(p<=e1 && q<=e2){
    // 외쪽이 작은 경우 왼쪽 삽입, 이덱스 증가
    if(ar[p] <= ar[q]){
      tp[tpIdx++]=ar[p++]; 
    }
    // 오른쪽이 작은 경우 오른쪽 삽입, 인덱스 증가
    else if(ar[p] > ar[q]){
      tp[tpIdx++]=ar[q++]; 
    }
  }
  // 왼구간이 남았을 때 왼구간 모두 넣기
  while(p<=e1){
    tp[tpIdx++]=ar[p++];
  }
  // 오른구간이 남았을 때 오른구간 모두 넣기
  while(q<=e2){
    tp[tpIdx++]=ar[q++];
  }
  
  // 정렬된 배열 본 배열에 저장
  for(int i=s1;i<=e2;i++){
    ar[i] = tp[i-s1];
  }
}

// 1.합병정렬 재귀: s,부터 e까지 배열 정렬
void mergeSort(int ar[],int start,int end){
  //기저사례: 수가 하나까지 분해되었을 때
  if(start>=end){
    return;
  }
  int mid = (start+end)/2;
  // 왼구간 합병정렬
  mergeSort(ar,start,mid);
  // 오른구간 합병정렬
  mergeSort(ar,mid+1,end);
  // 머지
  merge(ar,start,mid,mid+1,end);
}


int main() {
  
  for(int i=0;i<100;i++){
    numbers[i] = 100-i;
  }
  
  mergeSort(numbers,0,99);
  
  // 배열 출력
  for(int i=0;i<100;i++){
    cout<<numbers[i]<<'\n';
  }
  return 0;
}
