﻿//---------------------------------------------------------------------------

#ifndef MeteringFormH
#define MeteringFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>

 extern int AxiteAxumId;

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TTimer *OnlineDetectTimer;
	TEdit *UDPEdit;
	TProgressBar *ProgressBar1;
	TTimer *TimerStartDelay;
	TMemo *memLog;
	TTimer *RefreshTimer;
	TProgressBar *ProgressBar2;
	TProgressBar *ProgressBar3;
	TProgressBar *ProgressBar4;
	TProgressBar *ProgressBar5;
	TProgressBar *ProgressBar6;
	TProgressBar *ProgressBar7;
	TProgressBar *ProgressBar8;
	TProgressBar *ProgressBar9;
	TProgressBar *ProgressBar10;
	TProgressBar *ProgressBar11;
	TProgressBar *ProgressBar12;
	TProgressBar *ProgressBar13;
	TProgressBar *ProgressBar14;
	TProgressBar *ProgressBar15;
	TProgressBar *ProgressBar16;
	TProgressBar *ProgressBar17;
	TProgressBar *ProgressBar18;
	TProgressBar *ProgressBar19;
	TProgressBar *ProgressBar20;
	TProgressBar *ProgressBar21;
	TProgressBar *ProgressBar22;
	TProgressBar *ProgressBar23;
	TProgressBar *ProgressBar24;
	TProgressBar *ProgressBar25;
	TProgressBar *ProgressBar26;
	TProgressBar *ProgressBar27;
	TProgressBar *ProgressBar28;
	TProgressBar *ProgressBar29;
	TProgressBar *ProgressBar30;
	TProgressBar *ProgressBar31;
	TProgressBar *ProgressBar32;
	TProgressBar *ProgressBar33;
	TProgressBar *ProgressBar34;
	TProgressBar *ProgressBar35;
	TProgressBar *ProgressBar36;
	TProgressBar *ProgressBar37;
	TProgressBar *ProgressBar38;
	TProgressBar *ProgressBar39;
	TProgressBar *ProgressBar40;
	TProgressBar *ProgressBar41;
	TProgressBar *ProgressBar42;
	TProgressBar *ProgressBar43;
	TProgressBar *ProgressBar44;
	TProgressBar *ProgressBar45;
	TProgressBar *ProgressBar46;
	TProgressBar *ProgressBar47;
	TProgressBar *ProgressBar48;
	TProgressBar *ProgressBar49;
	TProgressBar *ProgressBar50;
	TProgressBar *ProgressBar51;
	TProgressBar *ProgressBar52;
	TProgressBar *ProgressBar53;
	TProgressBar *ProgressBar54;
	TProgressBar *ProgressBar55;
	TProgressBar *ProgressBar56;
	TProgressBar *ProgressBar57;
	TProgressBar *ProgressBar58;
	TProgressBar *ProgressBar59;
	TProgressBar *ProgressBar60;
	TProgressBar *ProgressBar61;
	TProgressBar *ProgressBar62;
	TProgressBar *ProgressBar63;
	TProgressBar *ProgressBar64;
	TProgressBar *ProgressBar65;
	TProgressBar *ProgressBar66;
	TProgressBar *ProgressBar67;
	TProgressBar *ProgressBar68;
	TLabel *Label1;
	TProgressBar *ProgressBar69;
	TProgressBar *ProgressBar70;
	TProgressBar *ProgressBar71;
	TProgressBar *ProgressBar72;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *LabelRedL1;
	TLabel *Label15;
	TLabel *Label19;
	TLabel *Label23;
	TLabel *Label27;
	TLabel *Label31;
	TLabel *Label35;
	TLabel *Label39;
	TLabel *Label43;
	TLabel *Label44;
	TLabel *Label45;
	TLabel *Label46;
	TLabel *Label48;
	TLabel *Label50;
	TLabel *Label52;
	TLabel *Label53;
	TLabel *Label54;
	TLabel *Label55;
	TLabel *Label56;
	TLabel *Label57;
	TLabel *Label58;
	TLabel *Label59;
	TLabel *Label60;
	TLabel *Label61;
	TLabel *Label62;
	TLabel *Label63;
	TLabel *Label64;
	TLabel *Label65;
	TLabel *Label66;
	TLabel *Label67;
	TLabel *Label68;
	TLabel *Label69;
	TLabel *Label70;
	TLabel *Label71;
	TLabel *Label72;
	TLabel *Label73;
	TLabel *Label74;
	TLabel *Label75;
	TLabel *Label76;
	TLabel *Label77;
	TLabel *Label78;
	TLabel *Label79;
	TLabel *Label107;
	TLabel *Label108;
	TLabel *Label109;
	TLabel *Label110;
	TLabel *Label111;
	TLabel *Label114;
	TLabel *Label115;
	TLabel *Label116;
	TLabel *Label117;
	TLabel *Label118;
	TButton *Button2;
	TTimer *Timer4;
	TLabel *LabelRedL2;
	TLabel *LabelRedL4;
	TLabel *LabelRedL3;
	TLabel *LabelRedL8;
	TLabel *LabelRedL7;
	TLabel *LabelRedL6;
	TLabel *LabelRedL5;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *Label38;
	TLabel *Label40;
	TLabel *Label41;
	TLabel *Label42;
	TLabel *Label47;
	TLabel *Label49;
	TLabel *Label51;
	TLabel *Label80;
	TLabel *Label81;
	TLabel *Label82;
	TLabel *Label83;
	TLabel *Label84;
	TLabel *Label85;
	TLabel *Label86;
	TLabel *Label87;
	TLabel *Label88;
	TLabel *Label89;
	TLabel *Label90;
	TLabel *Label91;
	TLabel *Label92;
	TLabel *Label93;
	TLabel *Label94;
	TLabel *Label95;
	TLabel *Label96;
	TLabel *Label97;
	TLabel *Label98;
	TLabel *Label99;
	TLabel *Label100;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall RefreshTimerTimer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall OnlineDetectTimerTimer(TObject *Sender);
//	void __fastcall CheckBox1Click(TObject *Sender);
//	void __fastcall CheckBox2Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

 //extern int checkBox1;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
