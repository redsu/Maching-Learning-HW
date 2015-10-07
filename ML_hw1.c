// vim: ts=4
#include<stdio.h>
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
	fin = fopen("hw1_train.dat.txt", "r");
	int n = 0, i = 0;
	double data[410][10];
	srand(time(NULL));
	for(i=0; i<400; i++){
		fscanf(fin, "%lf %lf %lf %lf %lf", 
			   &data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][5]);
		data[i][4] = 1;
		//printf("%lf %lf %lf %lf %lf\n",
        //       data[i][0],data[i][1],data[i][2],data[i][3],data[i][4]);
	}
      
	double Wt[10];
	for(i=0; i<4; i++)
		Wt[i] = data[0][i];
	Wt[4] = 1;
	i=0;
	int list[410], choose[410];
	for(i=0;i<400;i++)
		list[i] = choose[i] = -1;
	int index = 0;

	for(i=0; i<400;){
		index = rand()%400;
		if(choose[index]==-1){
			list[i] = index;
			choose[index] = 1;
			i++;
		}
	}
	for(i=0; i<4; i++)
        Wt[i] = data[list[0]][i];
	Wt[4] = data[list[0]][4];
	int j = 0, times = 1;
	//char end = false;
	double result = 0;
	int    sign = 1;
	int	   ok   = 0;
	int	   round = 1;
	int    t = 0;
	int	   cnt[100];
	for(t=0;t<100;t++)
		cnt[t] = 0;
	for(t=0; t<2000; t++){
		times = 1;
		ok = 0;
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
		

		for(i=0; i<4; i++)
        	Wt[i] = data[list[0]][i];
		Wt[4] = data[list[0]][4];

		while(1){
			//printf("round : %d\n", round);
			//times = 1;
			for(i=0; i<400; i++){
//			if(sign)
//				sign = 0;
			result = dot(Wt, data[list[i]]);
			//sign = result > 0 ? 1 : -1;
				if(result * data[list[i]][5] <= 0){
//					printf("update! %d Node: %d\n", times, i);
					for(j=0; j<5; j++){
						Wt[j]+=data[list[i]][j]*data[list[i]][5];
//						printf("%lf ", Wt[j]);
					}
//					printf("\n");
					times++;
					ok = 0;
					//break;
				}
				else{
//					printf("correct!\n");
					ok++;
				}
				if(ok==400)
					break;
			}
			if(ok==400)
			break;
			//printf("%d time(s).\n", i);
			round ++;
		}
		//printf("%d\n", times);
		cnt[times]++;
	}
	//printf("%d\n", times);
	//printf("%d time(s).\n", times);
/*	for(i=0; i<5; i++)
		printf("%lf ", Wt[i]);
	printf("\n");
*/	
	for(t=0;t<100;t++)
		printf("%d\n", cnt[t]);
	return 0;
}
