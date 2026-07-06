//
// Created by 21481 on 2026/7/6.
//

#include "MOTOR_PID_TASK.h"

#include "ABSC_GET_TASK.h"
#include "cmsis_os.h"
#include "DJI_motors.h"
#include "GET_RC_TASK.h"
#include "pid.h"
#include "uart_printf.h"

pid_type_def MOTOR_11_speed_pid;
pid_type_def MOTOR_12_speed_pid;
pid_type_def MOTOR_13_speed_pid;
pid_type_def MOTOR_14_speed_pid;
pid_type_def MOTOR_21_speed_pid;
pid_type_def MOTOR_22_speed_pid;
pid_type_def MOTOR_23_speed_pid;
pid_type_def MOTOR_24_speed_pid;


pid_type_def MOTOR_11_angle_pid;
pid_type_def MOTOR_12_angle_pid;
pid_type_def MOTOR_13_angle_pid;
pid_type_def MOTOR_14_angle_pid;
pid_type_def MOTOR_21_angle_pid;
pid_type_def MOTOR_22_angle_pid;
pid_type_def MOTOR_23_angle_pid;
pid_type_def MOTOR_24_angle_pid;

void MOTOR_PID_TASK()
{
    MOTOR_11_speed_pid_init();
    MOTOR_12_speed_pid_init();
    MOTOR_13_speed_pid_init();
    MOTOR_14_speed_pid_init();
    MOTOR_11_angle_pid_init();
    MOTOR_12_angle_pid_init();
    MOTOR_13_angle_pid_init();
    MOTOR_14_angle_pid_init();
    MOTOR_21_speed_pid_init();
    MOTOR_22_speed_pid_init();
    MOTOR_23_speed_pid_init();
    MOTOR_24_speed_pid_init();
    MOTOR_21_angle_pid_init();
    MOTOR_22_angle_pid_init();
    MOTOR_23_angle_pid_init();
    MOTOR_24_angle_pid_init();

    osDelay(ABSC_INIT_MS);

    while (1)
    {
        pid_compute();
        osDelay(1);
    }
}




void pid_compute()
{


    MOTOR_11_GIVEN_ANGLE =  MOTOR_11_TARGET_ABSC ;
    MOTOR_12_GIVEN_ANGLE =  MOTOR_12_TARGET_ABSC ;
    MOTOR_13_GIVEN_ANGLE =  MOTOR_13_TARGET_ABSC ;
    MOTOR_14_GIVEN_ANGLE =  MOTOR_14_TARGET_ABSC ;
    MOTOR_21_GIVEN_ANGLE =  MOTOR_21_TARGET_ABSC ;
    MOTOR_22_GIVEN_ANGLE =  MOTOR_22_TARGET_ABSC ;
    MOTOR_23_GIVEN_ANGLE =  MOTOR_23_TARGET_ABSC ;
    MOTOR_24_GIVEN_ANGLE =  MOTOR_24_TARGET_ABSC ;

    //位置环
    MOTOR_11_GIVEN_SPEED = MOTOR_11_angle_pid_loop(MOTOR_11_GIVEN_ANGLE);
    MOTOR_12_GIVEN_SPEED = MOTOR_12_angle_pid_loop(MOTOR_12_GIVEN_ANGLE);
    MOTOR_13_GIVEN_SPEED = MOTOR_13_angle_pid_loop(MOTOR_13_GIVEN_ANGLE);
    MOTOR_14_GIVEN_SPEED = MOTOR_14_angle_pid_loop(MOTOR_14_GIVEN_ANGLE);
    MOTOR_21_GIVEN_SPEED = MOTOR_21_angle_pid_loop(MOTOR_21_GIVEN_ANGLE);
    MOTOR_22_GIVEN_SPEED = MOTOR_22_angle_pid_loop(MOTOR_22_GIVEN_ANGLE);
    MOTOR_23_GIVEN_SPEED = MOTOR_23_angle_pid_loop(MOTOR_23_GIVEN_ANGLE);
    MOTOR_24_GIVEN_SPEED = MOTOR_24_angle_pid_loop(MOTOR_24_GIVEN_ANGLE);
    //速度环


    MOTOR_11_GIVEN_CURRENT = MOTOR_11_speed_pid_loop(MOTOR_11_GIVEN_SPEED);
    MOTOR_12_GIVEN_CURRENT = MOTOR_12_speed_pid_loop(MOTOR_12_GIVEN_SPEED);
    MOTOR_13_GIVEN_CURRENT = MOTOR_13_speed_pid_loop(MOTOR_13_GIVEN_SPEED);
    MOTOR_14_GIVEN_CURRENT = MOTOR_14_speed_pid_loop(MOTOR_14_GIVEN_SPEED);
    MOTOR_21_GIVEN_CURRENT = MOTOR_21_speed_pid_loop(MOTOR_21_GIVEN_SPEED);
    MOTOR_22_GIVEN_CURRENT = MOTOR_22_speed_pid_loop(MOTOR_22_GIVEN_SPEED);
    MOTOR_23_GIVEN_CURRENT = MOTOR_23_speed_pid_loop(MOTOR_23_GIVEN_SPEED);
    MOTOR_24_GIVEN_CURRENT = MOTOR_24_speed_pid_loop(MOTOR_24_GIVEN_SPEED);


}

