//
// Created by 21481 on 2026/1/30.
//


#include "ABSC_GET_TASK.h"
#include "cmsis_os.h"
#include "DJI_motors.h"
#include "remote_control.h"
#include "can_receive.h"
#include "dm_motor.h"
#include "GET_RC_TASK.h"

void CAN_SENT_TASK()
{
    osDelay(ABSC_INIT_MS);

    while (1)
    {
    if(rcData.rc.s[0] == 2 )
    {
        FDCAN_DJI_motors(0, 0, 0, 0, 0x200, CAN_CHANNEL_1);
        FDCAN_DJI_motors(0, 0, 0, 0, 0x200, CAN_CHANNEL_2);
    }
    else if (rcData.rc.s[0] == 3 | rcData.rc.s[0] == 1)
    {
        FDCAN_DJI_motors(
            MOTOR_11_GIVEN_CURRENT,
            MOTOR_12_GIVEN_CURRENT,
            MOTOR_13_GIVEN_CURRENT,
            MOTOR_14_GIVEN_CURRENT,
            0x200, CAN_CHANNEL_1);
        FDCAN_DJI_motors(
            MOTOR_21_GIVEN_CURRENT,
            MOTOR_22_GIVEN_CURRENT,
            MOTOR_23_GIVEN_CURRENT,
            MOTOR_24_GIVEN_CURRENT,
            0x200, CAN_CHANNEL_2);



    }



        osDelay(1);
    }
}



