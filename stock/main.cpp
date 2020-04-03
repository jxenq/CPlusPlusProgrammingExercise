#include <iostream>
#include "stock.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Stock s1;
	s1.acquire("abcde",20,12.17);
	s1.show();
	s1.buy(15,14);
	s1.show();	
	return 0;
}
