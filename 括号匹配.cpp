#include<iostream>
#include<cstdio>
typedef struct Node* NodePoint;
typedef class Stack* StackPoint;
struct Node{
    char data;
    NodePoint Link;
};
class Stack{
private:
    NodePoint head;
    NodePoint p;
    int StackLength;
    int Left;
    int Right;
public:
    Stack(){
        this->head=NULL;
        this->StackLength=0;
        this->Left=0;
        this->Right=0;
    }
    void LeftAdd(){
        this->Left++;
    }
    void RightAdd(){
        this->Right++;
    }
    int GetLeft(){
        return this->Left;
    }
    int GetRight(){
        return this->Right;
    }
    int GetLength(){
        return this->StackLength;
    }
    void StackPush(char data){
        NodePoint NewNode=new Node;
        NewNode->data=data;
        if(this->head==NULL){
            NewNode->Link=NULL;
            this->head=NewNode;
            this->p=NewNode;
        } else{
            NewNode->Link=this->p;
            this->p=NewNode;
        }
        this->StackLength++;
    }
    char StackPop(){
        if(this->StackLength<=0){
            abort();
        }
        NodePoint DeleteNode;
        char data;
        DeleteNode=this->p;
        data=p->data;
        this->p=this->p->Link;
        delete (DeleteNode);
        this->StackLength--;
        return data;
    }
};
bool Varify(char data1,StackPoint* s1){
    bool stat=true;
    char var1;
    if((*s1)->GetLength()<=0){
        stat= false;
        return stat;
    }
    if((*s1)->GetLength()>0) {
        var1 = (*s1)->StackPop();
    }
    if(data1==')'&&var1!='('){
        stat= false;
    }
    if(data1=='}'&&var1!='{'){
        stat= false;
    }
    if(data1==']'&&var1!='['){
        stat= false;
    }
    return stat;
}
void PrintNode(StackPoint* s1){
    while ((*s1)->GetLength()>0){
        std::cout<<(*s1)->StackPop();
    }
}
bool ReadNode(){
    bool stat= true;
    char data1;
    StackPoint s2=new Stack();
    StackPoint s1=new Stack();
    data1=getchar();
    while (data1!='\n'){
        if(data1=='['||data1=='{'||data1=='('){
            s1->StackPush(data1);
            s1->LeftAdd();
        }
        if(data1==']'||data1=='}'||data1==')'){
            s1->RightAdd();
            stat=Varify(data1,&s1);
        }
        data1=getchar();
    }
if(s1->GetRight()!=s1->GetLeft()){
    stat= false;
}
std::cout<<s1->GetLeft()<<" "<<s1->GetRight()<<"\n";
    return stat;
}
int main(){
    bool stat;
    stat=ReadNode();
    if(stat== false){
        std::cout<<"NO";
    } else{
        std::cout<<"YES";
    }
}