//pid control
//MOTOR11
void MOTOR_11_speed_pid_init(void)
{
    static fp32 MOTOR_11_speed_kpkikd[3] = {MOTOR_3508_SPEED_PID_KP,MOTOR_3508_SPEED_PID_KI,MOTOR_3508_SPEED_PID_KD};
    PID_init(&MOTOR_11_speed_pid,PID_POSITION,MOTOR_11_speed_kpkikd,MOTOR_3508_SPEED_PID_OUT_MAX,MOTOR_3508_SPEED_PID_KI_MAX);

}

int16_t MOTOR_11_speed_pid_loop(float MOTOR_11_speed_set_loop)
{
    PID_calc(&MOTOR_11_speed_pid, motor_can1_data[0].speed_rpm, MOTOR_11_speed_set_loop);
    int16_t MOTOR_11_given_current_loop = (int16_t)(MOTOR_11_speed_pid.out);

    return MOTOR_11_given_current_loop ;

}

void MOTOR_11_angle_pid_init(void)
{
    static fp32 MOTOR_11_angle_kpkikd[3] = {MOTOR_3508_ANGLE_PID_KP,MOTOR_3508_ANGLE_PID_KI,MOTOR_3508_ANGLE_PID_KD};
    PID_init(&MOTOR_11_angle_pid,PID_POSITION,MOTOR_11_angle_kpkikd,MOTOR_3508_ANGLE_PID_OUT_MAX,MOTOR_3508_ANGLE_PID_KI_MAX);

}

float MOTOR_11_angle_pid_loop(float MOTOR_11_angle_set_loop)
{
    PID_calc(&MOTOR_11_angle_pid, MOTOR_11_REAL_ABSC, MOTOR_11_angle_set_loop);
    float MOTOR_11_given_current_loop = MOTOR_11_angle_pid.out;

    return MOTOR_11_given_current_loop ;

}


//MOTOR12
void MOTOR_12_speed_pid_init(void)
{
    static fp32 MOTOR_12_speed_kpkikd[3] = {MOTOR_3508_SPEED_PID_KP,MOTOR_3508_SPEED_PID_KI,MOTOR_3508_SPEED_PID_KD};
    PID_init(&MOTOR_12_speed_pid,PID_POSITION,MOTOR_12_speed_kpkikd,MOTOR_3508_SPEED_PID_OUT_MAX,MOTOR_3508_SPEED_PID_KI_MAX);

}

int16_t MOTOR_12_speed_pid_loop(float MOTOR_12_speed_set_loop)
{
    PID_calc(&MOTOR_12_speed_pid, motor_can1_data[1].speed_rpm, MOTOR_12_speed_set_loop);
    int16_t MOTOR_12_given_current_loop = (int16_t)(MOTOR_12_speed_pid.out);

    return MOTOR_12_given_current_loop ;

}

