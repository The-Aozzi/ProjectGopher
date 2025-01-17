//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdGopher.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TIdGopher *IdGopher1;
        TEdit *Address;
        TListBox *Contents;
        TButton *ConnectButton;
        TButton *FetchButton;
        TMemo *ResponseList;
        TGroupBox *ConnectGroup;
        TLabel *PathLabel;
        TLabel *AddressLabel;
        TButton *BackButton;
        void __fastcall ConnectButtonClick(TObject *Sender);
        void __fastcall ClearListBoxObjects(TListBox* List);
        void __fastcall ContentsClick(TObject *Sender);
        void __fastcall BackButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
