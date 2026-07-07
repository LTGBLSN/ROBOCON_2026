//
// Created by 21481 on 2026/7/7.
//


#include "cmsis_os.h"
#include "DJI_motors.h"
#include "main.h"
#include "uart_printf.h"
#include "ABSC_GET_TASK.h"

#include "GET_RC_TASK.h"


void ABSC_GET_TASK()
{
    osDelay(ABSC_INIT_MS);
    init_absc();


    while (1)
    {

        MOTOR_11_get_absc();
        MOTOR_12_get_absc();
        MOTOR_13_get_absc();
        MOTOR_14_get_absc();
        MOTOR_21_get_absc();
        MOTOR_22_get_absc();
        MOTOR_23_get_absc();
        MOTOR_24_get_absc();
        if (rcData.rc.s[0] == 2)
        {
            init_absc();
        }
        osDelay(1);
    }
}

void init_absc()
{

    MOTOR_11_INIT_ANGLE = motor_can1_data[0].ecd;
    MOTOR_11_LAST_ECD = motor_can1_data[0].ecd;
    MOTOR_11_LAPS = 0.0f ;

    MOTOR_12_INIT_ANGLE = motor_can1_data[1].ecd;
    MOTOR_12_LAST_ECD = motor_can1_data[1].ecd;
    MOTOR_12_LAPS = 0.0f ;

    MOTOR_13_INIT_ANGLE = motor_can1_data[2].ecd;
    MOTOR_13_LAST_ECD = motor_can1_data[2].ecd;
    MOTOR_13_LAPS = 0.0f ;

    MOTOR_14_INIT_ANGLE = motor_can1_data[3].ecd;
    MOTOR_14_LAST_ECD = motor_can1_data[3].ecd;
    MOTOR_14_LAPS = 0.0f ;

    MOTOR_21_INIT_ANGLE = motor_can2_data[0].ecd;
    MOTOR_21_LAST_ECD = motor_can2_data[0].ecd;
    MOTOR_21_LAPS = 0.0f ;

    MOTOR_22_INIT_ANGLE = motor_can2_data[1].ecd;
    MOTOR_22_LAST_ECD = motor_can2_data[1].ecd;
    MOTOR_22_LAPS = 0.0f ;

    MOTOR_23_INIT_ANGLE = motor_can2_data[2].ecd;
    MOTOR_23_LAST_ECD = motor_can2_data[2].ecd;
    MOTOR_23_LAPS = 0.0f ;

    MOTOR_24_INIT_ANGLE = motor_can2_data[3].ecd;
    MOTOR_24_LAST_ECD = motor_can2_data[3].ecd;
    MOTOR_24_LAPS = 0.0f ;
}


void MOTOR_11_get_absc()
{
    if (((float)motor_can1_data[0].ecd - MOTOR_11_LAST_ECD) > 4000)
    {
        MOTOR_11_LAPS -- ;
    }
    else if (((float)motor_can1_data[0].ecd - MOTOR_11_LAST_ECD) < -4000)
    {
        MOTOR_11_LAPS ++ ;
    }
    MOTOR_11_REAL_ABSC = MOTOR_11_LAPS * 8192.0f + (float)motor_can1_data[0].ecd - MOTOR_11_INIT_ANGLE;
    MOTOR_11_LAST_ECD = motor_can1_data[0].ecd;
}


void MOTOR_12_get_absc()
{
    if (((float)motor_can1_data[1].ecd - MOTOR_12_LAST_ECD) > 4000)
    {
        MOTOR_12_LAPS -- ;
    }
    else if (((float)motor_can1_data[1].ecd - MOTOR_12_LAST_ECD) < -4000)
    {
        MOTOR_12_LAPS ++ ;
    }
    MOTOR_12_REAL_ABSC = MOTOR_12_LAPS * 8192.0f + (float)motor_can1_data[1].ecd - MOTOR_12_INIT_ANGLE;
    MOTOR_12_LAST_ECD = motor_can1_data[1].ecd;
}

