//---------------------------------------------------------------------------


#define MBN_VARARG

#include <vcl.h>
#pragma hdrstop

#include "MeeteringForm.h"




#include "mbn.h"

static int online = 0;
float vuValueL, vuValueR;

struct mbn_interface *itf;
struct mbn_handler *mbn;


int mSensorDataChanged(struct mbn_handler *mbn, struct mbn_message *msg, unsigned short obj, unsigned char type, union mbn_data dat);
void mOnlineStatus(struct mbn_handler *mbn, unsigned long addr, char valid);
int mSetActuatorData(struct mbn_handler *mbn, unsigned short obj, union mbn_data dat);

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

int mSetActuatorData(struct mbn_handler *mbn, unsigned short obj, union mbn_data dat)
{
//	if ( obj > 1047 )                // Logger
//	{
//		if (checkBox1 == 1 )
//		{
//			char Temp[32];
//			sprintf(Temp, "#%04d_%04d", obj,  (int)dat.UInt);
//			WillemForm1->memLog2->Lines->Add(Temp);
//		}
//	}



	//------------------------------------- Vu Meters 1  Links
	if ( obj == 1036 )
	{

		int ValueL = (int)dat.Float;
		if ( ValueL > -50 )
		{

			vuValueL = 50+dat.Float;
			vuValueL = ((vuValueL)*10);

		}
		else
		{
			vuValueL = 0;
		}


	}
	else if ( obj == 1037 )
	{

		int ValueR = (int)dat.Float;             // Rechts
		if ( ValueR > -50 )
		{

			vuValueR = 50+dat.Float;
			vuValueR = ((vuValueR)*10);

		}
		else
		{
			vuValueR = 0;
		}
	}
	return 0;
}




 //  Callback functies
void mOnlineStatus(struct mbn_handler *mbn, unsigned long addr, char valid)
{
	if( valid )
		online = (int)valid;

}




void __fastcall TForm1::Button1Click(TObject *Sender)
{
	OnlineDetectTimer->Enabled = true;

//	for (int i = 0; i < Form1->ControlCount ; i++)
//	{
//		// disable the control by setting Enabled property to false
//		Form1->Controls[i]->Enabled = true;
//	}






	int cnt;
	int cntvu_busses;
	struct mbn_interface *itf;
	char error[MBN_ERRSIZE];

	char Temp[16];
	//char *url;
	//char *port_found;
	char url[256];
	char port[16];
	char obj_desc[32];
	struct mbn_node_info thisnodeB;
	int cntSwitch;
	struct mbn_object objects[370];
	//struct mbn_object objects[350];
	int cntObject = 0;



	String s = UDPEdit->Text;



	StrPCopy(Temp, s);


  // itf = mbnUDPOpen(Temp, strdup("34848"), 0, error);  // Maak verbinding met ethernet  // strdup( ) handige functie
   itf = mbnUDPOpen(strdup("192.168.1.76"), strdup("34848"), 0, error);

   //
//
//
//
	if( itf == 0 )
	{
		//memLog->Lines->Add( "EthernetOpen failed: %s" );
		ShowMessage("Welcome to the Sellers Bank.");
		return;
	}

	thisnodeB.MambaNetAddr = 0;
	thisnodeB.Services = 0;
	sprintf(thisnodeB.Description, "Axite Control Surface 6 Faders + CRM");
	sprintf(thisnodeB.Name, "Meetering Test Node");
	thisnodeB.ManufacturerID = 0x0001;
	thisnodeB.ProductID = 0x0022;
	thisnodeB.UniqueIDPerProduct = 0x511;   //UniqueIDPerProduct
	thisnodeB.HardwareMajorRevision = 0;
	thisnodeB.HardwareMinorRevision = 0;
	thisnodeB.FirmwareMajorRevision = 1;
	thisnodeB.FirmwareMinorRevision = 3;
	thisnodeB.FPGAFirmwareMajorRevision = 0;
	thisnodeB.FPGAFirmwareMinorRevision = 0;
	thisnodeB.NumberOfObjects = 0;
	thisnodeB.DefaultEngineAddr = 0;
	thisnodeB.HardwareParent[0] = 0;
	thisnodeB.HardwareParent[1] = 0;
	thisnodeB.HardwareParent[2] = 0;
	thisnodeB.ServiceRequest = 0;
	// 1024 - 1035: OLED Display lines
	for (cnt=0; cnt<6; cnt++)
	{
		sprintf(obj_desc, "Display %d Line 1", cnt+1);

		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_OCTETS, 8, 0, 127, 0, "");

		//objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_UINT, 0, 2 , 0, 512, 256, MBN_DATATYPE_NODATA);
	}
	for (cnt=0; cnt<6; cnt++)
	{
		sprintf(obj_desc, "Display %d Line 2", cnt+1);
		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_OCTETS, 8, 0, 127, 0, "");
	}

	// 1036 - 1047: Stereo Audio level metering
	for (cnt=0; cnt<6; cnt++)
	{
		sprintf(obj_desc, "Display Meter %d Left dB", cnt+1);
		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
		sprintf(obj_desc, "Display Meter %d Right dB", cnt+1);
		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
	}



	// // //------------------------------------------------------------------------------------------------
	thisnodeB.NumberOfObjects = cntObject;
	mbn = mbnInit(&thisnodeB, objects, itf, error);

//	if((mbn = mbnInit(&thisnodeB, objects, itf, error)) == 0)
//	{
//		return; // memLog(LF_APP, "Init failed: %s", error);
//	}

	// Callbacks
   //	mbnSetSensorDataChangedCallback(mbn, mSensorDataChanged);
	//mbnSetSetActuatorDataCallback(mbn, mSetActuatorData);
	mbnSetOnlineStatusCallback(mbn, mOnlineStatus);



	//mbnSetErrorCallback(mbn, mError);



	mbnStartInterface(itf, error);

	//lstInterfaces->Enabled = false;
	UDPEdit->Enabled = false;
	//TCPEdit->Enabled = false;
	//cseUniqueID->Enabled = false;
	//btnOpen->Enabled = false;
	//btnClose->Enabled = true;

	mbnSendPingRequest(mbn, MBN_BROADCAST_ADDRESS);


}
//---------------------------------------------------------------------------

