#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
/*
[프로그래머스 42578 c++ VV] 위장
문제: 의상의 종류와 의상들이 주어졌을 때 입을 수 있는 의상의 조합의 수 구하기
접근: 의상의 조합의 수 -> 수학 경우의 수 구하기 -> 각 종류마다 뽑는 경우의 수는 nC1 , 전체 곱하면 전체 의상을 입는 경우의 수
풀이: 
// map구조체에 의상 종류를 키, 갯수를 값으로 지정
// 옷을 탐색하며 의상종류의 각 갯수를 구함
// map 의 객체를 탐색하며 각 입는 경우의 수 곱 // map의 객체는 pair 객체이다.
// 전부 안 입는경우 -1
개념:
//  map<string,int> m; : 균형잡힌 이진트리 형식으로 pair<key,value> 객체로 저장 
// map 구조체 탐색 : 
// 1. key값으로 탐색 :m[clothes[i][1]] +=1;
// 2. auto 로 자동으로 pair객체 인색해서 탐색 : for(auto iter: m){iter.second};

풀이2:
    //1.옷 배열탐색: 해시맵에 (종류, 갯수) 저장
    //2.조합 수 구하기 : 종류마다 안넣은 경우, 하나씩 고르는 경우
*/
map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int res=1;

    //1.옷 배열탐색: 해시맵에 (종류, 갯수) 저장
    int size = clothes.size();
    for(int i=0;i<size;i++){
        m[clothes[i][1]]+=1;
    }
    //2.조합 수 구하기 : 종류마다 안넣은 경우, 하나씩 고르는 경우
    for(auto it : m) res*=(it.second+1);
    return answer=res-1; 
}
