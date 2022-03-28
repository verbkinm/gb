#include "commanddropbombdecorator.h"

CommandDropBombDecorator::CommandDropBombDecorator(const Plane *plane, std::vector<DynamicObject *> &vec, uint16_t &bombsNumber, int16_t &score, ProxyLogger &proxyLog)
    : CommandDropBomb(plane,  vec, bombsNumber, score, proxyLog)
{

}

void CommandDropBombDecorator::Execute()
{
    if (_bombsNumber > 0)
    {
        _proxyLog.WriteToLog(std::string(__FUNCTION__) + " was invoked");

        double x = _plane->GetX() + 4;
        double y = _plane->GetY() + 2;

        BombDecorator* pBomb = new BombDecorator;
        pBomb->bomb().SetDirection(0.3, 1);
        pBomb->bomb().SetSpeed(2);
        pBomb->bomb().SetPos(x, y);
        pBomb->bomb().SetWidth(SMALL_CRATER_SIZE);

        _vecDynamicObj.push_back(pBomb);
        _bombsNumber--;
        _score -= Bomb::BombCost;
    }
}
