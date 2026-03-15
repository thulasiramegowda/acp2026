#include <stdio.h>

void inputTemperatures(int n, float temps[n]);
float findHighest(int n, float temps[n]);
float findLowest(int n, float temps[n]);
void output(float max, float min);

int main(){
    int n=7;
    float max,min;
    float temps[7];
    inputTemperatures(n,temps);
    max = findHighest(n,temps);
    min = findLowest(n,temps);
    output(max,min);
    return 0;
}
void inputTemperatures(int n, float temps[n]){
    for(int i=0;i<n;i++){
        printf("enter the temp of %d day :",i+1);
        scanf("%f",&temps[i]);
    }
}
float findHighest(int n, float temps[n]){
    float max= temps[0];
    for(int i=0;i<n;i++){
        if(temps[i]>max)
        max = temps[i];
    }
    return max;
}
float findLowestt(int n, float temps[n]){
    float min=temps[0];
    for(int i=0;i<n;i++){
        if(temps[i]<min)
        min = temps[i];
    }
    return min;
}
void output(float max,float min){
    printf("the highest temperature is %d",max);
    printf("the lowest temperature is %d",min);
}