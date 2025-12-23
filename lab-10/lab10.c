
#include <stdio.h>
#define MAX 20
int hashTable[MAX];
int m;
void insert(int key){
    int index=key%m;
    if(hashTable[index]==-1){
        hashTable[index]=key;
    }else{
        int i=1;
        while(hashTable[(index+1)%m]!=-1){
            i++;
        }
        hashTable[(index+1)%m]=key;
    }
}void display(){
    printf("\n Hash Table:\n");
    for(int i=0;i<m;i++){
        if(hashTable[i]!=-1){
            printf("Address %d: %d\n",i,hashTable[i]);
        }else{
            printf("Address %d: empty\n",i);
        }
    }
}
int main(){
    int n,key;
    printf("enter size of hash table:(m):");
    scanf("%d",&m);
    printf("enter number of employee records:");
    scanf("%d",&n);
    for(int i=0;i<m;i++){
        hashTable[i]=-1;
    }printf("enter %d employee key(4-digit):\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        insert(key);
    }
    display();
    return 0;

}
