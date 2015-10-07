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
	int n = 0, i, j;
	double data[510][10];
	
	srand(time(NULL));

	for(i=0; i<500; i++){
		fscanf(fin, "%lf %lf %lf %lf %lf", 
			   &data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][5]);
		data[i][4] = 1;
	}
    int	num, error, e_tmp, update, result;
	double Wt[10];
	double Wt_1[10];
	
	for(j=0; j<1; j++){
		num = rand()%500;
//		printf("%d\n\n", num);
		update = 1;
		error = 0;
		for(i=0; i<5; i++){
			Wt[i] = data[num][i];
			//printf("%lf ", Wt[i]);
		}
		//puts("");
		for(i=0;i<500;i++){
			result = dot(Wt, data[i]);
			if(result*data[i][5]<=0)
				error++;
		}
		printf("%d\n", error);
		while(1){
			//e_tmp = 0;
			/*for(i=0;i<500;i++){
				result = dot(Wt, data[i]);
				if(result*data[i][5]<=0)
					error++;
			}*/
			num = rand()%500;
			result = dot(Wt, data[num]);
			if(result*data[num][5]<=0){
				e_tmp = 0;
				for(i=0;i<5;i++){
					Wt_1[i] = Wt[i]+data[num][i];
					//printf("%lf ", Wt_1[i]);
				}
			

				//puts("");
			
				for(i=0;i<500;i++){
					result = dot(Wt_1, data[i]);
					if(result*data[i][5]<=0)
						e_tmp++;
				}
			
				if(e_tmp<error){
					for(i=0;i<5;i++){
						Wt[i] = Wt_1[i], error = e_tmp;//, update++;
						printf("%lf ", Wt[i]);
					}
					puts("");
				}

				update++;
			}
			if(update>=50)
				break;
			printf("U: %d , %d , %d\n", update, error, e_tmp);
		}
		for(i=0;i<5;i++)
			printf("%lf ", Wt[i]);
		printf("%d", error);
		printf("\n");
	}
	return 0;	
}	
