//
// Created by 21481 on 2026/7/7.
//

#include "GET_TARGET_ABSC.h"

#include "cmsis_os.h"
#include "main.h"
#include "uart_printf.h"

void GET_TARGET_ABSC()
{
    while(1)
    {

        MOTOR_11_TARGET_ABSC = (float)(MOTOR_11_TARGET_OUTPUT_SHAFT - MOTOR_11_OUTPUT_SHAFT_ERROR) * (float)pp_2_shaft * MOTOR_11_TURN;
        MOTOR_12_TARGET_ABSC = (float)(MOTOR_12_TARGET_OUTPUT_SHAFT - MOTOR_12_OUTPUT_SHAFT_ERROR) * (float)pp_2_shaft * MOTOR_12_TURN;
        MOTOR_13_TARGET_ABSC = (float)(MOTOR_13_TARGET_OUTPUT_SHAFT - MOTOR_13_OUTPUT_SHAFT_ERROR) * (float)pp_2_shaft * MOTOR_13_TURN;
        MOTOR_14_TARGET_ABSC = (float)(MOTOR_14_TARGET_OUTPUT_SHAFT - MOTOR_14_OUTPUT_SHAFT_ERROR) * (float)pp_2_shaft * MOTOR_14_TURN;
        MOTOR_21_TARGET_ABSC = (float)(MOTOR_21_TARGET_OUTPUT_SHAFT - MOTOR_21_OUTPUT_SHAFT_ERROR) * (float)pp_2_shaft * MOTOR_21_TURN;
        MOTOR_22_TARGET_ABSC = (float)(MOTOR_22_TARGET_OUTPUT_SHAFT - MOTOR_22_OUTPUT_SHAFT_ERROR) * (float)pp_2_shaft * MOTOR_22_TURN;
        MOTOR_23_TARGET_ABSC = (float)(MOTOR_23_TARGET_OUTPUT_SHAFT - MOTOR_23_OUTPUT_SHAFT_ERROR) * (float)pp_2_shaft * MOTOR_23_TURN;
        MOTOR_24_TARGET_ABSC = (float)(MOTOR_24_TARGET_OUTPUT_SHAFT - MOTOR_24_OUTPUT_SHAFT_ERROR) * (float)pp_2_shaft * MOTOR_24_TURN;
        osDelay(1);
    }
}

