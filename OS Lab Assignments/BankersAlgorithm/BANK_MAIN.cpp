#include<iostream>
using namespace std;

int number_of_processes=5;
int number_of_resources=3;

int allocated_matrix[5][3]={
    { 0, 1, 0 },
    { 2, 0, 0 },
    { 3, 0, 2 },
    { 2, 1, 1 },
    { 0, 0, 2 }
};

int max_need_matrix[5][3] = { 
    { 7, 5, 3 },
    { 3, 2, 2 },
    { 9, 0, 2 },
    { 2, 2, 2 },
    { 4, 3, 3 } 
};

int available_matrix[3] = { 3, 3, 2 };

int rem_need_matrix[5][3];

void rem(){
    for (int i = 0; i < number_of_processes; i++)
    {
        for (int j = 0; j < number_of_resources; j++)
        {
            rem_need_matrix[i][j] = max_need_matrix[i][j] - allocated_matrix[i][j];
        }
        
    }
    
}

int finish[5]={0,0,0,0,0};
int ans[5]={0,0,0,0,0};
int index;
void avil(){

    for (int k = 0; k < number_of_processes; k++)
    {
        for (int i = 0; i < number_of_processes; i++)
        {
            if (finish[i]==0)
            {
                int flag=0;
                for (int j = 0; j < number_of_resources; j++)
                {
                    if (rem_need_matrix[i][j]>available_matrix[j])
                    {
                        flag = 1;
                        break;
                    }
                    
                }
                if (flag==0)
                {
                    ans[index++] = i;
                    for (int j = 0; j < number_of_resources; j++)
                    {
                        available_matrix[j] += allocated_matrix[i][j];
                    }
                    finish[i]=1;
                }
            }
            
        }
        
    }
    
}

void print(){
    cout<<"-----------------------------------------------"<<endl;
    cout<<"| Processes | Allocated | Max_need | Rem_need |"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    for (int i = 0; i < number_of_processes; i++)
    {
        cout<<"|     p-"<<i<<"   | ";
        for (int j = 0; j < number_of_resources; j++)
        {
            cout<<allocated_matrix[i][j]<<"  ";
        }
        cout<<" | ";
        for (int j = 0; j < number_of_resources; j++)
        {
            cout<<max_need_matrix[i][j]<<"  ";
        }
        cout<<"| ";
        for (int j = 0; j < number_of_resources; j++)
        {
            cout<<rem_need_matrix[i][j]<<"  ";
        }
        cout<<"| ";
        cout<<endl;
    }
    cout<<"\n\tSafe Sequence : ";
    for (int i = 0; i < number_of_processes; i++)
    {
        cout<<"p"<<ans[i];
        if(i!=4){
            cout<<" -> ";
        }
    }
    cout<<"\n\n";
}

int main(){
    rem();
    avil();
    print();
    return 0;
}
/*
-----------------------------------------------
| Processes | Allocated | Max_need | Rem_need |
-----------------------------------------------
|     p-0   | 0  1  0   | 7  5  3  | 7  4  3  |
|     p-1   | 2  0  0   | 3  2  2  | 1  2  2  | 
|     p-2   | 3  0  2   | 9  0  2  | 6  0  0  |
|     p-3   | 2  1  1   | 2  2  2  | 0  1  1  | 
|     p-4   | 0  0  2   | 4  3  3  | 4  3  1  |

        Safe Sequence : p1 -> p3 -> p4 -> p0 -> p2
*/