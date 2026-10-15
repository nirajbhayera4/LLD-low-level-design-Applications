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

class garlicbread{
    public:
    virtual void prepare()=0;
};
class basicgarlicbread: public garlicbread{
    public:
    void prepare(){
        cout<<"Preparing basic garlic bread"<<endl;
    }
};
class specialgarlicbread: public garlicbread{
    public:
    void prepare(){
        cout<<"Preparing special garlic bread"<<endl;
    }
};

class wheatgarlicbread : public garlicbread{
    public:
    void prepare(){
        cout<<"Preparing wheat garlic bread"<<endl;
    }
};
class specialwheatgarlicbread : public garlicbread{
    public:
    void prepare(){
        cout<<"Preparing special wheat garlic bread"<<endl;
    }
};



class mealfactory{
    public:
    virtual Burger* createBurger(string& type)=0;
    virtual garlicbread* createGarlicBread(string& type)=0;
};

class singhBurger: public mealfactory{
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
    garlicbread* createGarlicBread(string& type) override{
        if(type=="basic"){
            return new basicgarlicbread();
        }
        else if(type=="special"){
            return new specialgarlicbread();
        }
        else{
            cout<<"Invalid garlic bread type"<<endl;
            return nullptr;
        }
    }

};
class KingBurger:public mealfactory{
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
    garlicbread* createGarlicBread(string& type) override{
        if(type=="basic"){
            return new wheatgarlicbread();
        }
        else if(type=="special"){
            return new specialwheatgarlicbread();
        }
        else{
            cout<<"Invalid garlic bread type"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string burgertype="special";
    string breadtype="special";
    mealfactory * newfactory=new singhBurger();
    Burger * newburger=newfactory->createBurger(burgertype);
    garlicbread * newgarlicbread=newfactory->createGarlicBread(breadtype);
    newburger->prepare();
    newgarlicbread->prepare();
   return 0;
}