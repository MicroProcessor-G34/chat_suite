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
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OnClientDisconnect(TObject *Sender,
	TCustomWinSocket *Socket)

{
	auto chatbox_msg = "Client \"" + nicknames[Socket] + "\" disconnected.";
	ChatBox->Lines->Add(chatbox_msg);
	for (size_t i = 0; i < ServerSocket1->Socket->ActiveConnections; i++) {
		// send formatted message to all clients
		ServerSocket1->Socket->Connections[i]->SendText(chatbox_msg);
	}

	nicknames.erase(Socket);
	ClientsCountLabel->Caption = StrToInt(nicknames.size());

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OnClientRead(TObject *Sender, TCustomWinSocket *Socket)
{
	AnsiString recText = Socket->ReceiveText();
	const AnsiString MSG = "msg:";
	const AnsiString NICK = "nick:";

	if (recText.SubString(0, MSG.Length()) == MSG) {

		AnsiString message = recText.SubString(MSG.Length() + 1,
			std::numeric_limits<int>::max());

		// ShowMessage(message);
		size_t client_id = 0;

		for (size_t i = 0; i < ServerSocket1->Socket->ActiveConnections; i++) {
			// find client id
			if (ServerSocket1->Socket->Connections[i] == Socket) {
				client_id = i;
			}
		}
		auto chatbox_msg = nicknames[Socket] + ": " + message;

		ChatBox->Lines->Add(chatbox_msg); // add it to server chatbox
		for (size_t i = 0; i < ServerSocket1->Socket->ActiveConnections; i++) {
			// send formatted message to all clients
			ServerSocket1->Socket->Connections[i]->SendText(chatbox_msg);
		}

	}
	else if (recText.SubString(0, NICK.Length()) == NICK) // nick
	{

		AnsiString nickname = recText.SubString(NICK.Length() + 1,
			std::numeric_limits<int>::max());

		nicknames[Socket] = nickname;
		ClientsCountLabel->Caption = StrToInt(nicknames.size());

		const auto client_id = ServerSocket1->Socket->ActiveConnections - 1;

		const auto chatbox_msg = "New client \"" + nickname +
			"\" has been connected.";

		ChatBox->Lines->Add(chatbox_msg);
		for (size_t i = 0; i < ServerSocket1->Socket->ActiveConnections; i++) {

			// send formatted message to all clients except new client
			if (ServerSocket1->Socket->Connections[i] != Socket)
				ServerSocket1->Socket->Connections[i]->SendText(chatbox_msg);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SendBtnClick(TObject *Sender) {
	if (ServerSocket1->Active == false) {
		throw Exception("Please start the server first.");
	}

	if (MsgBox->Text.Length() != 0) {
		auto chatbox_msg = ServerSocket1->Socket->LocalHost + "(Server) : " +
			MsgBox->Text;
		MsgBox->Clear();

		ChatBox->Lines->Add(chatbox_msg); // add it to server chatbox

		for (size_t i = 0; i < ServerSocket1->Socket->ActiveConnections; i++) {
			// send formatted message to all clients
			ServerSocket1->Socket->Connections[i]->SendText(chatbox_msg);
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::StartBtnClick(TObject *Sender) {
	if (ServerPortEditBox->Text.Length() == 0)
		throw Exception("Server Port can't be empty");
	ServerSocket1->Port = StrToInt(ServerPortEditBox->Text);
	ServerSocket1->Active = true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::StopBtnClick(TObject *Sender) {
	ServerSocket1->Active = false;
	nicknames.clear();
	ClientsCountLabel->Caption = StrToInt(nicknames.size());
    ChatBox->Lines->Add("Server Stopped."); // add it to server chatbox
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1Listen(TObject *Sender, TCustomWinSocket *Socket)

{
	ChatBox->Lines->Add("Server Started."); // add it to server chatbox
}
//---------------------------------------------------------------------------
