#define MBN_VARARG

#include <vcl.h>
#pragma hdrstop

//#include <Windows.h>
//#include <vcclr.h>

#include "MeeteringForm.h"
#include "mSetActuatorData.h"
#include "mbn.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 	char err[MBN_ERRSIZE], ifdesc[512];
	struct mbn_if_ethernet *n;
}
//---------------------------------------------------------------------------


void LoopThroughProgressBars(int oldtst);


int oldOnline, started;
static int oldtst, oldtstR, oldtst2, oldtstR2, newtst;


void __fastcall TForm1::RefreshTimerTimer(TObject *Sender)
{
		if ( online != oldOnline)
		{
			memLog->Lines->Add(online);
			started=1;
			//WillemForm1->Label7->Click();
			TimerStartDelay->Enabled = true;
		}

		online = oldOnline;

		if ( started )
		{


			if (oldtst > 0)         oldtst = oldtst - 3;
			if (oldtst < 0)         oldtst = vuValueL;
			if (oldtst < vuValueL)  oldtst = vuValueL;


		   if (oldtstR > 0)         oldtstR = oldtstR - 3;
		   if (oldtstR < 0)         oldtstR = vuValueR;
		   if (oldtstR < vuValueR)  oldtstR = vuValueR;



		   ProgressBar1->Position = oldtst;
		   ProgressBar2->Position = oldtstR;





		   // Loop through each progress bar and set its value
			for (int i = 0; i < 64; i++)
			{
				String progressBarName = "ProgressBar" + IntToStr(i + 1);                                      // Unique name of each progress bar component
				TProgressBar* progressBar = static_cast<TProgressBar*>(FindComponent(progressBarName));        // Find the progress bar by its name


				if (progressBar)
				{
					progressBar->Position = oldtst;
				}
			}


		}
		double tst=1;
}
//---------------------------------------------------------------------------

