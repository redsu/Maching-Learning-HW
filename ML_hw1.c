#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define false 0
#define true  1
double dot(double data1[], double data2[]){
	double result = 0.0f;
	int i = 0;
	for(i=0; i<5; i++){
		result += data1[i]*data2[i];
		//printf("%lf\n", result);
	}
	/*if(result>-1)
		return 1;
	else
		return -1;
	*/
	//printf("%lf\n", result);
	return result;
}
int main(){
	FILE* fin;
	fin = fopen("hw1_train.dat_Q18.txt", "r");
	int n = 0, i = 0;
	double data[510][10];
	
	srand(time(NULL));

	for(i=0; i<500; i++){
		fscanf(fin, "%lf %lf %lf %lf %lf", 
			   &data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][5]);
		data[i][4] = 1;
		//printf("%lf %lf %lf %lf %lf\n",
        //       data[i][0],data[i][1],data[i][2],data[i][3],data[i][4]);
	}
	int list[510], picked[510], num;
	for(i=0;i<500;i++)
		list[i] = picked[i] = -1;

	i = 0;
	
	while(i<500){
		num = rand()%500;
		if(picked[num]==-1){
			list[i] = num;
			picked[num] = 0;
			i++;
		}
	}

	double Wt[10];
	for(i=0; i<4; i++)
		Wt[i] = data[0][i];
	Wt[4] = 0;
	i=0;
	int j = 0, times = 0;
	//char end = false;
	double result = 0;
	int    sign = 0;
	while(1){
		for(i=0; i<500; i++){
			result = dot(Wt, data[list[i]]);
			//sign = result > 0 ? 1 : -1;
			if(result * data[list[i]][5] < 0){
				for(j=0; j<5; j++)
					Wt[j]+=data[list[i]][j]*data[list[i]][5]*0.5;
				//printf("update! %d\n", sign);
				break;
			}
			else
				;//printf("correct!\n");
		}
		times++;
		if(times==50)
			break;
		//printf("%d time(s).\n", i);
	}
	/*printf("%d\n", times);
	for(i=0; i<5; i++)
		printf("%lf ", Wt[i]);
	printf("\n");*/
	FILE* fin2;
	fin = fopen("hw1_train_Q18test.dat.txt", "r");
	int error = 0;
	for(i=0;i<500;i++){
		fscanf(fin, "%lf %lf %lf %lf %lf",
    		&data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][5]);
		data[i][4] = 1;
		result = dot(Wt,data[i]);
		if(result*data[i][5]<0)
			error++;
	}
	printf("%d\n", error);
	return 0;
}
