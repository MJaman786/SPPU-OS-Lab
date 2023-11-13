#include<iostream>
using namespace std;

#define MAX 30
float wt[MAX], bt[MAX], tat[MAX], average_tat=0.0, average_wt=0.0; 
int p[MAX], num;

void calculation(){
	float temp;
	for(int i=0; i<num-1; i++){
		for(int j=0; j<num-1-i; j++){
			if(bt[j]>bt[j+1]){
				temp = bt[j];
				bt[j] = bt[j+1];
				bt[j+1] = temp;
				
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	for(int i=0; i<num; i++){
		wt[i]=0;
		tat[i]=0;
	for(int j=0; j<i; j++){
		wt[i] = wt[i] + bt[j];
	}
	tat[i] = wt[i] + bt[i];
}

	for(int i=0; i<num; i++){
		average_wt += wt[i];
		average_tat += tat[i];
	}
	average_wt = average_wt/num;
	average_tat = average_tat/num;
}

	
void print(){
		cout<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"|\tP\t|\tBT\t|\tWT\t|\tTAT\t|"<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
	for(int i=0; i<num; i++){
		cout<<"|\t"<<p[i]<<"\t|\t"<<bt[i]<<"\t|\t"<<wt[i]<<"\t|\t"<<tat[i]<<"\t|\t"<<endl;
	}
	cout<<"\nAverage wt : "<<average_wt;
	cout<<"\nAverage tat : "<<average_tat;
	cout<<endl;
}

int main(){
	
	cout<<"Enter number of process : ";
	cin>>num;
	
	cout<<"Enter process numbers : ";
	for(int i=0; i<num; i++){
		cin>>p[i];
	}	
	
	cout<<"Enter burst times : ";
	for(int i=0; i<num; i++){
		cin>>bt[i];
	}
	
	calculation();
	print();
	
	return 0;
}
/*

-------- output -----------

Enter number of process : 4
Enter process numbers : 1 2 3 4 5
Enter burst times : 3 2 5 7

-----------------------------------------------------------------
|	P	|	BT	|	WT	|	TAT	|
-----------------------------------------------------------------
|	3	|	2	|	0	|	2	|	
|	2	|	3	|	2	|	5	|	
|	1	|	5	|	5	|	10	|	
|	4	|	5	|	10	|	15	|	

Average wt : 4.25
Average tat : 8


*/

