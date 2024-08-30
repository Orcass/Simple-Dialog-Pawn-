#include "dialog_manager.inc"

bool:OnTestDialogResponse(playerid, response, listitem, const inputtext[])
{
    if(response)
    {
        SendClientMessage(playerid, COLOR_GREEN, "You clicked OK!");
    }
    else
    {
        SendClientMessage(playerid, COLOR_RED, "You clicked Cancel!");
    }
    return true;
}

bool:OnDefaultDialogResponse(playerid, response, listitem, const inputtext[])
{
    SendClientMessage(playerid, COLOR_YELLOW, "No dialog handler found for this dialog.");
    return true;
}

bool:PreValidation(playerid, response, listitem, const inputtext[])
{
    if(IsPlayerInAnyVehicle(playerid))
    {
        SendClientMessage(playerid, COLOR_RED, "You cannot interact with dialogs while in a vehicle.");
        return false; 
    }
    return true;
}

public OnGameModeInit()
{
    RegisterDialogCallback(1234, OnTestDialogResponse);
    RegisterDefaultDialogCallback(OnDefaultDialogResponse);
    RegisterGlobalPreValidationFunction(PreValidation);
    return 1;
}
