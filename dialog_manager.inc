#ifndef _SIMPLE_DIALOG_MANAGER_INC_
#define _SIMPLE_DIALOG_MANAGER_INC_

#include <a_samp>

#define MAX_DIALOGS 1000

// Jenis dialog
enum DialogType {
    DIALOG_NORMAL, 
    DIALOG_LIST,    
    DIALOG_INPUT    
};

new DialogSettings[MAX_DIALOGS][5]; // Tipe dialog, Judul Kustom, Teks Kustom, Tombol Kustom 1, Tombol Kustom 2

typedef bool:DialogResponseFunction(playerid, response, listitem, const inputtext[]);

new PreValidationCallback(playerid);

stock RegisterAdvancedDialog(dialogid, DialogType:dialogType, const customTitle[], const customText[], const customButton1[], const customButton2[], DialogResponseFunction:callback)
{
    if(dialogid >= 0 && dialogid < MAX_DIALOGS)
    {
        DialogSettings[dialogid][0] = dialogType;
        DialogSettings[dialogid][1] = customTitle;
        DialogSettings[dialogid][2] = customText;
        DialogSettings[dialogid][3] = customButton1;
        DialogSettings[dialogid][4] = customButton2;
        // Daftarkan callback untuk dialog ini
        return 1;
    }
    return 0;
}

stock RegisterPreValidationFunction(PreValidationFunction:callback)
{
    PreValidationCallback = callback;
}

public OnPlayerDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid >= 0 && dialogid < MAX_DIALOGS)
    {
        // Cek validasi global
        if(PreValidationCallback && !PreValidationCallback(playerid))
        {
            return 1; // Batalkan jika validasi global gagal
        }

        // Ambil pengaturan dialog
        new DialogType:dialogType = DialogSettings[dialogid][0];
        new const customTitle[] = DialogSettings[dialogid][1];
        new const customText[] = DialogSettings[dialogid][2];
        new const customButton1[] = DialogSettings[dialogid][3];
        new const customButton2[] = DialogSettings[dialogid][4];

        // Tangani respons berdasarkan jenis dialog
        // Panggil callback terkait (contoh)
        // ...
        return 1;
    }
    return 0;
}

#endif
