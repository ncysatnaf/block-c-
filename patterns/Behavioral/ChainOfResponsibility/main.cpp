//
//  ChainOfResponsibility.cpp
//  block-c++
//
//  Created by vai on 1/4/17.
//  Copyright © 2017 nanoo. All rights reserved.
//

#include <iostream>

using namespace std;

class Handler
{
public:
    Handler *successor;
public:
    virtual void Handle(int requestNo) = 0;
    void MakeSuccessor(Handler *obj)
    {
        successor = obj;
    }
    
};

class ConcreteHandler1 : public Handler
{
public:
    void Handle(int requestNo)
    {
        cout << "ConcreteHandler1::Handle()\n";
        if(requestNo < 5)
        {
            cout << "Handled Request Number :" << requestNo << "\n";
        }
        else if (successor != NULL)
        {
            successor->Handle(requestNo);
        }
    }
};

class ConcreteHandler2 : public Handler
{
public:
    void Handle(int requestNo)
    {
        cout << "ConcreteHandler2::Handle()\n";
        if(requestNo < 10)
        {
            cout << "Handled Request Number :" << requestNo << "\n";
        }
        else if (successor != NULL)
        {
            successor->Handle(requestNo);
        }
    }
};

int main()
{
    Handler *handle1 = new ConcreteHandler1();
    Handler *handle2 = new ConcreteHandler2();
    handle1->MakeSuccessor(handle2);
    
    handle1->Handle(4);
    handle1->Handle(6);
    handle1->Handle(11);
    
    return 0;
}
