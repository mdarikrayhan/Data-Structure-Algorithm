#include <bits/stdc++.h>
using namespace std;
int main(){
cout<<"2^15 =                     32,768\n2^16 =                     65,536"<<endl;
cout<<"2^31 =              2,147,483,648\n2^32 =              4,294,967,296"<<endl;
cout<<"2^63 =  9,223,372,036,854,775,808 \n2^64 = 18,446,744,073,709,551,616"<<endl;
cout<<"\n\n";
//short int	2	-32,768 to 32,767
short int si1=-32768,si2=32767;
cout<<"short int negative : "<<si1<<"\nshort int positive : "<<si2<<endl;
//unsigned short int	2	0 to 65,535
unsigned short int usi=65535;
cout<<"unsigned short int : "<<usi<<endl;
//int	4	-2,147,483,648 to 2,147,483,647
int i1=-2147483648,i2=2147483647;
cout<<"int negatvie : "<<i1<<"\nint positive : "<<i2<<endl;
//unsigned int	4	0 to 4,294,967,295
unsigned int ui=4294967295;
cout<<"unsigned int : "<<ui<<endl;
//long int	4	-2,147,483,648 to 2,147,483,647
long int li1=-2147483648,li2=2147483647;
cout<<"long int negative : "<<li1<<"\nlong int positive : "<<li2<<endl;
//unsigned long int	8	0 to 4,294,967,295
unsigned long int uli=4294967295;
cout<<"unsigned long int : "<<uli<<endl;
//long long int	8	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
long long int lli1= -9223372036854775807,lli2=9223372036854775807;//using 808 at negative gives warning
cout<<"long long int negative : "<<lli1<<"\nlong long int positive : "<<lli2<<endl;
//unsigned long long int	8	0 to 18,446,744,073,709,551,615
unsigned long long int ulli=18446744073709551615;
cout<<"unsigned long long int : "<<ulli<<endl;
//signed char	1	-128 to 127
signed char sc1=-128,sc2=127;
cout<<"signed char negative : "<<sc1<<"\nsigned char positive : "<<sc2<<endl;
//unsigned char	1	0 to 255
unsigned char uc=255;
cout<<"unsigned char : "<<uc<<endl;
//float	4
//double	8	 
//long double	12	 
//wchar_t	2 or 4	1 wide character
}