void MOTOR_12_angle_pid_init(void)
{
    static fp32 MOTOR_12_angle_kpkikd[3] = {MOTOR_3508_ANGLE_PID_KP,MOTOR_3508_ANGLE_PID_KI,MOTOR_3508_ANGLE_PID_KD};
    PID_init(&MOTOR_12_angle_pid,PID_POSITION,MOTOR_12_angle_kpkikd,MOTOR_3508_ANGLE_PID_OUT_MAX,MOTOR_3508_ANGLE_PID_KI_MAX);

}

float MOTOR_12_angle_pid_loop(float MOTOR_12_angle_set_loop)
{
    PID_calc(&MOTOR_12_angle_pid, MOTOR_12_REAL_ABSC, MOTOR_12_angle_set_loop);
    float MOTOR_12_given_current_loop = MOTOR_12_angle_pid.out;

    return MOTOR_12_given_current_loop ;

}


//MOTOR13
void MOTOR_13_speed_pid_init(void)
{
    static fp32 MOTOR_13_speed_kpkikd[3] = {MOTOR_3508_SPEED_PID_KP,MOTOR_3508_SPEED_PID_KI,MOTOR_3508_SPEED_PID_KD};
    PID_init(&MOTOR_13_speed_pid,PID_POSITION,MOTOR_13_speed_kpkikd,MOTOR_3508_SPEED_PID_OUT_MAX,MOTOR_3508_SPEED_PID_KI_MAX);

}

int16_t MOTOR_13_speed_pid_loop(float MOTOR_13_speed_set_loop)
{
    PID_calc(&MOTOR_13_speed_pid, motor_can1_data[2].speed_rpm, MOTOR_13_speed_set_loop);
    int16_t MOTOR_13_given_current_loop = (int16_t)(MOTOR_13_speed_pid.out);

    return MOTOR_13_given_current_loop ;

}

void MOTOR_13_angle_pid_init(void)
{
    static fp32 MOTOR_13_angle_kpkikd[3] = {MOTOR_3508_ANGLE_PID_KP,MOTOR_3508_ANGLE_PID_KI,MOTOR_3508_ANGLE_PID_KD};
    PID_init(&MOTOR_13_angle_pid,PID_POSITION,MOTOR_13_angle_kpkikd,MOTOR_3508_ANGLE_PID_OUT_MAX,MOTOR_3508_ANGLE_PID_KI_MAX);

}

float MOTOR_13_angle_pid_loop(float MOTOR_13_angle_set_loop)
{
    PID_calc(&MOTOR_13_angle_pid, MOTOR_13_REAL_ABSC, MOTOR_13_angle_set_loop);
    float MOTOR_13_given_current_loop = MOTOR_13_angle_pid.out;

    return MOTOR_13_given_current_loop ;

}


//MOTOR14
void MOTOR_14_speed_pid_init(void)
{
    static fp32 MOTOR_14_speed_kpkikd[3] = {MOTOR_3508_SPEED_PID_KP,MOTOR_3508_SPEED_PID_KI,MOTOR_3508_SPEED_PID_KD};
    PID_init(&MOTOR_14_speed_pid,PID_POSITION,MOTOR_14_speed_kpkikd,MOTOR_3508_SPEED_PID_OUT_MAX,MOTOR_3508_SPEED_PID_KI_MAX);

}

int16_t MOTOR_14_speed_pid_loop(float MOTOR_14_speed_set_loop)
{
    PID_calc(&MOTOR_14_speed_pid, motor_can1_data[3].speed_rpm, MOTOR_14_speed_set_loop);
    int16_t MOTOR_14_given_current_loop = (int16_t)(MOTOR_14_speed_pid.out);

    return MOTOR_14_given_current_loop ;

}

void MOTOR_14_angle_pid_init(void)
{
    static fp32 MOTOR_14_angle_kpkikd[3] = {MOTOR_3508_ANGLE_PID_KP,MOTOR_3508_ANGLE_PID_KI,MOTOR_3508_ANGLE_PID_KD};
    PID_init(&MOTOR_14_angle_pid,PID_POSITION,MOTOR_14_angle_kpkikd,MOTOR_3508_ANGLE_PID_OUT_MAX,MOTOR_3508_ANGLE_PID_KI_MAX);

}

