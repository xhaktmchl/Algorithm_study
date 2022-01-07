#include <stdio.h>
int map[25][25];
int d[25];

int main(){
  
  int r,c;
  scanf("%d %d",&c,&r);
  
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      scanf("%d",&map[i][j]);
    }
  }
  for(int i=0;i<c;i++){
    for(int j=0;j<r;j++){
      if(map[j][i]==1){
        d[i] = j-1;
        break;
      }
      if(j==r-1&&map[j][i]==0){
        d[i] = r-1;
      }
    }
  }
  int max = -1;
  int idx = 0;
  for(int i=0;i<c;i++){
    // printf("%d ",d[i]);
    if(max<d[i]){
      max = d[i];
      idx = i;
    }
  }
  
  if(max<3){
    printf("0 0");
    return 0;
  }
  for(int i=0;i<4;i++){
    map[max][idx] = 1;
    max--;
  }
  int result = 0;
  for(int i=0;i<r;i++){
    int cnt = 0;
    for(int j=0;j<c;j++){
      if(map[i][j]==1) cnt++;
    }
    if(cnt == c) result++;
  }
  if(result ==0) printf("0 0");
  else printf("%d %d",idx+1,result);
  
}
