#ifndef STOCK_H_//如果定义了 STOCK_H_，此条件为假 ，则该语句与
//#endif之间的所有内容，不做编译处理 
#define STOCK_H_//宏名 

//条件编译 ，属于编译预处理， 与第二行的宏定义配合，避免重复包含 

#include <string>

class Stock
{
	private:
		std::string company;
		//双冒号，命名空间域解析运算符
	/*
	命名空间
	namespace wenhui{
	   double pail;
	   void fetch();
	   in pal;
	   struct well{....} ;	
	} 
	namespace jiaxing{
	   double bucket(double n){......};
	   void fetch();
	   in pal;
	   struct hill{....} ;	
	} 	
    用法：	
	using wenhui;
	using wenhui::fetch;
	std::string company;
	
	*/
		
		long shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val;}
	// 私有的方法，而且实现了，是一个内联函数 
	//类内的方法里面随意访问所有成员 
	public:
		void acquire(const std::string &co,long n,double pr);
		void buy(long num,double price);
		void sell(long num,double price);
		void update(double price);
		void show();	
		};

#endif
