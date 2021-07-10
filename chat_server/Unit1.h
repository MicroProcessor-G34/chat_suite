// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <map>
#include <numeric>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TMemo *ChatBox;
	TEdit *MsgBox;
	TButton *SendBtn;
	TServerSocket *ServerSocket1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *ClientsCountLabel;
	TLabel *Label4;
	TEdit *ServerPortEditBox;
	TButton *StartBtn;
	TButton *StopBtn;
	void __fastcall OnClientDisconnect(TObject *Sender,
		TCustomWinSocket *Socket);
	void __fastcall OnClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SendBtnClick(TObject *Sender);
	void __fastcall StartBtnClick(TObject *Sender);
	void __fastcall StopBtnClick(TObject *Sender);
	void __fastcall ServerSocket1Listen(TObject *Sender, TCustomWinSocket *Socket);





private: // User declarations
    std::map<TCustomWinSocket *,String> nicknames;
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
