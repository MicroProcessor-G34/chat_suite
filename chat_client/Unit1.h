// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.IOUtils.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>


// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TMemo *ChatBox;
	TEdit *MsgBox;
	TButton *SendBtn;
	TClientSocket *ClientSocket1;
	TEdit *ServerAddressEditBox;
	TLabel *Label1;
	TEdit *ServerPortEditBox;
	TLabel *Label2;
	TButton *ConnectBtn;
	TLabel *Label3;
	TEdit *nicknameEditBox;
	TButton *SendA;
	TButton *SendB;
	TButton *SendC;
	TTimer *ATimer;
	TTimer *BTimer;
	TTimer *CTimer;
	TShape *AIndicator;
	TShape *BIndicator;
	TShape *CIndicator;
	TLabel *Label5;
	TLabel *Label4;
	TButton *DisconnectBtn;



	void __fastcall OnClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall OnClientDisconnect(TObject *Sender,
		TCustomWinSocket *Socket);
	void __fastcall OnClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall SendBtnClick(TObject *Sender);
	void __fastcall ConnectBtnClick(TObject *Sender);
	void __fastcall SendAClick(TObject *Sender);
	void __fastcall ATimerTimer(TObject *Sender);
	void __fastcall BTimerTimer(TObject *Sender);
	void __fastcall CTimerTimer(TObject *Sender);
	void __fastcall SendBClick(TObject *Sender);
	void __fastcall SendCClick(TObject *Sender);
	void __fastcall DisconnectBtnClick(TObject *Sender);

private: // User declarations
	AnsiString ReceivedFileData;
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
