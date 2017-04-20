#include<stdio.h>
#include<iostream>
#include<process.h>
#include<cstdlib>
#include<cmath>
#include<climits>

using namespace std;


/*DP COINAGE*/

int i, j, amount, *dp[8];

int denomination[8]={0, 1, 5, 10, 20, 50, 100, 500};




/*Seat Placement*/
int reserved[100][100]={0},arr1[100][100]={0};

int counter=0,*count_arr,*count_arr1,no=0;

int number_of_vip_tables=0;

int flag_for_vip_allocate=0;

/*Table Placement*/
int affected_x[8]={0},affected_y[8]={0},cntx=0,cnty=0;

bool flag=false;

int row=0,column=0,no_of_tables=0;

int arr[100][100]={0},avail[100][100]={0};

int number_of_pillars, number_of_tables;


/*CCTV*/
int change_matrix[100][100]={0};

int max_i=0,max_j=0,max_count=0,tables_left=0;



/*
void display_affected();
void print_matrix();
void update_avail(int i,int j);
void place_tables();
void place_normal_table();
void input_matrix();
bool check(int i,int j);
int zeroinavail();*/


/////////////
/*
int place_members(int ,int ,int  ,int** );
int * table_allocation();
*/
//////////////////
/*
void person_allocation();
void calculate_occurence(int);
*/
//
/*
void count_vip_tables();
void find_and_allocate_vip(int &);
void finally_allocate_normal_table(int &no);
void allocate_normal_table(int flag,int &);
int find_normal_table();
void finally_allocate_vip_table(int &number_of_persons);
*/

//





/*Table Placement*/
void display_affected();

void display_matrix();

void update_avail(int i,int j);

void place_tables();

void place_normal_table();

void input_matrix();

bool check(int i,int j);

int zeroinavail();




/*Seat Placement*/

int place_members(int ,int ,int  ,int** );

int * table_allocation();

void person_allocation();

void calculate_occurence(int);

void count_vip_tables();

void find_and_allocate_vip(int &);

void finally_allocate_normal_table(int &no);

void allocate_normal_table(int flag,int &);

int find_normal_table();

void finally_allocate_vip_table(int &number_of_persons);

void copying_to_arr1();




void display_matrix()
{
	cout<<"\n\nThe following is your matrix:\n\n";
	

	cout<<" \t";
	for(int i=0;i<column;i++)
	{
		cout<<i+1<<"\t";
	}
	
	cout<<"\n\n";
	
	for(int i=0;i<row;i++)
	{
		
		cout<<i+1<<"\t";
		
		for(int j=0;j<column;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		
		cout<<"\n\n";
	}
}









void update_avail(int i,int j)
{
		for(int x=i-1;x<=i+1;x++)
		{
			for(int y=j-1;y<=j+1;y++)
			{ 
				if(avail[x][y]==0)
		 		{
		 			avail[x][y]=1;	
		 			affected_x[cntx++]=x;
		 			affected_y[cnty++]=y;
		 			
		 		}
		 		
			}
		}  
}


/*CHANGE THIS TO BEAUTIFUL*/
void display_affected()
{
	for(int i=0;i<cntx;i++)
	{
		for(int j=0;j<cnty;j++)
		{
			cout<<"-----------"<<endl;
			cout<<affected_x[i]<<","<<affected_y[j]<<endl;
			cout<<"-----------"<<endl;
		}
	}
}



int zeroinavail()
{
	int count=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(avail[i][j]==0)
			{
				count++;
			}
		}
	}
	return count;
}




