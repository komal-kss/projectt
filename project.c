#include<stdio.h>

struct process{
	int pid;
	int at;
	int bt;
}pro[100];

int n=0;

void priority(){
	int i,j;
	int time=0;
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(pro[j].at < pro[j+1].at){
				struct process obj= pro[j];
				pro[j]= pro[j+1];
				pro[j+1]= obj;
			}
		}
	}
	for(i=0; i<n; i++){
		time += pro[j].bt;
	}
	printf("\n\n");
	printf("When used priority based scheduling\n");
	printf("Total time: %d\n", time);
	printf("Average time: %d\n", time/n);
}

void stsf(){
		int i,j;
	int time=0;
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(pro[j].at > pro[j+1].at){
				struct process obj= pro[j];
				pro[j]= pro[j+1];
				pro[j+1]= obj;
			}
		}
	}
	printf("\n\n");
	for(i=0; i<n; i++){
		time += pro[i].bt;
	}
	printf("\n\n");
	printf("When used stsf algo\n\n");
	printf("Total time: %d\n", time);
	printf("Average time: %d\n", time/n);
	
}

void input(){
	int i;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("\n\n");
	for(i=0; i<n; i++){
		printf("Process Id: "); scanf("%d", &pro[i].pid); 
		printf("Arrival Time: "); scanf("%d", &pro[i].at);
		pro[i].bt= pro[i].at *2;
		printf("\n");
	}
}

void main(){
	input();
	priority();
	stsf();
}
