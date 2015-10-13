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
		return 1.0f;
	return -1.0f;
}
int main(){
	FILE* fin;
	fin = fopen("hw1_15_train.dat", "rt");
	int i = 0, j = 0, t = 0;
	double data[410][10];
	
	srand(time(NULL));
	
	for(i=0; i<400; i++){
		fscanf(fin, "%lf %lf %lf %lf %lf", 
			   &data[i][1],&data[i][2],&data[i][3],&data[i][4],&data[i][5]);
		data[i][0] = 1;
	}
      
	double Wt[10];
	
	int list[410], choose[410];
	int index = 0, pass = 0, times = 1;
	int cnt[100];
	
	for(t=0;t<100;t++)
		cnt[t] = 0;
	
	for(t=0; t<2000; t++){
		for(i=0;i<400;i++)
        	list[i] = choose[i] = -1;

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
		times = 1;

		while(1){
			for(i=0; i<400; i++){
				if(dot(Wt, data[list[i]]) * data[list[i]][5] <= 0){
					for(j=0; j<5; j++)
						Wt[j]+=data[list[i]][j]*data[list[i]][5];
					times++;
					pass = 0;
				}
				else
					pass++;
			
				if(pass>=400)
					break;
			}
			if(pass>=400)
				break;
		}
		cnt[times]++;
	}
	
	for(t=0;t<100;t++)
		printf("%d\n", cnt[t]);
	return 0;
}
