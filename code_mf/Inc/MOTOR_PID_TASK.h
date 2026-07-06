//
// Created by 21481 on 2026/7/6.
//

#ifndef DM_H723_LIB_MOTOR_PID_TASK_H
#define DM_H723_LIB_MOTOR_PID_TASK_H
#include "pid.h"


#define MOTOR_3508_SPEED_PID_KP 8.0f
#define MOTOR_3508_SPEED_PID_KI 0.01f
#define MOTOR_3508_SPEED_PID_KD 0.0f
#define MOTOR_3508_SPEED_PID_OUT_MAX 5000.0f//电机输出的最大劲
#define MOTOR_3508_SPEED_PID_KI_MAX 2000.0f

#define MOTOR_3508_ANGLE_PID_KP 0.4f
#define MOTOR_3508_ANGLE_PID_KI 0.0f
#define MOTOR_3508_ANGLE_PID_KD 0.0f
#define MOTOR_3508_ANGLE_PID_OUT_MAX 2000.0f
#define MOTOR_3508_ANGLE_PID_KI_MAX 0.0f



extern pid_type_def MOTOR_11_speed_pid;
extern pid_type_def MOTOR_12_speed_pid;
extern pid_type_def MOTOR_13_speed_pid;
extern pid_type_def MOTOR_14_speed_pid;
extern pid_type_def MOTOR_21_speed_pid;
extern pid_type_def MOTOR_22_speed_pid;
extern pid_type_def MOTOR_23_speed_pid;
extern pid_type_def MOTOR_24_speed_pid;

extern pid_type_def MOTOR_11_angle_pid;
extern pid_type_def MOTOR_12_angle_pid;
extern pid_type_def MOTOR_13_angle_pid;
extern pid_type_def MOTOR_14_angle_pid;
extern pid_type_def MOTOR_21_angle_pid;
extern pid_type_def MOTOR_22_angle_pid;
extern pid_type_def MOTOR_23_angle_pid;
extern pid_type_def MOTOR_24_angle_pid;


void pid_compute();

void MOTOR_11_speed_pid_init(void);
void MOTOR_12_speed_pid_init(void);
void MOTOR_13_speed_pid_init(void);
void MOTOR_14_speed_pid_init(void);
void MOTOR_21_speed_pid_init(void);
void MOTOR_22_speed_pid_init(void);
void MOTOR_23_speed_pid_init(void);
void MOTOR_24_speed_pid_init(void);
void MOTOR_11_angle_pid_init(void);
void MOTOR_12_angle_pid_init(void);
void MOTOR_13_angle_pid_init(void);
void MOTOR_14_angle_pid_init(void);
void MOTOR_21_angle_pid_init(void);
void MOTOR_22_angle_pid_init(void);
void MOTOR_23_angle_pid_init(void);
void MOTOR_24_angle_pid_init(void);



int16_t MOTOR_11_speed_pid_loop(float MOTOR_11_speed_set_loop);
int16_t MOTOR_12_speed_pid_loop(float MOTOR_12_speed_set_loop);
int16_t MOTOR_13_speed_pid_loop(float MOTOR_13_speed_set_loop);
int16_t MOTOR_14_speed_pid_loop(float MOTOR_14_speed_set_loop);
int16_t MOTOR_21_speed_pid_loop(float MOTOR_21_speed_set_loop);
int16_t MOTOR_22_speed_pid_loop(float MOTOR_22_speed_set_loop);
int16_t MOTOR_23_speed_pid_loop(float MOTOR_23_speed_set_loop);
int16_t MOTOR_24_speed_pid_loop(float MOTOR_24_speed_set_loop);

float MOTOR_11_angle_pid_loop(float MOTOR_11_angle_set_loop);
float MOTOR_12_angle_pid_loop(float MOTOR_12_angle_set_loop);
float MOTOR_13_angle_pid_loop(float MOTOR_13_angle_set_loop);
float MOTOR_14_angle_pid_loop(float MOTOR_14_angle_set_loop);
float MOTOR_21_angle_pid_loop(float MOTOR_21_angle_set_loop);
float MOTOR_22_angle_pid_loop(float MOTOR_22_angle_set_loop);
float MOTOR_23_angle_pid_loop(float MOTOR_23_angle_set_loop);
float MOTOR_24_angle_pid_loop(float MOTOR_24_angle_set_loop);


#endif //DM_H723_LIB_MOTOR_PID_TASK_H
