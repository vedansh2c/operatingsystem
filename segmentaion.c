#include<stdio.h>
#include<math.h>
void binaryAdd(int va,int m,int vAddArr[]){
    int binaryArr[m];
    for(int i=0;va>0;i++){    
        binaryArr[i]=va%2;    
        va=va/2;    
    }
    for(int i=m-1;i>=0;i--){    
        vAddArr[m-1-i]=binaryArr[i];
    }    

}
int main(){
    int logicalAddSpace,pageSize;
    printf("Enter the size of logical address space:");
    scanf("%d",&logicalAddSpace);
    printf("\nEnter the corresponding BaseAddress and size for Individual Segmentations\n");
    int base[4]={-1},size[4]={-1};
    for(int i=0;i<4;i++){
        if(i==0){
            printf("Code\n");
            printf("BaseAddress:");
            scanf("%d",&base[0]);
            printf("\nSize:");
            scanf("%d",&size[0]);
        }
        if(i==1){
            printf("\nHeap\n");
            printf("BaseAddress:");
            scanf("%d",&base[1]);
            printf("\nSize:");
            scanf("%d",&size[0]);
        }
        if(i==3){
            printf("\nStack\n");
            printf("BaseAddress:");
            scanf("%d",&base[3]);
            printf("\nSize:");
            scanf("%d",&size[3]);
        }
    }

    printf("\nEnter the virtual address:");
    int virtualAdd;
    scanf("%d",&virtualAdd);
    
    int m=log2(logicalAddSpace*1024),n=m-2;
    int vAddArr[m];
    binaryAdd(virtualAdd,m,vAddArr);

    int offset=0;
    for(int i=m-1;i>=m-n;i--){
        offset+=vAddArr[i]*pow(2,m-1-i);
    }
    int segment=0;
    for(int i=m-n-1;i>=0;i--){
        segment+=vAddArr[i]*pow(2,m-n-1-i);
    }
    if(segment==2 || offset>size[segment]){
        print("Segmentation Error\n");
    }
    else printf("\nPhysical address for the virtual address %d is %d\n",virtualAdd,base[segment]*1024+offset);
    return 0;    
}