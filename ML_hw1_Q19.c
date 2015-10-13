// vim: ts=4 sw=4
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double dot(double data1[], double data2[]){
	int i;
	double result = 0.0;
	for(i=0;i<5;i++)
		result += data1[i]*data2[i];
	if(result > 0)
		return 1.0f; 
	else
		return -1.0f;
}

int main(){
	FILE* ftrain;
	FILE* ftest;
	ftrain = fopen("hw1_18_train.dat","r");
	ftest  = fopen("hw1_18_test.dat","r");

	srand(time(NULL));

	int i, j, num, error, update, tmp;
	double trdata[520][6], tdata[520][6];

	for(i=0; i<500; i++){
		fscanf(ftrain, "%lf %lf %lf %lf %lf", &trdata[i][0], &trdata[i][1], &trdata[i][2], &trdata[i][3], &trdata[i][5]);
		trdata[i][4] = 1.0f;
	}
	for(i=0; i<500; i++){
		fscanf(ftest, "%lf %lf %lf %lf %lf", &tdata[i][0], &tdata[i][1], &tdata[i][2], &tdata[i][3], &tdata[i][5]);
		tdata[i][4] = 1.0f;
	}

	double Wt[6], Wt1[6], result;
	int count[600];
	for(i=0;i<600;i++)
		count[i]=0;
	for(i=0;i<5;i++)
		Wt[i] = Wt1[i] = 0.0f;
	for(j=0;j<2000;j++){
		update = 0;
		error = 0;
		while(1){
			num = rand()%500;
			if(trdata[num][5]>0){
				for(i=0;i<5;i++){
					Wt[i] = trdata[num][i];
				}
				for(i=0; i<500; i++)
					if(dot(Wt, trdata[i])*trdata[i][5]<0)
						error++;
				break;
			}
		}
		while(1){
			num = rand()%500;
			if(dot(Wt, trdata[num])*trdata[num][5]<0){
				for(i=0; i<5; i++)
					Wt[i] = Wt[i] + trdata[num][i]*trdata[num][5];
				update++;
			}
			if(update>=50)
				break;
		}

		//for(i=0; i<5; i++)
		//	printf("%lf ", Wt[i]);
		
		//printf("%d", error);
		//puts("");
		error = 0;
		for(i=0;i<500;i++){
			if(dot(Wt, tdata[i])*tdata[i][5]<0)
				error++;
		}
		//printf("%d\n", error);
		count[error]++;
		//printf("%lf\n", (double)error/500.0f);
	}
	for(i=1;i<600;i++)
		printf("%d\n", count[i]);
	fclose(ftest);
	fclose(ftrain);
    return 0;
}
