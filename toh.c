#include <stdio.h>

void toi(int, char *, char *, char *);

int main(){
    int num;
    printf("Enter number of disks: \n");
    scanf("%d", &num);
    toi(num, "Tower 1", "Tower 3", "Tower 2");
}

void toi(int n, char *from, char *to, char *spare){
    if(n == 1){
        printf("Move disk %d from %s to %s\n", n, from, to);
        return;
    }else{
        toi(n-1,from, spare, to); 
        printf("Move disk %d from %s to %s\n", n, from ,to);
        toi(n-1, spare, to, from);
    }
}
