
#include <iostream>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#define m 1000 		//к-сть розбиттів по Х
#define n 1000	 	//к-сть розбиттів по У
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
	 cout << "Невірні дані" << endl; 
}
		return s;     			//   повертає значення "s" 
} 	

void Func(){
	double a=0,b=0,c=0,d=0,h=0,h1=0,s=0,x1=0,y1=0; 			// змінні
	double t1, t2;											// runtime
	int i,j,nTheads, theadNum;
cout<<"Введiть межi iнтегрування по х (а,b), по у (c,d))"<<endl;
cout<<"Значення верхньої i нижньої меж iнтегрування не повиннi збiгатись"<<endl;
    cout<<"a= ";	//  нижня межа інтеграла
    cin>>a;
    cout<<"b= ";	//  верхня межа інтеграла
	cin>>b;
	cout<<"c= ";	//  нижня межа інтеграла
	cin>>c;
	cout<<"d= ";	//  верхня межа інтеграла 
	cin>>d;

double a1=a,c1=c;
h=(b-a)/n;                       //  величина кроку
h1=(d-c)/m;                      //  величина кроку

    cout<<"Кiлькiсть потокiв = ";
    cin>>nTheads;
    omp_set_num_threads(nTheads);

t1 = omp_get_wtime(); // початковий час обрахунку

				// задає всім змінним, яким не заданий клас, клас shared
				// задає список змінних для яких створюються локальні копії
		#pragma omp parallel for  default(shared) private(i,j) //reduction(+:s)
							//створює для кожного потоку копію змінної "s"				

for(i=1	; i<m+1; i++)							//  умова циклy while(x1<b)						
    {
	   for(j=1; j<n+1; j++)							//while(y1<d)								  
        {   		
			//переменноя может быть атомарной, в целях оптимизации лучше использовать директиву atomic		
			#pragma omp atomic					 	//  алгоритм знаходження площі для прямокутників
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
     default:      cout << "Невірні дані" << endl;	
  }
time2 = omp_get_wtime(); 			// кінець роботи потоками
cout<<"Runtime : "<<t2-t1;
cout<<"Iнтеграл вiд функцiї "<<str<<" на промiжку["<<a1<<";"<<b<<"]["<<c1<<";"<<d<<"] дорiвнює "<<s<<endl;
}
};

int main(){

	int A, B, px, py, count;	
setlocale(LC_CTYPE, "rus"); 
bool repeat=true;

while(repeat)
{	
		cout <<"Виберiть тип виразу який потрiбно проiнтеруати:" << endl; 
  		cout <<"1:	s = x*x+y*y;" << endl;
     	cout <<"2:	s = A*pow(x,px)+B*pow(y,py);" << endl;
     	cout <<"3:	s = A*cos(pow(x,px))+B*sin(pow(y,py));" << endl;
     	cout <<"Введiть номер виразу: ";
 		cin >> count;
 		if(count==2||count==3)
 		{
		 	cout <<"\nВведiть A: ";
 			cin >> A;
 			cout <<"Введiть B: ";
 			cin >> B;
 			cout <<"Введiть px: ";
 			cin >> px;
 			cout <<"Введiть py: ";
 			cin >> py; 			
		 }
 		integral Obj(count, A, B, px, py);
		Obj.Func();

	cout<<"Повторити? enter true(1) or false(0): ";
	cin>>repeat;
}
//system("pause");
return 0;
}








/*	double n,m;
	cout<<"Введiть кiлькiсть розбиттiв для 'n' i 'm'"<<endl;
	cout<<"n= ";	//  кількість розбиттів по X
	cin>>n;
	cout<<"m= ";	//  кількість розбиттів по Y
	cin>>m;
*/