void place_tables()
{ 
	int temp1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			/*display_matrix();
			cout<<"NO: "<<no_of_tables<<"****************************\n";
			
			cout<<endl<<zeroinavail()<<"---------------";
			*/

			if(no_of_tables==0)
			{
				flag=true;
				break;
			}
			
			if(zeroinavail()<no_of_tables)
				{

					for(int p=0;p<cntx;p++)
					{
						if(affected_x[p]==-1||affected_y[p]==-1);
						else{
							avail[affected_x[p]][affected_y[p]]=0;
						
						arr[affected_x[p]][affected_y[p]]=0;
						affected_x[p]=affected_y[p]=0;	
						
						
						}
						
					}
						no_of_tables++;
						cntx=cnty=0;
						flag=true;
						break;

				}
				
			for(int p=0;p<cntx;p++)
					{
						affected_x[p]=0;
						affected_y[p]=0;
						
					}
						cntx=cnty=0;
			
			
			if(arr[i][j]==0 )//&&avail[i][j]!=1) //check for pillar
			{
				
				temp1=check(i,j);	//check for neighbour
				if(temp1==true)
				{
			
					arr[i][j]=5;
					update_avail(i,j);
					no_of_tables--;					
				}
			}
			
		}
		if(flag==true)
		break;
	}
	if(flag==true)
	{
		place_normal_table();
	}
	
}





void place_normal_table()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(no_of_tables>0)
			{
			
				if(avail[i][j]==0)
				{
					avail[i][j]=1;
					arr[i][j]=6;	
					no_of_tables--;
					
			/*		cout<<"*****************--";
				display_matrix();
						cout<<"NO: "<<no_of_tables<<"**********normal table******************\n";*/
				}
			
			}
			
		}
	}
	
}




void input_pillars()
{
	int pillar_row,pillar_column;
	
	cout<<"\n\nPlease enter the number of pillars:\t";
	cin>>number_of_pillars;
	
	cout<<"\n\n";
	
	system("pause");
	
	cout<<"\n\n";
	
	if(number_of_pillars>row*column)
	{

		cout<<"\n\nError! Number of Pillars Can not exceed the space available!";
		cout<<"\n\nPlease enter number of tables again.\n\nPress any key to continue.";
		
		input_pillars();
		
	}
	
	else
	{
	
		
		
		display_matrix();
		
		for(int i=0;i<number_of_pillars;i++)
		{
			pillar_row=0;
			pillar_column=0;
			cout<<"\n\nEnter the coordinates of Pillar "<<i+1<<":\t";
			scanf("%d,%d",&pillar_row,&pillar_column);
			
			arr[pillar_row-1][pillar_column-1]=2;
			avail[pillar_row-1][pillar_column-1]=2;
		}
		
		display_matrix();
		
		
		cout<<"\n\nEnter total number of tables:\t";
		
		cin>>no_of_tables;
		
		tables_left=no_of_tables;
		
		cout<<"\nPress any key to continue...";
		
		
	}
	
	
}





void input_matrix()
{

	cout<<"Enter number of rows(Upto 100): \t";
	cin>>row;
	
	cout<<"Enter number of columns(Upto 100): \t";
	cin>>column;
	
	input_pillars();
	
	/*
	
	cout<<"\nEnter total number of tables";
	cin>>no_of_tables;
	
	tables_left=no_of_tables;
	
	cout<<"\nPress any key to continue...";
	
	*/
	
	 
}



bool check(int i,int j)
{
	bool check1=true;
	
	if(avail[i][j]==2||avail[i][j]==1)
	{
		return false;
	}
	else{
		return true;
	}
}




void copy_matrix()
{

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			change_matrix[i][j]=arr[i][j];
		}
	}
}




void display_change_matrix()
{
	cout<<"\n\nThe following is your changed matrix:\n\n";
	

	cout<<" \t";
	for(int i=0;i<row;i++)
	{
		cout<<i+1<<"\t";
	}
	
	cout<<"\n\n";
	
	for(int i=0;i<row;i++)
	{
		
		cout<<i+1<<"\t";
		
		for(int j=0;j<column;j++)
		{
			cout<<change_matrix[i][j]<<"\t";
		}
		
		cout<<"\n\n";
	}
}





void count_the_matrix(int i, int j)
{
	int current_table_count=0;
	
	for(int x=i-1;x<=i+1;x++)
	{
		for(int y=j-1;y<=j+1;y++)
		{ 
			if(i==row && x==i+1 || i==0 && x==i-1 || j==column && y==j+1 || j==0 && y==j-1)
			{
				
			}
			
			else
			{
				if(change_matrix[x][y]==5 || change_matrix[x][y]==6 )
	 			{
	 				current_table_count++;
					 
					 //cout<<"\n------------\n"<<x<<","<<y<<"\n---------------current table count"<<current_table_count<<"\n\n-------max count previous"<<max_count;
	 			}
	 			
			}
	 		
		}
	}  
	
	if(current_table_count>max_count)
	{
		max_i=i;
		max_j=j;
		max_count=current_table_count;
	}
}





