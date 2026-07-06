//
// Created by 21481 on 2026/7/7.
//

#ifndef DM_H723_LIB_CHASSIS_TASK_H
#define DM_H723_LIB_CHASSIS_TASK_H


#define BIG_LEG_LEARNTH 0.1326f//大腿长度132.6mm
#define SMALL_LEG_LEARNTH 0.23f//小腿长度230.0mm

void get_motor_shaft_angle();
float calculate_opposite_angle(float a, float b, float c);

#endif //DM_H723_LIB_CHASSIS_TASK_H
