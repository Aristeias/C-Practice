#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d", &n);
    int num[n][n];
    int max = 0,rowIndex,colIndex;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &num[i][j]);
            if(abs(num[i][j]) > max){
                max = abs(num[i][j]);
                rowIndex = i + 1;
                colIndex = j + 1;
            }
        }
    }
    printf("%d %d %d", max, rowIndex, colIndex);
}
