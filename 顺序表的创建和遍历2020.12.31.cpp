#include <iostream>
using namespace std;

class Sqlist {
public:
    int length=0;
    int listsize;
    int *elme;
    void initList(int n) {
        elme = new int[n];
        length = 0;
        listsize = n;
    }

    void showList(){
        for (int i = 0; i < listsize; ++i) {
            cout<<elme[i];
            if(i!=listsize-1)cout<<" ";
        }
    }
    void add(int n){
        elme[length++]=n;
    }
};
int main(){
    Sqlist l;
    int n;
    cin>>n;
    l.initList(n);
    int m;
    for (int i = 0; i < n; ++i) {
        cin>>m;
        l.add(m);
    }
    l.showList();
}