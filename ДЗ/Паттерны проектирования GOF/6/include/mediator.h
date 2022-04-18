#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <ScreenSingleton.h>

class Mediator;
class Colleague
{
public:
    Colleague() : _x(0.0), _y(0.0) {}
    virtual void BeNotified(std::string info) = 0;
    virtual void SomeActions() = 0;
    virtual ~Colleague(){};
    static Mediator* pMediator;

    double _x, _y;
};

class Mediator {
public:
    void AddColleague(Colleague* pNewColleague)
    {
        v.push_back(pNewColleague);
    };

    void Notify(Colleague* from, std::string info)
    {
        for (Colleague* pElem : v)
        {
            if (pElem != from)
                pElem->BeNotified(info);
        }
    }
    std::vector<Colleague*> v;
};

//Для танков
class Colleague1 : public Colleague {
public:
    Colleague1(Mediator* pMed) : pMediator(pMed){ }
    void BeNotified(std::string info) override
    {
        ScreenSingleton::getInstance().GotoXY(_x, _y - 5);
        if(info == "I kill you!")
        {
            std::cout << "Help me!" << std::endl;
        }
        else
            std::cout << info;
    }
    void SomeActions() override
    {
        pMediator->Notify(this, "Banzay!!!");
    }
    Mediator* pMediator;
};

//Для самолёта
class Colleague2 : public Colleague
{
public:
    Colleague2(Mediator* pMed) : pMediator(pMed){}
    void BeNotified(std::string info) override {}
    void SomeActions() override
    {
        ScreenSingleton::getInstance().GotoXY(_x, _y - 2);
        std::cout << "I kill you!";
        pMediator->Notify(this, "I kill you!");
    }
    Mediator* pMediator;
};
