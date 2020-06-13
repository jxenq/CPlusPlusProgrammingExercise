#include<iostream> 
using namespace std;
typedef struct queue{
	int x;
	struct queue *next;
} LinkList;	//结构体 
class  MyQueue{
	LinkList *head, *node, *end; //结构体成员 
	static int j;	//队列长度 
	public:
		MyQueue()		//构造函数 
		{
			head=NULL; 
			node=NULL;
			end=NULL; 
			head=new LinkList;
			end=head;
			
		}
		void push(int x)	//入队函数 
		{
	    	node=new LinkList;
			node->x=x;
			end->next=node;
			node=end; 
			j++;			//队列长度++ 
		}
		void pop()		//出队函数 
		{
			if(j==0)				//队列为空 
		    	cout<<"Invalid"<<endl;
			else
			     {
			     	cout<<head->next->x<<endl;	//输出队首元素 
			     	head->next=head->next->next;
			     	delete head->next;				//头一个删了 
		        	j--;
				 }
		}
		int size()		//求队列长度函数 
		{
			return j;
		}
};
int MyQueue::j=0;

int main(void)
{
	MyQueue ob;		//对象 
	int n,i,c,d;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				{
					scanf("%d",&d);
					ob.push(d);
					break;
				}
			case 2:ob.pop();break;
			case 3:cout<<ob.size()<<endl;break;
		}
	}
}
