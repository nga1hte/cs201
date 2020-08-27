//Program to print steps for solving tower of hanoi

#include <stdio.h>

//global counter to count and track number of steps
int steps = 0;

//take number of disk, from, to and primary towers respectively
void toh(int, char*, char*, char*);

int main(){
    int disks = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    toh(disks, "Tower 1", "Tower 2", "Tower 3");
}

void toh(int n, char *a, char *b, char *c){
    if(n == 1){
        ++steps;
        printf("%d: Move disk 1 from %s to %s\n", steps, a, c);
    }else{
        toh(n-1, a, c, b);
        ++steps;
        printf("%d: Move disk %d from %s to %s\n", steps, n, a, c);
        toh(n-1, b, a, c);
        return;
    }
}

