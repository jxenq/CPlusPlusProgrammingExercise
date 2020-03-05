#include<iostream>

using namespace std;

int main()
{
	int space = 7,i,j;
	for(i = 0;i < 4;i++)
	{
		for(j = 0;j < 30;j++)
		{
			cout << " ";	
		}
		for(j = 0;j < space - 1;j++)
		{
			cout << " ";
		}
		for(j = 0;j <= 7 - space;j++)
		{
			cout << "*";
		}
		cout << '\n';
		space -= 2;
	}
	space = 5;
	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 30;j++)
		{
			cout << " ";	
		}
		for(j = 0;j < space;j++)
		{
			cout << "*";
		}
		for(j = 0;j < 7 - space;j++)
		{
			cout << " ";
		}
		cout << '\n';
		space -= 2;
	}
}

/*                                  *                                  
				  ***
                                *****
                              *******
                              *****
                              ***
                              * 
*/


