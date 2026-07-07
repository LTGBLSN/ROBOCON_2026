//
// Created by 21481 on 2026/1/29.
//

#include "main.h"
#include "uart_printf.h"
#include "cmsis_os.h"
#include "remote_control.h"
#include "IMU_DATA_GET.h"
#include "DJI_motors.h"
#include "dm_motor.h"
#include "GET_RC_TASK.h"

void DEBUG_UART_TASK()
{
    while (1)
    {
        usart1_printf("%f,%f,%f,%d,%d \r\n",
        MOTOR_11_GIVEN_ANGLE,
        MOTOR_11_REAL_ABSC,
        MOTOR_11_GIVEN_SPEED,
        motor_can1_data[0].speed_rpm,
        MOTOR_11_GIVEN_CURRENT
        );


        // usart1_printf("%f,%f,%f,%d,%d \r\n",
        // MOTOR_12_GIVEN_ANGLE,
        // MOTOR_12_REAL_ABSC,
        // MOTOR_12_GIVEN_SPEED,
        // motor_can1_data[1].speed_rpm,
        // MOTOR_12_GIVEN_CURRENT
        // );


        // usart1_printf("%f,%f \r\n",
        //               timeA,
        //               timeB
        // );
        osDelay(1);
    }
}
