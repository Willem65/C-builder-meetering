#define MBN_VARARG

#include "mbn.h"
#include "MeeteringForm.h"
#include "Button1Click.h"


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
	thisnodeB.ProductID = 0x0024;
	thisnodeB.UniqueIDPerProduct = 0x516;   //UniqueIDPerProduct
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


	sprintf(obj_desc, "Meter %d Left dB", cnt+1);
	objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
	sprintf(obj_desc, "Meter %d Right dB", cnt+1);
	objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);

	sprintf(obj_desc, "Phase Meter %d", cnt+1);
	objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, 0.0, 0.0, 0.0, 0.0);

	sprintf(obj_desc, "dummy %d", cnt+1);
	objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, 0.0, 0.0, 0.0, 0.0);

	for (cnt=0; cnt<68; cnt++)
	{
		sprintf(obj_desc, "dummy %d", cnt+1);
		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, 0.0, 0.0, 0.0, 0.0);
	}


	// 1036 - 1047: Stereo Audio level metering
	for (cnt=0; cnt<32; cnt++)
	{
		sprintf(obj_desc, "Small meter %d left dB", cnt+1);
		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
		sprintf(obj_desc, "Small meter %d right dB", cnt+1);
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
	mbnSetSetActuatorDataCallback(mbn, mSetActuatorData);
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


