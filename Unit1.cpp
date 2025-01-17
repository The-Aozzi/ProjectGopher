//---------------------------------------------------------------------------

#include <vcl.h>
#include <IdGopher.hpp>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent *Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ConnectButtonClick(TObject *Sender)
{
    __try
    {
        // Configure the Gopher component
        IdGopher1->Host = Address->Text;           // Gopher server address
        IdGopher1->Port = 70 /*StrToInt(Edit2->Text)*/; // Port number

        // Fetch data from the Gopher server
        TStringList *Response = new TStringList();
        __try
        {
            TIdGopherMenu *GMenu = IdGopher1->GetMenu("", false, ""); // "" for root menu
            ClearListBoxObjects(Contents);
            for (int i = 0; i < GMenu->Count; ++i){
                Contents->Items->AddObject((*GMenu)[i]->Title,
                               (TObject*)new AnsiString((*GMenu)[i]->Selector));
                //(*GMenu)[i]->

            }


        }
        __finally
        {
            delete Response;
        }
    }
    catch (const Exception &E)
    {
        ShowMessage("Error: " + E.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearListBoxObjects(TListBox* List){
    for(int i = 0; i < List->Items->Count; ++i){
        if (List->Items->Objects[i] == NULL) continue;
        delete (AnsiString*)List->Items->Objects[i];
    }
    List->Items->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContentsClick(TObject *Sender)
{
    int Index = Contents->ItemIndex;
    if (Index == -1) return;
    AnsiString* Selector = (AnsiString*)Contents->Items->Objects[Index];
    if (Selector == NULL) return;
    if (*Selector == "")  return;
    TIdGopherMenu *GMenu = IdGopher1->GetMenu(*Selector, false, "");
                           //IdGopher1->GetMenu(
    PathLabel->Caption = "Path: gopher://" + IdGopher1->Host + *Selector;
    BackButton->Enabled = true;
    ClearListBoxObjects(Contents);
    for (int i = 0; i < GMenu->Count; ++i){
        Contents->Items->AddObject((*GMenu)[i]->Title,
                            (TObject*)new AnsiString((*GMenu)[i]->Selector));

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BackButtonClick(TObject *Sender)
{
    AnsiString Path = PathLabel->Caption;
    Path = Path.SubString(16 + IdGopher1->Host.Length(), Path.Length());
    while(Path[Path.Length()-1] != '/'){
        Path.SetLength(Path.Length()-1);
    }
    AnsiString Selector = Path.SubString(0, Path.Length()-2);
    if(Selector.IsEmpty()){
        PathLabel->Caption = "Path: gopher://" + IdGopher1->Host + "/";
        BackButton->Enabled = false;
    }
    else{
        PathLabel->Caption = "Path: gopher://" + IdGopher1->Host + Selector;
    }
    TIdGopherMenu *GMenu = IdGopher1->GetMenu(Selector, false, "");
    ClearListBoxObjects(Contents);
    for (int i = 0; i < GMenu->Count; ++i){
        Contents->Items->AddObject((*GMenu)[i]->Title,
                            (TObject*)new AnsiString((*GMenu)[i]->Selector));

    }
}
//---------------------------------------------------------------------------

