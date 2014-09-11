#include<iostream>
using namespace std;
typedef struct
{
    int year;
    int month;
    int day;
} date;
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isRunyear(int year)
{
    if(((year%4==0) && (year%100!=0))
        || (year % 400) == 0)
        return true;
    return false;
}
int yearDay(date d)
{
	int totalDay = 0;
	if(d.month==1)
			{
				totalDay = d.day;
			  return totalDay;
			}
	for(int i=1;i<d.month;i++)
	{
			totalDay += month[i];
	}
			totalDay += d.day;
		if(isRunyear(d.year))
			totalDay++;
			return totalDay;
}
int betweenDays(date d1,date d2)
{
	if(d1.year == d2.year)
		return yearDay(d2)-yearDay(d1);
	else
		{
			int totalDays = 0;
			for(int i=d1.year;i<d2.year;i++)
			{
				totalDays += isRunyear(i)?366:365;
			}
			return totalDays - yearDay(d1) + yearDay(d2);
		}
}
int dayOfWeek(date d)
{
    date d1;
    d1.year = d.year;
    d1.month = d.month;
    d1.day = 1;
    return betweenDays(d1,d) + 1;
}
int main()
{
    date d1;
    date d2;
    cin>>d1.year>>d1.month>>d1.day;
    cin>>d2.year>>d2.month>>d2.day;
    cout<<betweenDays(d1,d2)<<endl;
    date d3;
    cin>>d3.year>>d3.month>>d3.day;
    cout<<dayOfWeek(d3)<<endl;
    return 0;
}
