#include "bombdecorator.h"

BombDecorator::BombDecorator()
{

}

//void BombDecorator::Move(uint16_t time)
//{
//    _bomb.Move(time * 1.6);
////    x += xDirction * speed * time * 0.001;
////    y += yDirection * speed * time * 0.001;
//}

void BombDecorator::Draw() const
{
//    _bomb.Draw();
    // Некоторое изменение внешнего вида бомбы
    MyTools::GotoXY(/*_bomb.*/GetX(), /*_bomb.*/GetY() - 1);
    std::cout << "|";
}

//void BombDecorator::SetPos(double nx, double ny)
//{
//    _bomb.SetPos(nx, ny);
//}

//double BombDecorator::GetY() const
//{
//    return _bomb.y;
//}

//double BombDecorator::GetX() const
//{
//    return _bomb.x;
//}

//void BombDecorator::SetWidth(uint16_t widthN)
//{
//    _bomb.SetWidth(widthN);
//}

//uint16_t BombDecorator::GetWidth() const
//{
//    return _bomb.GetWidth();
//}
