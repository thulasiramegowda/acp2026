typedef struct {
    	float length;
    	float width;
    	float area;
    	float costPerUnit;
    	float totalCost;
} Floor;

void inputDetails(int n, Floor floors[]);
void calculateCosts(int n, Floor floors[]);
int highestCostFloor(int n, Floor floors[]);
void displayHighestCost(int index, Floor floors[]);

int main(){
    int n, index;
    printf("Enter number of floors:");
    scanf("%d", &n);
    Floor floors[n];
    
    inputDetails(n,floors);
    calculateCosts(n, floors);
    index = highestCostFloor(n, floors);
    displayHighestCost(index,floors);
    retrun 0;
}
void inputDetails(int n, Floor floors[n]){
    for(int i=0;i<n;i++){
    printf("--floar deatils--\n");
    printf("enter the length :");
    scanf("%f\n",&floors[i].length);
printf("enter the width :");
    scanf("%f\n",&floors[i].width);
printf("enter the Cost per unit area :");
    scanf("%f\n",&floors[i].costPerUnit);
}
}

void calculateCosts(int n, Floor floors[]){
for(int i=0;i<n;i++){
    floors[i].area = floors[i].length * floors[i].width;
    floors[i].totalCost = floors[i].area * floors[i].costPerUnit;
}
}
int highestCostFloor(int n,Floor floors[]){
    int index=0;
    for(int i=0;i,n;i++){
        if(floors[i].totalCost > floors[index].totalCost){
            index = i;
        }
    }
    return index;
}
void output(int index,Floor floor[]){
    printf("the floor with highest cost : %d",index + 1);
    printf("the total cost = %.3f",Floor[index].totalCost);
}
