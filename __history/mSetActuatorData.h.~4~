
#ifndef MSETACTUATORDATA_H
#define MSETACTUATORDATA_H

//#include "MeeteringForm.h"
#include "mbn.h"


extern int online;

extern int VuMeterBuffer[64], ProgMeterBuffer[8], SubMeterBuffer[2];

//int mSensorDataChanged(struct mbn_handler *mbn, struct mbn_message *msg, unsigned short obj, unsigned char type, union mbn_data dat);
void mOnlineStatus(struct mbn_handler *mbn, unsigned long addr, char valid);
int mSetActuatorData(struct mbn_handler *mbn, unsigned short obj, union mbn_data dat);


#endif
