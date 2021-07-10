// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	//CurrentFile = nullptr;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OnClientConnect(TObject *Sender,
	TCustomWinSocket *Socket)

{
	ClientSocket1->Socket->SendText("nick:" + nicknameEditBox->Text);
	ChatBox->Lines->Add("Connected to server.");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OnClientDisconnect(TObject *Sender,
	TCustomWinSocket *Socket)

{
	ChatBox->Lines->Add("Disconnected from server.");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OnClientRead(TObject *Sender, TCustomWinSocket *Socket)
{

	String recText = Socket->ReceiveText();
	ChatBox->Lines->Add(recText);
	if (recText.SubString(0, nicknameEditBox->Text.Length())
		== nicknameEditBox->Text) {
		String msg = recText.SubString(nicknameEditBox->Text.Length() + 2,
			std::numeric_limits<int>::max());
		// ShowMessage(msg);

		auto startIndicator = [this](TTimer * timer, TShape * indicator) {
			timer->Interval = 500;
			timer->Enabled = true;
			indicator->Brush->Color = clRed;
		};
		if (msg == " A") {
			startIndicator(ATimer, AIndicator);
		}
		else if (msg == " B") {
			startIndicator(BTimer, BIndicator);
		}
		else if (msg == " C") {
			startIndicator(CTimer, CIndicator);
		}
	}

	// server sends formatted messages
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SendBtnClick(TObject *Sender) {
	if(ClientSocket1->Active == false)
	{
		throw Exception("Please connect to server first.");
	}
	if (MsgBox->Text.Length() != 0) {
		ClientSocket1->Socket->SendText("msg:" + MsgBox->Text);
		MsgBox->Clear();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ConnectBtnClick(TObject *Sender) {

	if(nicknameEditBox->Text.Length() == 0)
		throw Exception("Nickname can't be empty");
	if(ServerAddressEditBox->Text.Length() == 0)
		throw Exception("Server Address can't be empty");
	if(ServerPortEditBox->Text.Length() == 0)
		throw Exception("Server Port can't be empty");
	ClientSocket1->Address = ServerAddressEditBox->Text;
	ClientSocket1->Port = StrToInt(ServerPortEditBox->Text);
	ClientSocket1->Active = true;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::SendAClick(TObject *Sender) {
	if(ClientSocket1->Active == false)
	{
		throw Exception("Please connect to server first.");
	}
	ClientSocket1->Socket->SendText("msg:A");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::ATimerTimer(TObject *Sender) {
	AIndicator->Brush->Color = clWhite;
	ATimer->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::BTimerTimer(TObject *Sender) {
	BIndicator->Brush->Color = clWhite;
	BTimer->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CTimerTimer(TObject *Sender) {
	CIndicator->Brush->Color = clWhite;
	CTimer->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SendBClick(TObject *Sender) {
	if(ClientSocket1->Active == false)
	{
		throw Exception("Please connect to server first.");
	}
	ClientSocket1->Socket->SendText("msg:B");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SendCClick(TObject *Sender) {
	if(ClientSocket1->Active == false)
	{
		throw Exception("Please connect to server first.");
	}
	ClientSocket1->Socket->SendText("msg:C");

}
void __fastcall TForm1::DisconnectBtnClick(TObject *Sender)
{
	ClientSocket1->Active = false;
}
//---------------------------------------------------------------------------

