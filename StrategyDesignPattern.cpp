#include<iostream>
using namespace std;

// first we make the strategies 
class walkable{
    public:
    virtual void walk()=0;
    virtual ~walkable() {}
};

// concrete class of the walkable strategy
class normalwalk:public walkable{
    public:
    void walk(){
        cout<<"I am walking normally"<<endl;
    };
};
class nowalk:public walkable{
    public:
    void walk(){
        cout<<"I am not walking"<<endl;
    };
};

//2nd strategy 
class flyable{
    public:
    virtual void fly()=0;
    virtual ~flyable() {}
};

// concrete class of the flyable strategy
class normalfly:public flyable{
    public:
    void fly(){
        cout<<"I am flying normally"<<endl;
    };
};
class noflyway:public flyable{
    public:
    void fly(){
        cout<<"I am not flying"<<endl;
    };
};

class robot{
    protected:
    walkable* walkstrategy;
    flyable* flystrategy;

    public:
    robot(walkable* w,flyable* f){
        this->walkstrategy=w;
        this->flystrategy=f;
    }

    void walk(){
        walkstrategy->walk();
    }
    void fly(){
        flystrategy->fly();
    }

    virtual void projection()=0;


};

// concrete robot class
class companionrobot:public robot{
    public:
    companionrobot(walkable* w,flyable* f):robot(w,f){}
    void projection(){
        cout<<"I am a companion robot"<<endl;
    }
};

class enemyrobot:public robot{
    public:
    enemyrobot(walkable* w,flyable* f):robot(w,f){}
    void projection(){
        cout<<"I am an enemy robot"<<endl;
    }
};

int main(){
    robot * robot1=new companionrobot{new normalwalk(), new normalfly()};
    robot1->walk();
    robot1->fly();
    robot1->projection();
    
    cout<<"--------------------"<<endl;

    robot * robot2=new enemyrobot{new nowalk(), new noflyway()};
    robot2->walk();
    robot2->fly();
    robot2->projection();
    return 0;
}