void run_count_matrix_once()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(change_matrix[i][j]!=2)
			{
				count_the_matrix(i,j);	
			}
		}
	}
	
//	cout<<"\n\n--------------\ncount max"<<max_count<<"\n\n--------------\nmax i"<<max_i<<"\n\n--------------\nmax j"<<max_j;
}




void update_change_matrix(int i, int j)
{
	for(int x=i-1;x<=i+1;x++)
	{
		for(int y=j-1;y<=j+1;y++)
		{ 
			if(change_matrix[x][y]>4)
	 		{
	 			change_matrix[x][y]=0;
	 		}
	 		
		}
	}
	
	change_matrix[i][j]=4;
	
	
}




void working_cctv()
{
	while(tables_left!=0)
	{
		run_count_matrix_once();

		for(int i=0;i<row;i++)
		{
			if(max_i==i)	
			{
					
				for(int j=0;j<column;j++)
				{
				/*
					delay(100);
					cout<<"\t"<<i<<"::"<<j<<endl;
					cout<<"After count once";
				*/	
					if(max_i==i && max_j==j)
					{
						cout<<"After if";
						update_change_matrix(i,j);

						tables_left-=max_count;

						max_count=0;

						display_change_matrix();
						
						cout<<"\n\n----------------------"<<tables_left<<"\n\n--------------------------------";
						
					}
				}
				
			}
		}
	}
}





/*SEAT ALLOCATION STARTS*/


int place_members(int &z,int p,int q,int cnt1,int** traversed)
{
        if(arr1[p][q]==6)
        {
                arr1[p][q]=cnt1;
                traversed[p][q]=1;
                z++;
                cout<<z;
        }
        
        else
        {
                traversed[p][q]=1;
                return -1;
        }
        
        if(     (arr1[p-1][q]==6)&&   (p-1>=0)&&         (traversed[p-1][q]==0))
        {       //cout<<"\nzzzzzzzz\n";
                place_members(z,p-1,q,cnt1,traversed);
                //traversed[p-1][q]=1;       
        }
        if(     (arr1[p][q-1]==6)&&      (q-1>=0)&&      (traversed[p][q-1]==0))
        {       //cout<<"wwwwwwwwwwww\n";
                place_members(z,p,q-1,cnt1,traversed);
                //traversed[p][q-1]=1;
        }
        if(     (arr1[p+1][q]==6)&&   (p+1<=row)&&       (traversed[p+1][q]==0))
        {       //cout<<"xxxxxxxxxxxxx\n";
                place_members(z,p+1,q,cnt1,traversed);
               // traversed[p+1][q]=1;
        }
        if(     (arr1[p][q+1]==6)&&      (q+1<=column)&&          (traversed[p][q+1]==0))
        {       //cout<<"qqqqqqqqqqqq\n";
                place_members(z,p,q+1,cnt1,traversed);
                //traversed[p][q+1]=1;
        }

       //cout<<"z="<<z;
        return z;
        
        
}





