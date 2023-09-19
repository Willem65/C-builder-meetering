#include "mSetActuatorData.h"
#include "MeeteringForm.h"
#include <stdio.h>


 int online=0;
 //float vuValueL=0, vuValueR=0;
 int VuMeterBuffer[64], ProgMeterBuffer[8];// SubMeterBuffer[2];

 //  Callback functies
void mOnlineStatus(struct mbn_handler *mbn, unsigned long addr, char valid)
{
	if( valid )
		online = (int)valid;

}





int mSetActuatorData(struct mbn_handler *mbn, unsigned short obj, union mbn_data dat)
{


//	//if ( obj > 1055 && obj < 1057)
//	if (obj == 1040)
//	{
//
//			//int val = (int)dat.UInt;
//
//
//			char Temp[6000];
//
//			//String test = IntToStr( val );
//
//			sprintf(Temp,"%s", dat.Octets);
//
//			Form1->memLog->Lines->Add(Temp);
//
//	}


//	if (obj == 1039)
//	{
//		int ValueP = (int)dat.Octets;
//
//		ProgMeterBuffer[obj-1031];
//
//	}


	//------------------------------------- 32 Kleine Stereo Vu Meters -------------------------------------
	int AantalVumeters, ProgVumeters, SubVumeters;
	float vuValueL, ValueProg, ValueSub;

	for ( AantalVumeters = 0; AantalVumeters < 64; AantalVumeters++) // 32 stereo vu meters
	{
		if ( obj == 1096+AantalVumeters )
		{
			int ValueL = (int)dat.Float;
			if ( ValueL > -50 )
			{
				vuValueL = 50+dat.Float;
				vuValueL = ((vuValueL)*10);
				VuMeterBuffer[AantalVumeters]=vuValueL;
			}
			else
			{
				vuValueL = 0;
				VuMeterBuffer[AantalVumeters]=0;
			}
		}
	}


	//-------------------------------------- Laatste 4 VU meters voor Prog Sub Dump en CRM -----------------
	if ( (obj == 1024) || (obj == 1025) )       // Prog Vu meter
	{
		int ValueP = (int)dat.Float;
		if ( ValueP > -50 )
		{
			ValueProg = 50+dat.Float;
			ValueProg = ((ValueProg)*10);
			ProgMeterBuffer[obj-1024]=ValueProg;
		}
		else
		{
			ValueProg = 0;
			ProgMeterBuffer[obj-1024]=0;
		}
	}
	else if ( (obj == 1029) || (obj == 1030) )    // Sub Vu meter
	{
		int ValueP = (int)dat.Float;
		if ( ValueP > -50 )
		{
			ValueProg = 50+dat.Float;
			ValueProg = ((ValueProg)*10);
			ProgMeterBuffer[obj-1027]=ValueProg;
		}
		else
		{
			ValueProg = 0;
			ProgMeterBuffer[obj-1027]=0;
		}
	}
	else if ( (obj == 1034) || (obj == 1035) )     // Dump Vu meter
	{
		int ValueP = (int)dat.Float;
		if ( ValueP > -50 )
		{
			ValueProg = 50+dat.Float;
			ValueProg = ((ValueProg)*10);
			ProgMeterBuffer[obj-1030]=ValueProg;
		}
		else
		{
			ValueProg = 0;
			ProgMeterBuffer[obj-1030]=0;
		}
	}
	else if ( (obj == 1037) || (obj == 1038) )      // CRM Vu meter
	{
		int ValueP = (int)dat.Float;
		if ( ValueP > -50 )
		{
			ValueProg = 50+dat.Float;
			ValueProg = ((ValueProg)*10);
			ProgMeterBuffer[obj-1031]=ValueProg;
		}
		else
		{
			ValueProg = 0;
			ProgMeterBuffer[obj-1031]=0;
		}
	}







//---------------------------------------------------------------------------
//----------------------------- GPO SIGNALES------------------------------------
//---------------------------------------------------------------------------




	else if (obj == 1041)
	{
		int t=dat.SInt;

		if( t == 1 )
		  Form1->LabelRedL1->Color = clRed;
		else
		  Form1->LabelRedL1->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------



	else if (obj == 1042)
	{
		int t=dat.SInt;

		if( t == 1 )
		  Form1->LabelRedL2->Color = clRed;
		else
		  Form1->LabelRedL2->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------



	else if (obj == 1043)
	{
		int t=dat.SInt;

		if( t == 1 )
		  Form1->LabelRedL3->Color = clRed;
		else
		  Form1->LabelRedL3->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------



	else if (obj == 1044)
	{
		int t=dat.SInt;

		if( t == 1 )
		  Form1->LabelRedL4->Color = clRed;
		else
		  Form1->LabelRedL4->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------


	else if (obj == 1045)
	{
		int t=dat.SInt;

		if( t == 1 )
		  Form1->LabelRedL5->Color = clRed;
		else
		  Form1->LabelRedL5->Color = clInactiveCaption;
	}


//---------------------------------------------------------------------------


	else if (obj == 1046)
	{
		int t=dat.SInt;

		if( t == 1 )
		  Form1->LabelRedL6->Color = clRed;
		else
		  Form1->LabelRedL6->Color = clInactiveCaption;
	}

//---------------------------------------------------------------------------


	else if (obj == 1047)
	{
		int t=dat.SInt;

		if( t == 1 )
		  Form1->LabelRedL7->Color = clRed;
		else
		  Form1->LabelRedL7->Color = clInactiveCaption;
	}
//----------------1058-------1237----------------------------------------------------


	else if (obj == 1048)
	{
		int t=dat.SInt;

		if( t == 1 )
		  Form1->LabelRedL8->Color = clRed;
		else
		  Form1->LabelRedL8->Color = clInactiveCaption;
	}

//---------------------------------------------------------------------------




	return 0;
}
