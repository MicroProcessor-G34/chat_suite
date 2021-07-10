object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Chat Server V1.0'
  ClientHeight = 354
  ClientWidth = 624
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
    Left = 8
    Top = 311
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
  object Label2: TLabel
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
  object Label3: TLabel
    Left = 423
    Top = 144
    Width = 111
    Height = 16
    Caption = 'Clients Connected: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ClientsCountLabel: TLabel
    Left = 540
    Top = 144
    Width = 7
    Height = 16
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 423
    Top = 29
    Width = 65
    Height = 16
    Caption = 'Server Port'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ChatBox: TMemo
    Left = 60
    Top = 8
    Width = 305
    Height = 273
    ReadOnly = True
    TabOrder = 0
  end
  object MsgBox: TEdit
    Left = 64
    Top = 310
    Width = 305
    Height = 21
    TabOrder = 1
  end
  object SendBtn: TButton
    Left = 423
    Top = 313
    Width = 193
    Height = 33
    Caption = 'Send'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = SendBtnClick
  end
  object ServerPortEditBox: TEdit
    Left = 423
    Top = 51
    Width = 177
    Height = 21
    TabOrder = 3
    Text = '4000'
  end
  object StartBtn: TButton
    Left = 423
    Top = 94
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 4
    OnClick = StartBtnClick
  end
  object StopBtn: TButton
    Left = 525
    Top = 94
    Width = 75
    Height = 25
    Caption = 'Stop'
    TabOrder = 5
    OnClick = StopBtnClick
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 4000
    ServerType = stNonBlocking
    OnListen = ServerSocket1Listen
    OnClientDisconnect = OnClientDisconnect
    OnClientRead = OnClientRead
    Left = 424
    Top = 232
  end
end
