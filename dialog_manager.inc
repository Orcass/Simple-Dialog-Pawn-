#ifndef _DIALOG_MANAGER_ADVANCED_INC_
#define _DIALOG_MANAGER_ADVANCED_INC_

#include <a_samp>

#define MAX_DIALOGS 1000
#define NO_DIALOG -1

new DialogCallbacks[MAX_DIALOGS];
new DialogQueue[MAX_PLAYERS]; 

typedef bool:DialogResponseFunction(playerid, response, listitem, const inputtext[]);

DialogResponseFunction:DefaultDialogCallback;

DialogResponseFunction:GlobalPreValidationFunction;

stock RegisterDialogCallback(dialogid, DialogResponseFunction:callback)
{
    if(dialogid >= 0 && dialogid < MAX_DIALOGS)
    {
        DialogCallbacks[dialogid] = _:callback;
    }
}

stock RegisterDefaultDialogCallback(DialogResponseFunction:callback)
{
    DefaultDialogCallback = _:callback;
}

stock RegisterGlobalPreValidationFunction(DialogResponseFunction:callback)
{
    GlobalPreValidationFunction = _:callback;
}

stock QueueDialog(playerid, dialogid)
{
    DialogQueue[playerid] = dialogid;
}

public OnPlayerDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(GlobalPreValidationFunction != 0)
    {
        if(!GlobalPreValidationFunction(playerid, response, listitem, inputtext))
        {
            return 0; 
        }
    }

    if(dialogid >= 0 && dialogid < MAX_DIALOGS && DialogCallbacks[dialogid] != 0)
    {
        return DialogCallbacks[dialogid](playerid, response, listitem, inputtext);
    }
    
    if(DefaultDialogCallback != 0)
    {
        return DefaultDialogCallback(playerid, response, listitem, inputtext);
    }
    
    return 0;
}

public OnGameModeInit()
{
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        DialogQueue[i] = NO_DIALOG;
    }
    return 1;
}

#endif
