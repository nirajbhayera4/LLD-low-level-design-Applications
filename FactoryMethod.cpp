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

class basicWheatBurger : public Burger
{
public:
    void prepare()
    {
        cout << "Preparing basic wheat burger" << endl;
    }
};
class specialWheatBurger : public Burger
{
public:
    void prepare()
    {
        cout << "Preparing special wheat burger" << endl;
    }
};



class burgerfactory{
    public:
    virtual Burger* createBurger(string& type)=0;
};

class singhBurger: public burgerfactory{
    public:
    Burger* createBurger(string& type) override{
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
class KingBurger:public burgerfactory{
    public:
    Burger* createBurger(string& type) override{
        if(type=="basic"){
            return new basicWheatBurger();
        }
        else if(type=="special"){
            return new specialWheatBurger();
        }
        else{
            cout<<"Invalid burger type"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type="special";
    burgerfactory * newfactory=new singhBurger();
    Burger * newburger=newfactory->createBurger(type);
    newburger->prepare();
   return 0;
}