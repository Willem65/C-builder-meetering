//---------------------------------------------------------------------------

#ifndef MeeteringFormH
#define MeeteringFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
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
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall RefreshTimerTimer(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