float MOTOR_14_angle_pid_loop(float MOTOR_14_angle_set_loop)
{
    PID_calc(&MOTOR_14_angle_pid, MOTOR_14_REAL_ABSC, MOTOR_14_angle_set_loop);
    float MOTOR_14_given_current_loop = MOTOR_14_angle_pid.out;

    return MOTOR_14_given_current_loop ;

}


//MOTOR21
void MOTOR_21_speed_pid_init(void)
{
    static fp32 MOTOR_21_speed_kpkikd[3] = {MOTOR_3508_SPEED_PID_KP,MOTOR_3508_SPEED_PID_KI,MOTOR_3508_SPEED_PID_KD};
    PID_init(&MOTOR_21_speed_pid,PID_POSITION,MOTOR_21_speed_kpkikd,MOTOR_3508_SPEED_PID_OUT_MAX,MOTOR_3508_SPEED_PID_KI_MAX);

}

int16_t MOTOR_21_speed_pid_loop(float MOTOR_21_speed_set_loop)
{
    PID_calc(&MOTOR_21_speed_pid, motor_can2_data[0].speed_rpm, MOTOR_21_speed_set_loop);
    int16_t MOTOR_21_given_current_loop = (int16_t)(MOTOR_21_speed_pid.out);

    return MOTOR_21_given_current_loop ;

}

void MOTOR_21_angle_pid_init(void)
{
    static fp32 MOTOR_21_angle_kpkikd[3] = {MOTOR_3508_ANGLE_PID_KP,MOTOR_3508_ANGLE_PID_KI,MOTOR_3508_ANGLE_PID_KD};
    PID_init(&MOTOR_21_angle_pid,PID_POSITION,MOTOR_21_angle_kpkikd,MOTOR_3508_ANGLE_PID_OUT_MAX,MOTOR_3508_ANGLE_PID_KI_MAX);

}

float MOTOR_21_angle_pid_loop(float MOTOR_21_angle_set_loop)
{
    PID_calc(&MOTOR_21_angle_pid, MOTOR_21_REAL_ABSC, MOTOR_21_angle_set_loop);
    float MOTOR_21_given_current_loop = MOTOR_21_angle_pid.out;

    return MOTOR_21_given_current_loop ;

}

//MOTOR22
void MOTOR_22_speed_pid_init(void)
{
    static fp32 MOTOR_22_speed_kpkikd[3] = {MOTOR_3508_SPEED_PID_KP,MOTOR_3508_SPEED_PID_KI,MOTOR_3508_SPEED_PID_KD};
    PID_init(&MOTOR_22_speed_pid,PID_POSITION,MOTOR_22_speed_kpkikd,MOTOR_3508_SPEED_PID_OUT_MAX,MOTOR_3508_SPEED_PID_KI_MAX);

}

int16_t MOTOR_22_speed_pid_loop(float MOTOR_22_speed_set_loop)
{
    PID_calc(&MOTOR_22_speed_pid, motor_can2_data[1].speed_rpm, MOTOR_22_speed_set_loop);
    int16_t MOTOR_22_given_current_loop = (int16_t)(MOTOR_22_speed_pid.out);

    return MOTOR_22_given_current_loop ;

}

void MOTOR_22_angle_pid_init(void)
{
    static fp32 MOTOR_22_angle_kpkikd[3] = {MOTOR_3508_ANGLE_PID_KP,MOTOR_3508_ANGLE_PID_KI,MOTOR_3508_ANGLE_PID_KD};
    PID_init(&MOTOR_22_angle_pid,PID_POSITION,MOTOR_22_angle_kpkikd,MOTOR_3508_ANGLE_PID_OUT_MAX,MOTOR_3508_ANGLE_PID_KI_MAX);

}

