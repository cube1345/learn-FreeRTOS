#ifndef __SHOWTIMETASK_H__
#define __SHOWTIMETASK_H__

#include "FreeRTOS.h"
#include "timers.h"

void ShowTimeTask(void *params);
void TimerCallBackFun(TimerHandle_t xTimer);

#endif
