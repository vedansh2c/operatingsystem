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
    printf("\nEnter the page size:");
    scanf("%d",&pageSize);
    int noOfPages=logicalAddSpace/pageSize;
    int pageTable[noOfPages];
    printf("\nEnter the corresponding frame number for virtual pages\n");
    for(int i=0;i<noOfPages;i++){
        printf("PageNo %d:",i);
        scanf("%d",&pageTable[i]);
    }
    printf("\nEnter the virtual address:");
    int virtualAdd;
    scanf("%d",&virtualAdd);
    int m=log2(logicalAddSpace),n=log2(pageSize);
    int vAddArr[m];
    binaryAdd(virtualAdd,m,vAddArr);

    int offset=0;
    for(int i=m-1;i>=m-n;i--){
        offset+=vAddArr[i]*pow(2,m-1-i);
    }
    int pageNo=0;
    for(int i=m-n-1;i>=0;i--){
        pageNo+=vAddArr[i]*pow(2,m-n-1-i);
    }
    printf("\nPhysical address for the virtual address %d is %d\n",virtualAdd,pageTable[pageNo]*pageSize+offset);
    return 0;
}