float MOTOR_22_angle_pid_loop(float MOTOR_22_angle_set_loop)
{
    PID_calc(&MOTOR_22_angle_pid, MOTOR_22_REAL_ABSC, MOTOR_22_angle_set_loop);
    float MOTOR_22_given_current_loop = MOTOR_22_angle_pid.out;

    return MOTOR_22_given_current_loop ;

}


//MOTOR23
void MOTOR_23_speed_pid_init(void)
{
    static fp32 MOTOR_23_speed_kpkikd[3] = {MOTOR_3508_SPEED_PID_KP,MOTOR_3508_SPEED_PID_KI,MOTOR_3508_SPEED_PID_KD};
    PID_init(&MOTOR_23_speed_pid,PID_POSITION,MOTOR_23_speed_kpkikd,MOTOR_3508_SPEED_PID_OUT_MAX,MOTOR_3508_SPEED_PID_KI_MAX);

}

int16_t MOTOR_23_speed_pid_loop(float MOTOR_23_speed_set_loop)
{
    PID_calc(&MOTOR_23_speed_pid, motor_can2_data[2].speed_rpm, MOTOR_23_speed_set_loop);
    int16_t MOTOR_23_given_current_loop = (int16_t)(MOTOR_23_speed_pid.out);

    return MOTOR_23_given_current_loop ;

}

void MOTOR_23_angle_pid_init(void)
{
    static fp32 MOTOR_23_angle_kpkikd[3] = {MOTOR_3508_ANGLE_PID_KP,MOTOR_3508_ANGLE_PID_KI,MOTOR_3508_ANGLE_PID_KD};
    PID_init(&MOTOR_23_angle_pid,PID_POSITION,MOTOR_23_angle_kpkikd,MOTOR_3508_ANGLE_PID_OUT_MAX,MOTOR_3508_ANGLE_PID_KI_MAX);

}

float MOTOR_23_angle_pid_loop(float MOTOR_23_angle_set_loop)
{
    PID_calc(&MOTOR_23_angle_pid, MOTOR_23_REAL_ABSC, MOTOR_23_angle_set_loop);
    float MOTOR_23_given_current_loop = MOTOR_23_angle_pid.out;

    return MOTOR_23_given_current_loop ;

}



//MOTOR24
void MOTOR_24_speed_pid_init(void)
{
    static fp32 MOTOR_24_speed_kpkikd[3] = {MOTOR_3508_SPEED_PID_KP,MOTOR_3508_SPEED_PID_KI,MOTOR_3508_SPEED_PID_KD};
    PID_init(&MOTOR_24_speed_pid,PID_POSITION,MOTOR_24_speed_kpkikd,MOTOR_3508_SPEED_PID_OUT_MAX,MOTOR_3508_SPEED_PID_KI_MAX);

}

int16_t MOTOR_24_speed_pid_loop(float MOTOR_24_speed_set_loop)
{
    PID_calc(&MOTOR_24_speed_pid, motor_can2_data[3].speed_rpm, MOTOR_24_speed_set_loop);
    int16_t MOTOR_24_given_current_loop = (int16_t)(MOTOR_24_speed_pid.out);

    return MOTOR_24_given_current_loop ;

}

void MOTOR_24_angle_pid_init(void)
{
    static fp32 MOTOR_24_angle_kpkikd[3] = {MOTOR_3508_ANGLE_PID_KP,MOTOR_3508_ANGLE_PID_KI,MOTOR_3508_ANGLE_PID_KD};
    PID_init(&MOTOR_24_angle_pid,PID_POSITION,MOTOR_24_angle_kpkikd,MOTOR_3508_ANGLE_PID_OUT_MAX,MOTOR_3508_ANGLE_PID_KI_MAX);

}

float MOTOR_24_angle_pid_loop(float MOTOR_24_angle_set_loop)
{
    PID_calc(&MOTOR_24_angle_pid, MOTOR_24_REAL_ABSC, MOTOR_24_angle_set_loop);
    float MOTOR_24_given_current_loop = MOTOR_24_angle_pid.out;

    return MOTOR_24_given_current_loop ;

}