int* table_allocation()
{
        int cnt=100,flag=0;
    
	    int temp=0;
        
        count_arr1=new int[1000];
    
	    count_arr=new int[1000]; //counter of number of tables of same type
    
	    int **copy;     //initialised to 0 like avail 
    
	    copy=new int*[row];
    
	
	    for(int i=0;i<row;++i)
        {
                copy[i]=new int[column];
        }
        
        
        for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				/*if(arr[i][j]==6||arr[i][j]==5)
				copy[i][j]=6;
				else
				copy[i][j]=0;*/
				copy[i][j]=0;
				arr1[i][j]=arr[i][j];
			}
		}
	        
        
        for(int x=0;x<row;x++)
        {
                for(int y=0;y<column;y++)
                {
                        if(arr1[x][y]==6)
                        {
                            //    cout<<cnt<<"\n*******************************************************\n";
                                flag=place_members(temp,x,y,cnt,copy);
                                
                                count_arr[counter]=flag;
                                count_arr1[counter++]=cnt;
                                temp=0;
                                cnt++;
                                
                                
                        }
                        
                }
        }
        cout<<"copy\n\n\n"<<endl;
   
   
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<column;j++)
                {
                        cout<<copy[i][j]<<"\t";
                }
                cout<<endl;
        }
        cout<<"arr\n\n"<<endl;
   
   
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<column;j++)
                {
                        cout<<arr1[i][j]<<"\t";
                }
                cout<<endl;
        }
        cout<<"count_arr\n\n";
        
   
   
        for(int i=0;i<counter;i++)
        {
                
                cout<<count_arr[i]<<":::"<<count_arr1[i]<<"\n";
                
        }
   
   
    return count_arr;
        

        
}



void person_allocation()
{
        int min=INT_MAX,flag;
        bool choice=false;      //0 VIP 1 Normal    
        
		
		cout<<"Enter no of persons:\t";
        cin>>no;
        cout<<"For VIP / Normal (0/1):\t";
        cin>>choice;
               
        if(choice)
        {
             
                finally_allocate_normal_table(no);
        }
        
		else
        {
                finally_allocate_vip_table(no);
        }
            
       // calculate_occurence(min);

        cout<<"copy\n\n\n"<<endl;
   
   
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<column;j++)
                {
                        //cout<<copy[i][j]<<"\t";
                }
                cout<<endl;
        }
        cout<<"arr\n\n"<<endl;
   
   
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<column;j++)
                {
                        cout<<arr1[i][j]<<"\t";
                }
                cout<<endl;
        }
        cout<<"count_arr\n\n";
        
   
   
        for(int i=0;i<counter;i++)
        {
                
                cout<<count_arr[i]<<":::"<<count_arr1[i]<<"\n";
                
        }
   



}






void count_vip_tables()
{
        
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<column;j++)
                {
                        if(arr1[i][j]==5)
                        {
                                number_of_vip_tables++;
                        }               
                }
        }
}







void find_and_allocate_vip(int &number_of_persons)
{
         for(int i=0;i<row;i++)
        {
                for(int j=0;j<column;j++)
                {
                        if(arr1[i][j]==5&&number_of_persons>0)
                        {
                                arr1[i][j]=-99; // VIP ALLOCATED
                                number_of_vip_tables--;
                                number_of_persons-=4;
                        }               
                }
        }
}





void finally_allocate_vip_table(int &number_of_persons)
{
        count_vip_tables();
        
		
		
	
		if(number_of_vip_tables>=(((number_of_persons/4)+1)&& (number_of_persons>0)))
        {
                while(number_of_persons>0)
                {
                        find_and_allocate_vip(number_of_persons);        
                        //number_of_persons-=4;
                }     
				
				
                         
        }
        else
        {
        	cout<<"\n\nVIP not Available\n"<<endl; system("pause");	
		}
            
                
                
    
		
		
}





int find_normal_table()
{

        int flag=0,temp1;
        int min=INT_MAX;
        for(int i=0;i<counter;i++)
                {      
                        if(abs(count_arr[i]-no)<min)
                        {
                                min=abs(count_arr[i]-no);
                                flag=i;
                                
                        }
                        
                }
        

        return flag;
}






void allocate_normal_table(int flag,int &no_of_persons)
{
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<column;j++)
                {
                        if(arr1[i][j]==count_arr1[flag]&&no_of_persons>0)
                        {
                                arr1[i][j]=-66; // NORMAL ALLOCATED
                                no_of_persons-=4;
                                count_arr[flag]-=1;
                        }               
                }
        }
}



void finally_allocate_normal_table(int &no)
{
        int flag=0,temp1;
        
        /*for(int i=0;i<counter;i++)
                {      
                        if(abs(count_arr[i]-no)<min)
                        {
                                min=abs(count_arr[i]-no);
                                flag=i;
                                
                        }
                        
                }   
        */
        
        flag=find_normal_table();
        
        
        
        if(count_arr[flag]*4>=no)
        {
        
                while(no>0)
                {
                        allocate_normal_table(flag,no);
                        //no-=4;
                }
        
        }               


        /*
        for(int i=0;i<row;i++)
        {
                for(int j=0;j<column;j++)
                {
                        if(arr1[i][j]==count_arr1[flag])
                        {
                                arr1[i][j]=-66;
                                no-=4;
                        }       
                }
        }*/


} 




