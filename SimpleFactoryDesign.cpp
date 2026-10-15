#include <iostream>

using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {} // virtual destructor
};

class basicBurger : public Burger
{
public:
    void prepare()
    {
        cout << "Preparing basic burger" << endl;
    }
};
class specialBurger : public Burger
{
public:
    void prepare()
    {
        cout << "Preparing special burger" << endl;
    }
};

class burgerfactory{
    public:
    Burger *createBurger(string& type){
        if(type=="basic"){
            return new basicBurger();
        }
        else if(type=="special"){
            return new specialBurger();
        }
        else{
            cout<<"Invalid burger type"<<endl;
            return nullptr;
        }

    }
};

int main(){
    string type="special";
    burgerfactory * newfactory=new burgerfactory();
    Burger * newburger=newfactory->createBurger(type);
    newburger->prepare();
   return 0;
}