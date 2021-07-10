object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Chat Client V1.0'
  ClientHeight = 445
  ClientWidth = 649
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 416
    Top = 11
    Width = 87
    Height = 13
    Caption = 'Server IP Address'
  end
  object Label2: TLabel
    Left = 416
    Top = 69
    Width = 55
    Height = 13
    Caption = 'Server Port'
  end
  object Label3: TLabel
    Left = 416
    Top = 133
    Width = 45
    Height = 13
    Caption = 'Nickname'
  end
  object AIndicator: TShape
    Left = 432
    Top = 397
    Width = 41
    Height = 33
    Shape = stCircle
  end
  object BIndicator: TShape
    Left = 504
    Top = 397
    Width = 41
    Height = 33
    Shape = stCircle
  end
  object CIndicator: TShape
    Left = 584
    Top = 397
    Width = 41
    Height = 33
    Shape = stCircle
  end
  object Label5: TLabel
    Left = 8
    Top = 303
    Width = 50
    Height = 16
    Caption = 'Message'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 8
    Width = 46
    Height = 16
    Caption = 'ChatBox'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ChatBox: TMemo
    Left = 64
    Top = 8
    Width = 305
    Height = 273
    ReadOnly = True
    TabOrder = 0
  end
  object MsgBox: TEdit
    Left = 64
    Top = 302
    Width = 305
    Height = 21
    TabOrder = 1
  end
  object SendBtn: TButton
    Left = 416
    Top = 303
    Width = 193
    Height = 33
    Caption = 'Send'
    TabOrder = 2
    OnClick = SendBtnClick
  end
  object ServerAddressEditBox: TEdit
    Left = 416
    Top = 30
    Width = 177
    Height = 21
    TabOrder = 3
    Text = '127.0.0.1'
  end
  object ServerPortEditBox: TEdit
    Left = 416
    Top = 88
    Width = 177
    Height = 21
    TabOrder = 4
    Text = '4000'
  end
  object ConnectBtn: TButton
    Left = 416
    Top = 198
    Width = 75
    Height = 25
    Caption = 'Connect'
    TabOrder = 5
    OnClick = ConnectBtnClick
  end
  object nicknameEditBox: TEdit
    Left = 416
    Top = 152
    Width = 177
    Height = 21
    TabOrder = 6
  end
  object SendA: TButton
    Left = 416
    Top = 358
    Width = 71
    Height = 33
    Caption = 'A'
    TabOrder = 7
    OnClick = SendAClick
  end
  object SendB: TButton
    Left = 493
    Top = 358
    Width = 71
    Height = 33
    Caption = 'B'
    TabOrder = 8
    OnClick = SendBClick
  end
  object SendC: TButton
    Left = 570
    Top = 358
    Width = 71
    Height = 33
    Caption = 'C'
    TabOrder = 9
    OnClick = SendCClick
  end
  object DisconnectBtn: TButton
    Left = 518
    Top = 198
    Width = 75
    Height = 25
    Caption = 'Disconnect'
    TabOrder = 10
    OnClick = DisconnectBtnClick
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 4000
    OnConnect = OnClientConnect
    OnDisconnect = OnClientDisconnect
    OnRead = OnClientRead
    Left = 72
    Top = 342
  end
  object ATimer: TTimer
    OnTimer = ATimerTimer
    Left = 232
    Top = 398
  end
  object BTimer: TTimer
    OnTimer = BTimerTimer
    Left = 304
    Top = 398
  end
  object CTimer: TTimer
    OnTimer = CTimerTimer
    Left = 384
    Top = 398
  end
end
