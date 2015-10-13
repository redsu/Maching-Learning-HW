// vim: ts=4
#include<stdio.h>
#define false 0
#define true  1
double dot(double data1[], double data2[]){
	double result = 0.0f;
	int i = 0;
	for(i=0; i<5; i++)
		result += data1[i]*data2[i];
	
	if(result > 0)
		return 1.0f;
	
	return -1.0f;
}

int main(){
	FILE* fin;
	fin = fopen("hw1_15_train.dat", "rt");
	int n = 0, i = 0;
	double data[410][10];
	for(i=0; i<400; i++){
		fscanf(fin, "%lf %lf %lf %lf %lf", 
			   &data[i][1],&data[i][2],&data[i][3],&data[i][4],&data[i][5]);
		data[i][0] = 1;
	}
      
	double Wt[10];
	
	for(i=0; i<5; i++)
		Wt[i] = data[0][i];
	
	int j = 0, times = 1;
	int pass = 0;
	
	while(1){
		for(i=0; i<400; i++){
			if(dot(Wt, data[i]) * data[i][5] <= 0){
				for(j=0; j<5; j++){
					Wt[j]+=data[i][j]*data[i][5];
				}
				times++;
				pass = 0;
			}
			else{
				pass++;
			}
			if(pass>=400)
				break;
		}
		if(pass>=400)
			break;
	}
	printf("%d time(s). Index : %d\n", times, i);
	for(i=0; i<5; i++)
		printf("%lf ", Wt[i]);
	printf("\n");
	return 0;
}
