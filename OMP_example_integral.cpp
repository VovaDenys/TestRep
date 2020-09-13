
#include <iostream>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#define m 1000 		//�-��� �������� �� �
#define n 1000	 	//�-��� �������� �� �
using std::cout;		
using std::cin;
using std::endl;

using namespace std;

	
class integral {
 	int A, B, px, py, count;	
public:
	
	integral(int count,int A,int B,int px,int py):count(count),A(A),B(B),px(px),py(py)	{	}
	
double Fx(double x, double y)
{ 
double s;

  switch (count) 
  {  	
     case 1: 
     {   	s=x*x+y*y;								break; 		}
     case 2: 
     {		s = A*pow(x,px)+B*pow(y,py);			break;      }
     case 3: 
     {   	s = A*cos(pow(x,px))+B*sin(pow(y,py));	break;	    }
     default: count= 1;  
	 cout << "����� ���" << endl; 
}
		return s;     			//   ������� �������� "s" 
} 	

void Func(){
	double a=0,b=0,c=0,d=0,h=0,h1=0,s=0,x1=0,y1=0; 			// ����
	double t1, t2;											// runtime
	int i,j,nTheads, theadNum;
cout<<"����i�� ���i i����������� �� � (�,b), �� � (c,d))"<<endl;
cout<<"�������� ������� i ������ ��� i����������� �� ������i ��i������"<<endl;
    cout<<"a= ";	//  ����� ���� ���������
    cin>>a;
    cout<<"b= ";	//  ������ ���� ���������
	cin>>b;
	cout<<"c= ";	//  ����� ���� ���������
	cin>>c;
	cout<<"d= ";	//  ������ ���� ��������� 
	cin>>d;

double a1=a,c1=c;
h=(b-a)/n;                       //  �������� �����
h1=(d-c)/m;                      //  �������� �����

    cout<<"�i���i��� �����i� = ";
    cin>>nTheads;
    omp_set_num_threads(nTheads);

t1 = omp_get_wtime(); // ���������� ��� ���������

				// ���� ��� ������, ���� �� ������� ����, ���� shared
				// ���� ������ ������ ��� ���� ����������� ������� ��ﳿ
		#pragma omp parallel for  default(shared) private(i,j) //reduction(+:s)
							//������� ��� ������� ������ ���� ����� "s"				

for(i=1	; i<m+1; i++)							//  ����� ����y while(x1<b)						
    {
	   for(j=1; j<n+1; j++)							//while(y1<d)								  
        {   		
			//���������� ����� ���� ���������, � ����� ����������� ����� ������������ ��������� atomic		
			#pragma omp atomic					 	//  �������� ����������� ����� ��� ������������
			s+= Fx( (2*(a+i*h)-h)/2.,(2*(c+i*h1)-h1)/2. );
		}  	
    }
			s*=h*h1;

std::string str = "";	
switch (count) 
  {  	
     case 1: 
     { 			 	str="x*x+y*y";	  						break;     }
     case 2: 
     {		     	str="A*pow(x,px)+B*pow(y,py)";	    	break;     }
     case 3: 
     {     			str="A*cos(pow(x,px))+B*sin(pow(y,py))";break;     }
     default:      cout << "����� ���" << endl;	
  }
time2 = omp_get_wtime(); 			// ����� ������ ��������
cout<<"Runtime : "<<t2-t1;
cout<<"I������� �i� �����i� "<<str<<" �� ����i���["<<a1<<";"<<b<<"]["<<c1<<";"<<d<<"] ���i���� "<<s<<endl;
}
};

int main(){

	int A, B, px, py, count;	
setlocale(LC_CTYPE, "rus"); 
bool repeat=true;

while(repeat)
{	
		cout <<"�����i�� ��� ������ ���� ����i��� ���i��������:" << endl; 
  		cout <<"1:	s = x*x+y*y;" << endl;
     	cout <<"2:	s = A*pow(x,px)+B*pow(y,py);" << endl;
     	cout <<"3:	s = A*cos(pow(x,px))+B*sin(pow(y,py));" << endl;
     	cout <<"����i�� ����� ������: ";
 		cin >> count;
 		if(count==2||count==3)
 		{
		 	cout <<"\n����i�� A: ";
 			cin >> A;
 			cout <<"����i�� B: ";
 			cin >> B;
 			cout <<"����i�� px: ";
 			cin >> px;
 			cout <<"����i�� py: ";
 			cin >> py; 			
		 }
 		integral Obj(count, A, B, px, py);
		Obj.Func();

	cout<<"���������? enter true(1) or false(0): ";
	cin>>repeat;
}
//system("pause");
return 0;
}








/*	double n,m;
	cout<<"����i�� �i���i��� �������i� ��� 'n' i 'm'"<<endl;
	cout<<"n= ";	//  ������� �������� �� X
	cin>>n;
	cout<<"m= ";	//  ������� �������� �� Y
	cin>>m;
*/
