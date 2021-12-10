#include "genericplayer.h"

GenericPlayer::GenericPlayer()
{

}

bool GenericPlayer::isBoosted() const
{
    return getValue() > 21;
}

void GenericPlayer::bust() const
{

}