/*DP COINAGE STARTS*/


struct a
{
    int val;
    struct a *next;
};

struct a *start=NULL, *end=NULL, *t;

void insert(int y)
{
	
	//printf("\n\nInside Insert \n\n");
	
    struct a *temp;
    temp=(struct a *)malloc(sizeof(struct a));
    temp->val=y;
    temp->next=NULL;
    
	if(start==NULL)
	{
	//	printf("\n\nCreated Starting element\n\n");
		start=end=temp;	
	}
    
	else
    {
	//	printf("\n\nCreated End element\n\n");
		
		end->next=temp;
		end=temp;
    }
}

int minimum(int a, int b)
{
    if(a<b)
	return a;
    else
	return b;
}

void dp1()
{
    
	printf("\n Enter amount (minimum Rs 1000) to be exchanged (in thousands): ");
    
	scanf("%d", &amount);
    
	
	if(amount>0)
    {
		for(i=0; i<8; i++)
		{
		    dp[i]=(int *)malloc((amount+1)*sizeof(int));	
		}
		
		
		
		for(j=0; j<=amount; j++)
		{
		    dp[0][j]=INT_MAX;	
		}
				
		
		for(i=1; i<8;i++)
		{
		    dp[i][0]=0;
		    
			for(j=1; j<=amount; j++)
		    {
				if(j-denomination[i]>=0)
				{
				    dp[i][j] = minimum( 1+dp[i][j-denomination[i]], dp[i-1][j] );	
				}
				
				
				else
				{
				    dp[i][j] = dp[i-1][j];	
				}
				
		    }
		}
		 
		for(j=0; j<=amount; j++)
		{
			dp[0][j]=0;	
		}
		
		
		printf("\n No of chips needed: %d \n", dp[7][amount]);
		
	/*	
		for(i=0; i<8; i++)
		{
		    printf("\n ");
		    for(j=0; j<=amount; j++)
		    {
			printf("%d ", dp[i][j]);
		    }
		}
		
	*/
    
	}
    
	else
	{
		printf("\n Invalid Amount!");	
	}
	
	
	//printf("\n\n FInished DP 1");
	
}



void dp2(int j)
{
	//int k=7;
	
	//printf("\n\nInside Dp2\n");
	
    //int x=0;
    for(i=7; i>=0;)
    {
    	
    /*	
		printf("\n\nInside For Loop\n");
    	
    	printf("\n\n This is DP[k][j]= %d", dp[i][j]);
    	
    */	
    	if(i==0)
    	{
    		break;
		}
    	
    //	printf("\n\n This is DP[k-1][j]= %d", dp[i-1][j]);
    	
		if(dp[i][j]!=dp[i-1][j])
		{
			
			/*
			
			printf("\n\nInside First if");

			printf("\n\n*************----------------The value of i = %d",i );
			
			*/
			
		    if(j-denomination[i]>=0)
		    {
		    	
		    //	printf("\n\nInside Second IF");
		    	
				j=j-denomination[i];
				
				insert(denomination[i]);
				
				/*displaying each time*/
				
				/*
				t=start;
			   
			    while(t!=NULL)
			    {
					printf("%d ", t->val);
					
					t=t->next;
				}
				*/
	
	
		    }
		    
			else
			{
			//	printf("\n\nInside Else\n\n");
				
				break;
			}
				
		
				
		}
		
		
		
		else
		{
		//	printf("\n\nInside Outter else\n\n");
			i--;
		}
		
		
		
		
			
    }
    
	printf("\n Required chips are of denominations: ");
    
	t=start;
   
    while(t!=NULL)
    {
		printf("%d ", t->val);
		
		t=t->next;
	}

}


/*WORKING DISPLAY FROM HERE*/


