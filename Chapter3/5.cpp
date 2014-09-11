#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
char *p[] = {"et-ic", "al-is-tic", "s-tic", "p-tic", "-lyt-ic", "ot-ic", "an-tic",
"n-tic", "c-tic", "at-ic", "h-nic", "n-ic", "m-ic", "l-lic", "b-lic", "-clic", "l-ic",
"h-ic", "f-ic", "d-ic", "-bic", "a-ic", "-mac", "i-ac"};
int getlastsamechar(char* a)
{
	int result = -1;
	int i = 0;
	int j = 0;
	int alen = strlen(a);
	char* aswap = new char[alen + 1];
	strcpy(aswap, a);
	for(i = 0; i < alen/2; i++)
	{
		char c = aswap[i];
		aswap[i] = aswap[alen - 1 - i];
		aswap[alen - 1 - i] = c;
	}
	printf("%s\n",aswap);
	int n = sizeof(p)/sizeof(char*);
	for(i = 0; i < n; i++)
	{
		int len = strlen(p[i]);
		char* b = new char[len+1];
		strcpy(b,p[i]);
		for(j = 0; j < len; j++)
		{
			if(b[j] == '-')
			{
				for(int q = j; q < len; q++)
				{
					b[q] = b[q+1];
				}
				len--;
			}
		}
		for(j = 0; j < len/2; j++)
		{
			char c = b[j];
			b[j] = b[len - 1 - j];
			b[len - 1- j] = c;
		}
		if(alen >= len)
		{
			for(j = 0; j < len; j++)
			{
				if(aswap[j] != b[j])
				{
					break;
				}
			}
			delete b;
			if(j == len)
			{
				result = i;
				break;
			}
		}

	}
	delete aswap;
	return result;
}
int main()
{
	char *a = "clinic";
	int result = getlastsamechar(a);
	printf("%d\n",result);
	if(-1 != result)
	{
		char* res = new char[strlen(p[result]) + 1];
		strcpy(res, p[result]);
		printf("%s\n", res);
	}

    return 0;
}
