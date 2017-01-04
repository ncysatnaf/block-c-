//
//  Command.cpp
//  Behavioral
//
//  Created by vai on 1/4/17.
//  Copyright © 2017 nanoo. All rights reserved.
//

#include <iostream>

using namespace std;


class Receiver
{
    
public:
    void Action()
    {
        cout << "Inside Receiver::Action()\n";
    }
};

class Command
{
    
public:
    virtual void Execute() = 0;
    
};

class ConcreteCommand : public Command
{
    
private:
    Receiver *receiver;
    
public:
    ConcreteCommand(Receiver *obj)
    {
        receiver = obj;
    }
    
    void Execute()
    {
        receiver->Action();
    }
    
};

class Invoker
{
    
private:
    Command *cmd;
    
public:
    Invoker(Command *obj)
    {
        cmd = obj;
    }
    
    void ExecuteCmd()
    {
        cmd->Execute();
    }
};


int main()
{
    Receiver *receiver = new Receiver();
    Command *cmd = new ConcreteCommand(receiver);
    Invoker *invoker = new Invoker(cmd);
    invoker->ExecuteCmd();
    
    return 0;
}
