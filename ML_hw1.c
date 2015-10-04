// vim: ts=4
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
	fin = fopen("hw1_train_Q18.dat.txt", "r");
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
<<<<<<< HEAD
      
	double Wt[10];
	for(i=0; i<4; i++)
		Wt[i] = data[0][i];
	Wt[4] = 1;
=======
	int list[410], picked[410], num, error = 0;
	/*for(i=0;i<400;i++)
		list[i] = picked[i] = -1;

	i = 0;
	
	while(i<400){
		num = rand()%400;
		if(picked[num]==-1){
			list[i] = num;
			picked[num] = 0;
			i++;
		}
	}*/

	double Wt[10], Wt_1[10];
	num = rand()%500;
	//num = 0;
	for(i=0; i<4; i++)
		Wt[i] = data[num][i];
	Wt[4] = 0;
>>>>>>> 01df3b64002736edee844d49ee7eb1d18147f63a
	i=0;
	int j = 0, times = 1;
	//char end = false;
	double result = 0;
<<<<<<< HEAD
	int    sign = 1;
	int	   ok   = 0;
	int	   round = 1;
	while(1){
		//printf("round : %d\n", round);
		//times = 1;
		for(i=0; i<400; i++){
			if(sign)
				sign = 0;
			result = dot(Wt, data[i]);
			//sign = result > 0 ? 1 : -1;
			if(result * data[i][5] <= 0){
				//printf("update! %d Node: %d\n", times, i);
				for(j=0; j<5; j++){
					Wt[j]+=data[i][j]*data[i][5];
					//printf("%lf ", Wt[j]);
				}
				//printf("\n");
				times++;
				ok = 0;
				//break;
			}
			else{
				//printf("correct!\n");
				ok++;
			}
			if(ok==400)
				break;
		}
		//times++;
		if(ok==400)
			break;
		//printf("%d time(s).\n", i);
		round ++;
=======
	int    sign = 0;
	int tmp;
	printf("check1\n");
	error = 0;
	for(i=0; i<500; i++){
		result = dot(Wt, data[i]);
		//sign = result > 0 ? 1 : -1;
		if(result * data[i][5] < 0){
			error++;
		}
	}
	printf("check2\n");
	while(1){
		num = rand()%500;
		result = dot(Wt, data[num]);
		if(result * data[num][5] < 0){
			for(i=0; i<5; i++)
		        Wt_1[i] = data[num][i]*data[num][5] + Wt[i];
			tmp = 0;
			for(i=0; i<500; i++){
				result = dot(Wt_1, data[i]);
				if(result * data[i][5] < 0)
					tmp++;
			}
			if(tmp==0)
				break;
			if(tmp<error){
				error = tmp;
				for(i=0; i<5; i++)
					Wt[i] = Wt_1[i];
				//times++;
				printf("update! %d\n", times);
			}
			
			printf("Error %d, tmp %d\n", error, tmp);
		}
		times++;
		if(times==50)
			break;
>>>>>>> 01df3b64002736edee844d49ee7eb1d18147f63a
	}

	printf("%d\n", times);
	for(i=0; i<5; i++)
		printf("%lf ", Wt[i]);
	printf("\n");
	return 0;
}
