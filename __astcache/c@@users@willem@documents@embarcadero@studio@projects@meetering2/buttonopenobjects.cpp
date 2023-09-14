
#include "ButtonOpenObjects.h"



//void __fastcall TForm1::Button1Click(TObject *Sender)
//{
//
//	OnlineDetectTimer->Enabled = true;
//
//	for (int i = 0; i < WillemForm1->ControlCount ; i++)
//	{
//		// disable the control by setting Enabled property to false
//		WillemForm1->Controls[i]->Enabled = true;
//	}
//
//
//	int cnt;
//	int cntvu_busses;
//	struct mbn_interface *itf;
//	char error[MBN_ERRSIZE];
//
//	char Temp[16];
//	//char *url;
//	//char *port_found;
//	char url[256];
//	char port[16];
//	char obj_desc[32];
//	struct mbn_node_info thisnodeB;
//	int cntSwitch;
//	struct mbn_object objects[370];
//	//struct mbn_object objects[350];
//	int cntObject = 0;
//
//
//
//	String s = UDPEdit->Text;
//
//	//AnsiString s = UDPEdit->Text;
//
//	//UnicodeString s = UDPEdit->Text;
//
//	StrPCopy(Temp, s);
//
//
//
//	//AnsiString udpText = "192.168.1.76";
//
//	//UnicodeString udpText = UDPEdit->Text;
//
//	//int text = s.Length();
//
//	//StrPCopy(Temp, s.SubString1( 2 , text-1 ));
//
//
//
////	//------------------------------------------- write to file
////	std::ofstream outputFile;
////	outputFile.open("ip.txt");
////
////	if (outputFile.is_open())
////	{
////		outputFile << Temp << std::endl;
////		outputFile.close();
////	}
////	else
////		std::cout << "Unable to open the file." << std::endl;
////	//----------------------------------------------------------------
//
//
//   itf = mbnUDPOpen(Temp, strdup("34848"), 0, error);  // Maak verbinding met ethernet  // strdup( ) handige functie
//
//
//
//
//	if( itf == 0 )
//	{
//		memLog->Lines->Add( "EthernetOpen failed: %s" );
//		ShowMessage("Welcome to the Sellers Bank.");
//		return;
//	}
//
//
//
//	//thisnodeB.UniqueIDPerProduct = 8;
//
//
//	thisnodeB.MambaNetAddr = 0;
//	thisnodeB.Services = 0;
//	sprintf(thisnodeB.Description, "Axite Control Surface 6 Faders + CRM");
//	sprintf(thisnodeB.Name, "Test Node D&R");
//	thisnodeB.ManufacturerID = 0x0001;
//	thisnodeB.ProductID = 0x0022;
//	thisnodeB.UniqueIDPerProduct = 0x110;   //UniqueIDPerProduct
//	thisnodeB.HardwareMajorRevision = 0;
//	thisnodeB.HardwareMinorRevision = 0;
//	thisnodeB.FirmwareMajorRevision = 1;
//	thisnodeB.FirmwareMinorRevision = 3;
//	thisnodeB.FPGAFirmwareMajorRevision = 0;
//	thisnodeB.FPGAFirmwareMinorRevision = 0;
//	thisnodeB.NumberOfObjects = 0;
//	thisnodeB.DefaultEngineAddr = 0;
//	thisnodeB.HardwareParent[0] = 0;
//	thisnodeB.HardwareParent[1] = 0;
//	thisnodeB.HardwareParent[2] = 0;
//	thisnodeB.ServiceRequest = 0;
//	/* 1024 - 1035: OLED Display lines */
//	for (cnt=0; cnt<6; cnt++)
//	{
//		sprintf(obj_desc, "Display %d Line 1", cnt+1);
//
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_OCTETS, 8, 0, 127, 0, "");
//
//		//objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_UINT, 0, 2 , 0, 512, 256, MBN_DATATYPE_NODATA);
//	}
//	for (cnt=0; cnt<6; cnt++)
//	{
//		sprintf(obj_desc, "Display %d Line 2", cnt+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_OCTETS, 8, 0, 127, 0, "");
//	}
//
//	/* 1036 - 1047: Stereo Audio level metering */
//	for (cnt=0; cnt<6; cnt++)
//	{
//		sprintf(obj_desc, "Display Meter %d Left dB", cnt+1);
//		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//		sprintf(obj_desc, "Display Meter %d Right dB", cnt+1);
//		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
//	}
//
//	/* 1048 - 1053: Encoder rotation */
//	for (cnt=0; cnt<6; cnt++)
//	{
//		sprintf(obj_desc, "Encoder %d", cnt+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_SINT, 1, 1, -128, 127, 0, MBN_DATATYPE_NODATA);
//	}
//
//	/* 1054 - 1059: Encoder switch */
//	for (cnt=0; cnt<6; cnt++)
//	{
//		sprintf(obj_desc, "Encoder %d Switch", cnt+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_STATE, 1, 1, 0, 1, 0, MBN_DATATYPE_NODATA);
//	}
//
//
//
//	/* 1060 - 1083: Module switches (TB, INP B, CUE/PFL, START/STOP) */
//	for (cntSwitch=0; cntSwitch<4; cntSwitch++)
//	{
//		for (cnt=0; cnt<6; cnt++)
//		{
//			sprintf(obj_desc, "Switch %d.%d", cnt+1, cntSwitch+1);
//			objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_STATE, 1, 1, 0, 1, 0, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//		}
//	}
//
//	/* 1084 - 1089: Fader (also actuator[A] to store actual value set by other node) */
//	for (cnt=0; cnt<6; cnt++)
//	{
//		sprintf(obj_desc, "Fader %d", cnt+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_UINT, 1, 2, 0, 1023, 0, MBN_DATATYPE_UINT, 2, 0, 1023, 0, 0);
//	}
//
//	/* 1090 - 1113: Module switches ON color */
//	for (cntSwitch=0; cntSwitch<4; cntSwitch++)
//	{
//		for (cnt=0; cnt<6; cnt++)
//		{
//			sprintf(obj_desc, "Switch %d.%d on color", cnt+1, cntSwitch+1);
//			objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 3, 2, 2);
//		}
//	}
//
//	/* 1114 - 1137: Module switches OFF color */
//	for (cntSwitch=0; cntSwitch<4; cntSwitch++)
//	{ /*cntSwitch == switchID */
//		for (cnt=0; cnt<6; cnt++)  /* cnt == module */
//		{
//			sprintf(obj_desc, "Switch %d.%d off color", cnt+1, cntSwitch+1);
//			objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 3, 0, 0);
//		}
//	}
//
//	/* 1138 - 1143: PGM on/off */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++)
//	{
//		sprintf(obj_desc, "PGM %d on/off", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//	/* 1144 - 1149: SUB on/off */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
//		sprintf(obj_desc, "SUB %d on/off", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//
//	/* 1150 - 1155: EQ on/off */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
//		sprintf(obj_desc, "EQ %d on/off", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//
//	/* 1156 - 1161: DYN on/off */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
//		sprintf(obj_desc, "Dynamics %d on/off", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//
//	/* 1162 - 1167: AUX1 on/off */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
//		sprintf(obj_desc, "Aux1 %d on/off", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//
//	/* 1168 - 1173: AUX2 on/off */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
//		sprintf(obj_desc, "Aux2 %d on/off", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//
//	/* 1174 - 1179: AUX3 on/off */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
//		sprintf(obj_desc, "Aux3 %d on/off", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//
//	/* 1180 - 1185: AUX4 on/off */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
//		sprintf(obj_desc, "Aux4 %d on/off", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//
//	/* 1186 - 1191: Peak Indicator (ppm) */
//	for (cntSwitch=0; cntSwitch<6; cntSwitch++) {
//		sprintf(obj_desc, "Peak %d", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//
//	/* 1192 - 1240: CRM Switches */
//	for (cntSwitch=0; cntSwitch<49; cntSwitch++)
//	{
//		sprintf(obj_desc, "Switch %d", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_STATE, 1, 1, 0, 1, 0, MBN_DATATYPE_STATE, 1, 0, 1, 0, 0);
//	}
//	/* 1241 - 1289: CRM switches ON color */
//	for (cntSwitch=0; cntSwitch<49; cntSwitch++)
//	{
//		sprintf(obj_desc, "Switch %d on color", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 3, 2, 2);
//	}
//	/* 1290 - 1338: CRM switches OFF color */
//	for (cntSwitch=0; cntSwitch<49; cntSwitch++)
//	{
//		sprintf(obj_desc, "Switch %d off color", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_STATE, 1, 0, 3, 0, 0);
//	}
//	/* 1339 - 1342: Potmeters, also actuator to internally save current value set by other nodes (not in sync status) */
//	for (cntSwitch=0; cntSwitch<4; cntSwitch++)
//	{
//		sprintf(obj_desc, "Potential Meter %d", cntSwitch+1);
//		objects[cntObject++] = MBN_OBJ(obj_desc, MBN_DATATYPE_UINT, 1, 2, 0, 1023, 0, MBN_DATATYPE_UINT, 2, 0, 1023, 0, 0);
//	}
//
//	// -------------toegevoegde level meter voor mix en monitor bussen----------------
//
////	/* 1043 - 1063: Stereo Audio level metering for mix or monitor busses */
////	for (cntvu_busses=0; cntvu_busses<20; cntvu_busses++)
////	{
////		sprintf(obj_desc, "Mix or Mon Bus Meter %d Left dB", cntvu_busses+1);
////		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
////		sprintf(obj_desc, "Mix or Mon Bus Meter %d Right dB", cntvu_busses+1);
////		objects[cntObject++] = MBN_OBJ( obj_desc, MBN_DATATYPE_NODATA, MBN_DATATYPE_FLOAT, 2, -50.0, 5.0, -50.0, -50.0);
////	}
//
//
//
//	// // //------------------------------------------------------------------------------------------------
//	thisnodeB.NumberOfObjects = cntObject;
//
//
//	if((mbn = mbnInit(&thisnodeB, objects, itf, error)) == 0)
//	{
//		return; // memLog(LF_APP, "Init failed: %s", error);
//	}
//
//	// Callbacks
//	mbnSetSensorDataChangedCallback(mbn, mSensorDataChanged);
//	mbnSetSetActuatorDataCallback(mbn, mSetActuatorData);
//	mbnSetOnlineStatusCallback(mbn, mOnlineStatus);
//
//
//
//	//mbnSetErrorCallback(mbn, mError);
//
//
//
//	mbnStartInterface(itf, error);
//
//	lstInterfaces->Enabled = false;
//	UDPEdit->Enabled = false;
//	//TCPEdit->Enabled = false;
//	//cseUniqueID->Enabled = false;
//	btnOpen->Enabled = false;
//	//btnClose->Enabled = true;
//
//	mbnSendPingRequest(mbn, MBN_BROADCAST_ADDRESS);
//
//
//
//}

