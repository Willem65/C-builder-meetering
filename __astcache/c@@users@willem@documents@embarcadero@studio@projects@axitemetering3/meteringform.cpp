#define MBN_VARARG



#include <vcl.h>
#pragma hdrstop

#include "MeteringForm.h"
#include "mSetActuatorData.h"
#include "mbn.h"
#include <iostream>
#include <fstream>
//#include <ctime>
//#include <chrono>
//#include <stdio.h>
#include <string>



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


int AxiteAxumId;




//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

   	// iterate through all controls on Form1  TWillemForm1->ControlCount, Disable all Controls
	for (int i = 0; i < Form1->ControlCount ; i++)
	{
		// disable the control by setting Enabled property to false
		Form1->Controls[i]->Enabled = false;
	}

	Button1->Enabled = true;
	Button2->Enabled = true;
	UDPEdit->Enabled = true;
//	CheckBox1->Enabled = true;
//	CheckBox2->Enabled = true;
//	CheckBox2->Checked = True;

	//----------------------------------------------------- Read from file
	std::string fileContent;
	std::ifstream file;
	//std::ifstream inputFile;
	std::string ipString;
	std::string AxiteAxum;
	std::string	faders;

	char Temp[16];

   file.open("ipsetting.txt");

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			if (line.find("ip address  = ") != std::string::npos)
			{
				ipString = line.c_str();
			}
			if (line.find("Axum=1 Axite=2 = ") != std::string::npos)
			{
				AxiteAxum = line.c_str();
			}
		}
	}
	else
	{
		ShowMessage("Wrong IP address, or axum server is not running");
	}


	String s = ipString.c_str();
	int text = s.Length();
	StrPCopy(Temp, s.SubString1( 15 , text-2 ));
	UDPEdit->Text = Temp;
	memLog->Text = online;

	String s2 = AxiteAxum.c_str();
	int text2 = s2.Length();
	StrPCopy(Temp, s2.SubString1( 18 , text2-1 ));
	memLog->Lines->Add(Temp);
	AxiteAxumId = StrToInt(Temp);


 	char err[MBN_ERRSIZE], ifdesc[512];
	struct mbn_if_ethernet *n;
}
//---------------------------------------------------------------------------


void LoopThroughProgressBars(int oldtst);


int oldOnline, started;
//static int oldtst, oldtstR, oldtst2, oldtstR2, newtst;
float vuValueLL, vuValueRR, vuValueProg, vuValueSub;
int oldVuMeterBuffer[64], oldProgMeterBuffer[8];


void __fastcall TForm1::RefreshTimerTimer(TObject *Sender)
{
	if ( online != oldOnline)
	{
		// iterate through all controls on Form1  TWillemForm1->ControlCount, Disable all Controls
		for (int i = 0; i < Form1->ControlCount ; i++)
		{
			// disable the control by setting Enabled property to false
			Form1->Controls[i]->Enabled = true;
		}

		memLog->Lines->Add(online);
		started=1;
		TimerStartDelay->Enabled = true;
		Timer4->Enabled = true;
	}

	online = oldOnline;

	if ( started )
	{

	//memLog->Lines->Add(ProgMeterBuffer[3]);


		for (int i = 0; i < 64; i++)     //Loop through each progress bar and set its value
		{
			String progressBarName = "ProgressBar" + IntToStr(i + 1);                                      // Unique name of each progress bar component
			TProgressBar* progressBar = static_cast<TProgressBar*>(FindComponent(progressBarName));        // Find the progress bar by its name

			if (progressBar)
			{
				vuValueLL = VuMeterBuffer[i];
				progressBar->Position = oldVuMeterBuffer[i];
				//progressBar->Position = VuMeterBuffer[i];
			}

			if (oldVuMeterBuffer[i] > 0)         oldVuMeterBuffer[i] = oldVuMeterBuffer[i] - 3;
			if (oldVuMeterBuffer[i] < 0)         oldVuMeterBuffer[i] = vuValueLL;
			if (oldVuMeterBuffer[i] < vuValueLL)  oldVuMeterBuffer[i] = vuValueLL;
		}


		for ( int i = 0; i < 8; i++)     //Loop through the progress bar and set its value
		{
			String j = IntToStr(i + 65);                                      // Unique name of each progress bar component
			String progressBarName = "ProgressBar" + j;

			TProgressBar* progressBar = static_cast<TProgressBar*>(FindComponent(progressBarName));        // Find the progress bar by its name

			if (progressBar)
			{
				vuValueProg = ProgMeterBuffer[i];
				//progressBar->Position = ProgMeterBuffer[i];
				progressBar->Position = oldProgMeterBuffer[i];
			}

			if (oldProgMeterBuffer[i] > 0)         oldProgMeterBuffer[i] = oldProgMeterBuffer[i] - 3;
			if (oldProgMeterBuffer[i] < 0)         oldProgMeterBuffer[i] = vuValueProg;
			if (oldProgMeterBuffer[i] < vuValueProg)  oldProgMeterBuffer[i] = vuValueProg;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 	// Execute the Notepad application
	system("notepad.exe ipsetting.txt");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Timer4Timer(TObject *Sender)
{

 		TDateTime Today, Date2, TheTime, Time2;
		unsigned short Year, Year2, Month, Month2, Day, Day2;
		unsigned short Hour, Hour2, Min, Min2, Sec, Sec2, MSec, MSec2;
		int NbrOfDays;
		double DiffSecs;

		Today = Date();
		TheTime = Time();

		Label2->Caption = ("Today: " + FormatDateTime("yyyy/mm/dd", Today));

        TDateTime currentTime = Now();
	   Label1->Caption = currentTime.TimeString();
	   Label1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OnlineDetectTimerTimer(TObject *Sender)
{
		if ( started == 0 )
		{
			ShowMessage("Wrong IP address, or axum server is not running");
			OnlineDetectTimer->Enabled = false;
		}
		OnlineDetectTimer->Enabled = false;
}
//---------------------------------------------------------------------------

//void __fastcall TForm1::CheckBox1Click(TObject *Sender)
//{
//	if ( CheckBox1->Checked == True )
//	{
//		checkBox1=1;
//		CheckBox2->Checked = False;
//	}
//	else
//	{
//	  checkBox1=0;
//	}
//}
////---------------------------------------------------------------------------
//
//void __fastcall TForm1::CheckBox2Click(TObject *Sender)
//{
//	if ( CheckBox2->Checked == True )
//	{
//		checkBox2=2;
//		CheckBox1->Checked = False;
//	}
//	else
//	{
//	  checkBox2=0;
//	}
//
//}

//---------------------------------------------------------------------------

