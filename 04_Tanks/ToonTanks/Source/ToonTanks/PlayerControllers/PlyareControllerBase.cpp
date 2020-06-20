


#include "PlyareControllerBase.h"

void APlyareControllerBase::SetPlayerEnabledState(bool SetPlayerEnabled)
{
    if (SetPlayerEnabled)
    {
        GetPawn()->EnableInput(this);
        APlyareControllerBase::bShowMouseCursor = true;
        
    }
    else
    {
        GetPawn()->DisableInput(this);
        APlyareControllerBase::bShowMouseCursor = false;

    }
}
