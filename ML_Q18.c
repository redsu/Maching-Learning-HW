// vim: ts=4
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double dot(double data1[], double data2[]){
	int i;
	double result = 0.0;
	for(i=0;i<5;i++)
		result += data1[i]*data2[i];
	//if(result > 0)
		//return result;
	//else
		return result;
}

int main(){
	FILE *ftrain, *ftest;
	ftrain = fopen("hw1_18_train.txt","r");
	ftest  = fopen("hw1_18_test.txt","r");

	srand(time(NULL));

	int i, j, num, error, update, zero, tmp;
	double trdata[520][5], tdata[520][5];

	for(i=0; i<500; i++){
		fscanf(ftrain, "%lf %lf %lf %lf %lf", &trdata[i][0], &trdata[i][1], &trdata[i][2], &trdata[i][3], &trdata[i][5]);
		trdata[i][4] = 1.0f;
		printf("%lf %lf %lf %lf %lf\n", trdata[i][0], trdata[i][1], trdata[i][2], trdata[i][3], trdata[i][5]);
		puts("1");
	}

	for(i=0; i<500; i++){
		fscanf(ftest, "%lf %lf %lf %lf %lf", &tdata[i][0], &tdata[i][1], &tdata[i][2], &tdata[i][3], &tdata[i][5]);
		tdata[i][4] = 1.0f;
	}

	double Wt[5], Wt1[5], result;

	for(i=0;i<5;i++)
		Wt[i] = Wt1[i] = 0.0f;

	update = zero = 0;
	//puts("start");
	while(1){
		num = rand()%500;
		result = dot(Wt, trdata[num]);
		if(zero==0){
			for(i=0;i<5;i++)
				Wt[i] = trdata[num][i];
			zero = 1;
			error = 0;
			for(i=0; i<500; i++)
				if(dot(Wt1, trdata[i])*trdata[i][5]<=0)
					error++;
			update++;
		}
		//printf(": %lf\n", result);
		if(result*trdata[num][5]<=0){
			for(i=0; i<5; i++){
				Wt1[i] = Wt[i] + trdata[num][i]*trdata[num][5];
				printf("%lf ", Wt1[i]);
			}
			puts("");

			tmp = 0;

			for(i=0; i<500; i++)
				if(dot(Wt1, trdata[i])*trdata[i][5]<=0)
					tmp++;

			if(tmp<error){
				for(i=0;i<5;i++){
					Wt[i] = Wt1[i];
					printf("%lf ", Wt[i]);
				}
				puts("");
				tmp = error;
				puts("Update");
			}
			printf("%d %d\n ", error, tmp);
			update++;
		}
		if(update>=50)
			break;
	}

	for(i=0; i<5; i++)
		printf("%lf ", Wt[i]);
	printf("%d", error);
	puts("");

    return 0;
}
