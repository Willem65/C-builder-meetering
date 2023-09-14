#ifndef ButtonOpenObjectsH
#define ButtonOpenObjectsH

#define MBN_VARARG



#include "AxiteMeetering.h"

 //----------Hieronder mijn toegevoegde include files----------------------------------

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "mbn.h"



int mSensorDataChanged(struct mbn_handler *mbn, struct mbn_message *msg, unsigned short obj, unsigned char type, union mbn_data dat);
void mOnlineStatus(struct mbn_handler *mbn, unsigned long addr, char valid);
int mSetActuatorData(struct mbn_handler *mbn, unsigned short obj, union mbn_data dat);

#endif