void MOTOR_13_get_absc()
{
    if (((float)motor_can1_data[2].ecd - MOTOR_13_LAST_ECD) > 4000)
    {
        MOTOR_13_LAPS -- ;
    }
    else if (((float)motor_can1_data[2].ecd - MOTOR_13_LAST_ECD) < -4000)
    {
        MOTOR_13_LAPS ++ ;
    }
    MOTOR_13_REAL_ABSC = MOTOR_13_LAPS * 8192.0f + (float)motor_can1_data[2].ecd - MOTOR_13_INIT_ANGLE;
    MOTOR_13_LAST_ECD = motor_can1_data[2].ecd;
}


void MOTOR_14_get_absc()
{
    if (((float)motor_can1_data[3].ecd - MOTOR_14_LAST_ECD) > 4000)
    {
        MOTOR_14_LAPS -- ;
    }
    else if (((float)motor_can1_data[3].ecd - MOTOR_14_LAST_ECD) < -4000)
    {
        MOTOR_14_LAPS ++ ;
    }
    MOTOR_14_REAL_ABSC = MOTOR_14_LAPS * 8192.0f + (float)motor_can1_data[3].ecd - MOTOR_14_INIT_ANGLE;
    MOTOR_14_LAST_ECD = motor_can1_data[3].ecd;
}

void MOTOR_21_get_absc()
{
    if (((float)motor_can2_data[0].ecd - MOTOR_21_LAST_ECD) > 4000)
    {
        MOTOR_21_LAPS -- ;
    }
    else if (((float)motor_can2_data[0].ecd - MOTOR_21_LAST_ECD) < -4000)
    {
        MOTOR_21_LAPS ++ ;
    }
    MOTOR_21_REAL_ABSC = MOTOR_21_LAPS * 8192.0f + (float)motor_can2_data[0].ecd - MOTOR_21_INIT_ANGLE;
    MOTOR_21_LAST_ECD = motor_can2_data[0].ecd;
}

void MOTOR_22_get_absc()
{
    if (((float)motor_can2_data[1].ecd - MOTOR_22_LAST_ECD) > 4000)
    {
        MOTOR_22_LAPS -- ;
    }
    else if (((float)motor_can2_data[1].ecd - MOTOR_22_LAST_ECD) < -4000)
    {
        MOTOR_22_LAPS ++ ;
    }
    MOTOR_22_REAL_ABSC = MOTOR_22_LAPS * 8192.0f + (float)motor_can2_data[1].ecd - MOTOR_22_INIT_ANGLE;
    MOTOR_22_LAST_ECD = motor_can2_data[1].ecd;
}

void MOTOR_23_get_absc()
{
    if (((float)motor_can2_data[2].ecd - MOTOR_23_LAST_ECD) > 4000)
    {
        MOTOR_23_LAPS -- ;
    }
    else if (((float)motor_can2_data[2].ecd - MOTOR_23_LAST_ECD) < -4000)
    {
        MOTOR_23_LAPS ++ ;
    }
    MOTOR_23_REAL_ABSC = MOTOR_23_LAPS * 8192.0f + (float)motor_can2_data[2].ecd - MOTOR_23_INIT_ANGLE;
    MOTOR_23_LAST_ECD = motor_can2_data[2].ecd;
}


void MOTOR_24_get_absc()
{
    if (((float)motor_can2_data[3].ecd - MOTOR_24_LAST_ECD) > 4000)
    {
        MOTOR_24_LAPS -- ;
    }
    else if (((float)motor_can2_data[3].ecd - MOTOR_24_LAST_ECD) < -4000)
    {
        MOTOR_24_LAPS ++ ;
    }
    MOTOR_24_REAL_ABSC = MOTOR_24_LAPS * 8192.0f + (float)motor_can2_data[3].ecd - MOTOR_24_INIT_ANGLE;
    MOTOR_24_LAST_ECD = motor_can2_data[3].ecd;
}