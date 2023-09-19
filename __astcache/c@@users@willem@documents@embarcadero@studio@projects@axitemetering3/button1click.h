#pragma once
#ifndef BUTTON1CLICK_H
#define BUTTON1CLICK_H


struct mbn_interface *itf;
struct mbn_handler *mbn;

//int AxiteAxumId;


//int mSensorDataChanged(struct mbn_handler *mbn, struct mbn_message *msg, unsigned short obj, unsigned char type, union mbn_data dat);
void mOnlineStatus(struct mbn_handler *mbn, unsigned long addr, char valid);
int mSetActuatorData(struct mbn_handler *mbn, unsigned short obj, union mbn_data dat);




#endif