#include <iostream>
using namespace std;
char *number[] = {"1011111","0000101","1110110","1110101","0101101",
	"1111001","1111011","0010101","1111111","1111101"};
char** getNumber(int bit)
{
	char** result= new char*[5];
	for(int i = 4; i >= 0; i--)
	{
		result[i] = number[bit%10];
		bit/=10;
	}
	return result;
}
int main()
{
    int number;
    cin>>number;
char** num = getNumber(number);
	for(int i = 0; i < 5; i++)
	{
		cout<<*num<<endl;
		num++;
	}
	return 0;
}
