object Form1: TForm1
  Left = 350
  Top = 118
  Width = 916
  Height = 639
  Caption = 'Gopher Client'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    900
    600)
  PixelsPerInch = 96
  TextHeight = 14
  object FetchButton: TButton
    Left = 592
    Top = 156
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Fetch'
    Enabled = False
    TabOrder = 1
  end
  object ResponseList: TMemo
    Left = 597
    Top = 232
    Width = 172
    Height = 105
    HelpType = htKeyword
    Anchors = [akTop, akRight]
    Enabled = False
    TabOrder = 2
  end
  object ConnectGroup: TGroupBox
    Left = 5
    Top = 0
    Width = 891
    Height = 81
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Connection'
    TabOrder = 3
    object PathLabel: TLabel
      Left = 304
      Top = 24
      Width = 174
      Height = 14
      Caption = 'Path: gopher://gopher.floodgap.com/'
    end
    object AddressLabel: TLabel
      Left = 8
      Top = 24
      Width = 45
      Height = 14
      Caption = 'Address:'
    end
    object Address: TEdit
      Left = 56
      Top = 20
      Width = 241
      Height = 22
      TabOrder = 0
      Text = 'gopher.floodgap.com'
    end
    object ConnectButton: TButton
      Left = 126
      Top = 48
      Width = 75
      Height = 25
      Caption = 'Connect'
      TabOrder = 1
      OnClick = ConnectButtonClick
    end
    object BackButton: TButton
      Left = 384
      Top = 48
      Width = 75
      Height = 25
      Caption = 'Back'
      Enabled = False
      TabOrder = 2
      OnClick = BackButtonClick
    end
  end
  object Contents: TListBox
    Left = 5
    Top = 88
    Width = 890
    Height = 507
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 22
    ParentFont = False
    TabOrder = 0
    OnClick = ContentsClick
  end
  object IdGopher1: TIdGopher
    Left = 864
    Top = 8
  end
end
