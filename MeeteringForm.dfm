object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 208
    Top = 45
    Width = 136
    Height = 44
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object UDPEdit: TEdit
    Left = 429
    Top = 125
    Width = 146
    Height = 63
    TabOrder = 1
    Text = '192.168.1.76'
  end
  object OnlineDetectTimer: TTimer
    Left = 306
    Top = 226
  end
end