void seating_for_working_1()
{
	
	int min=10000;
	int *a;
	
	a=table_allocation();
	
}

void seating_for_working_2()
{

	person_allocation();



    for(int i=0;i<row;i++)
    {
            for(int j=0;j<column;j++)
            {
                    cout<<arr1[i][j]<<"\t";
            }
            cout<<endl;
    }
	
	
	system("pause");
	
	

	
}








void working()
{
	
	int flag_for_seating=0;
	
	int choice,choice_2;
	
	int flag_show=0;
	
	while(true)
	{
		
		cout<<"\n\n\t\t\t\tWELCOME";
		cout<<"\nWhat are you?";
		cout<<"\n1. Employer";
		
		if(flag_show)
		{
			cout<<"\n2. Customer";	
			cout<<"\n3. Exit";
		}
		
		cout<<"\n\nEnter your choice:\t";
		cin>>choice;
		
		
		switch(choice)
		{
			case 1:	flag_show=1;
					
					/*TABLE PLACEMENT*/
					
					cout<<"\n\n\n\t\t\t\tTABLE PLACEMENT";
					
					system("cls");
					
					input_matrix();
					
					place_tables();
					
					display_matrix();
					
					system("pause");
					
					/*CCTV*/
					
					cout<<"\n\n\t\t\t\tNOW THE CCTV PLACEMENT";
				
					
					display_change_matrix();
				
					copy_matrix();
					
					display_change_matrix();
				
					run_count_matrix_once();
				
					working_cctv();
					
					display_change_matrix();
					
					cout<<endl;
				
					system("pause");
					
					
					
					break;
					
			
			
			case 2: 
					while(true)
					{
						cout<<"\n\n\n\n\t\t\t\tWELCOME SIR";
						cout<<"\n\nWhat would you like to do?";
						cout<<"\n1. Change Money for CHIPS";
						cout<<"\n2. Reserve a table"; 
						cout<<"\n3. Exit";
						
						cout<<"\n\nEnter your choice:\t";
						cin>>choice_2;
				
						
						
						switch(choice_2)
						{
							case 1:	cout<<"\n\n\n\n\n\t\t\tWELCOME TO CHIP CHANGING COUNTER";
									
									cout<<endl<<endl;
									
									system("pause");
									
									dp1();
								    
								    dp2(amount);
								    
								    printf("\n\n");
								    
									system("pause");
									
									break;
							
							
							
							
							case 2:	
									
									if(flag_for_seating==0)
									{
										seating_for_working_1();
										flag_for_seating=1;	
									}
									
									seating_for_working_2();
									
									/*
									int min=10000;
									int *a;
									
									a=table_allocation();
									person_allocation();
								
								
								
								    for(int i=0;i<row;i++)
								    {
								            for(int j=0;j<column;j++)
								            {
								                    cout<<arr1[i][j]<<"\t";
								            }
								            cout<<endl;
								    }
									
									
									system("pause");*/
									

									
							
									break;
							
							case 3:	exit(0); break;
							
							default: cout<<"INVALID!";
									 system("pause");
							
									 break;		
												
						}
					
						
					}
			
					
					
					break;
			
		
			case 3: exit(0); break;
		
		
			default: cout<<"INVALID!";
						system("pause");
			
					break;		
			
		}
		
	}
	
	
}







int main()
{
	
	
	working();
	
	/*
//table placement now
	
	system("cls");
	
	input_matrix();
	
	place_tables();
	
	display_matrix();
	
	system("pause");
	
	
//cctv now
	
	display_change_matrix();

	copy_matrix();
	
	display_change_matrix();

	run_count_matrix_once();

	working_cctv();
	
	display_change_matrix();
	
	system("pause");
	
	
//seat placement now

	int min=10000;
	int *a;
	
	a=table_allocation();
	person_allocation();



    for(int i=0;i<row;i++)
    {
            for(int j=0;j<column;j++)
            {
                    cout<<arr1[i][j]<<"\t";
            }
            cout<<endl;
    }
	
	
	system("pause");
	

//DP Coinage Now

	dp1();
    
    dp2(amount);
    
    printf("\n\n");
    
	system("pause");
	
		*/
	return 0;
}
