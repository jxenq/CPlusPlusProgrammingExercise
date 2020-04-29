#include <iostream>
using namespace std;

struct Queue {
    int data;
    Queue * next;
};

class MyQueue {
private:
    int front;
    int rear;
    Queue * Q;
public:
    MyQueue() {
        this->front = 0;
        this->rear = 0;
        this->Q = NULL;
    }
    void push(int x) {
        if(this->Q==NULL) {
            this->Q = new Queue;
            this->Q->data = x;
            this->Q->next = NULL;
            this->rear++;
        } else {
            Queue *p=this->Q, *last=NULL;
            do {
                last = p;
                p = p->next;
            } while(p!=NULL);
            Queue *c=new Queue;
            c->data = x;
            c->next = NULL;
            last->next = c;
            this->rear++;
        }
    }
    int size() {
        return this->rear - this->front;
    }
    int pop() {
        if(this->size()==0) return -1;
        int data;
        data = this->Q->data;
        this->Q = this->Q->next;
        this->front++;
        return data;
    }
};

int main() {
    int n, op;
    cin >> n;
    MyQueue q;
    while(n>0) {
        cin >> op;
        switch (op) {
            case 1: {
                int x;
                cin >> x;
                q.push(x);
                break;
            }
            case 2: {
                int popElement = q.pop();
                if(popElement==-1) cout << "Invalid" << endl;
                else cout << popElement << endl;
                break;
            }
            case 3: {
                cout << q.size() << endl;
                break;
            }
        }
        n--;
    }
    
    return 0;
}
