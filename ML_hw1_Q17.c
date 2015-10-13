// vim: ts=4
#include<stdio.h>
#include<time.h>
#define false 0
#define true  1
double dot(double data1[], double data2[]){
	double result = 0.0f;
	int i = 0;
	for(i=0; i<5; i++)
		result += data1[i]*data2[i];
	if(result>0)
		return 1;
	return -1;
}
int main(){
	FILE* fin;
	fin = fopen("hw1_15_train.dat", "rt");
	int n = 0, i = 0;
	double data[410][10];
	srand(time(NULL));
	for(i=0; i<400; i++){
		fscanf(fin, "%lf %lf %lf %lf %lf", 
			   &data[i][1],&data[i][2],&data[i][3],&data[i][4],&data[i][5]);
		data[i][0] = 1;
	}
      
	double Wt[10];
	for(i=0; i<5; i++)
		Wt[i] = data[0][i];
	
	int list[410], choose[410];
	int index = 0;
	
	int j = 0, update = 1;
	int	pass = 0;
	int t = 0;
	int	cnt[10000];
	for(t=0;t<100;t++)
		cnt[t] = 0;
	for(t=0; t<2000; t++){
		for(i=0;i<400;i++)
        	list[i] = choose[i] = -1;
	    
		index = 0;
	    for(i=0; i<400;){
	        index = rand()%400;
	        if(choose[index]==-1){
	            list[i] = index;
	            choose[index] = 1;
	            i++;
	        }
	    }
		

		for(i=0; i<5; i++)
        	Wt[i] = data[list[0]][i];
		pass = 1;
		update = 1;
		while(1){
			for(i=0; i<400; i++){
				if(dot(Wt, data[list[i]]) * data[list[i]][5] <= 0){
					for(j=0; j<5; j++)
						Wt[j] += data[list[i]][j]*data[list[i]][5];
					update++;
					pass = 0;
					break;
				}
				else
					pass++;

				if(pass>=400)
					break;
			}
			if(pass >= 400)
				break;
		}
		cnt[update]++;
	}
	for(t=1;t<200;t++)
		printf("%d\n", cnt[t]);
	return 0;
}
