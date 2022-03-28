#include "commanddropbomb.h"

CommandDropBomb::CommandDropBomb(const Plane *plane,  std::vector<DynamicObject*> &vec, uint16_t &bombsNumber, int16_t &score, ProxyLogger &proxyLog)
    : _plane(plane), _vecDynamicObj(vec), _bombsNumber(bombsNumber), _score(score), _proxyLog(proxyLog)
{

}

void CommandDropBomb::Execute()
{
    if (_bombsNumber > 0)
    {
        _proxyLog.WriteToLog(std::string(__FUNCTION__) + " was invoked");

        double x = _plane->GetX() + 4;
        double y = _plane->GetY() + 2;

        Bomb* pBomb = new Bomb;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        _vecDynamicObj.push_back(pBomb);
        _bombsNumber--;
        _score -= Bomb::BombCost;
    }
}
