//
// Created by 21481 on 2026/7/7.
//

#ifndef DM_H723_LIB_GET_TARGET_ABSC_H
#define DM_H723_LIB_GET_TARGET_ABSC_H

#include "math.h"

// 24772.1643

#define one_laps_3508_pp (19.0f * 8192.0f)
#define one_laps_shaft (2.0f * M_PI)
#define pp_2_shaft (one_laps_3508_pp/one_laps_shaft)

#define MOTOR_11_TURN (-1.0f)
#define MOTOR_12_TURN (+1.0f)
#define MOTOR_13_TURN (-1.0f)
#define MOTOR_14_TURN (+1.0f)

#define MOTOR_21_TURN (-1.0f)
#define MOTOR_22_TURN (+1.0f)
#define MOTOR_23_TURN (-1.0f)
#define MOTOR_24_TURN (+1.0f)


#define MOTOR_11_OUTPUT_SHAFT_ERROR (0.0f *M_PI)
#define MOTOR_12_OUTPUT_SHAFT_ERROR (0.0f *M_PI)
#define MOTOR_13_OUTPUT_SHAFT_ERROR (1.0f *M_PI)
#define MOTOR_14_OUTPUT_SHAFT_ERROR (1.0f *M_PI)
#define MOTOR_21_OUTPUT_SHAFT_ERROR (0.0f *M_PI)
#define MOTOR_22_OUTPUT_SHAFT_ERROR (0.0f *M_PI)
#define MOTOR_23_OUTPUT_SHAFT_ERROR (1.0f *M_PI)
#define MOTOR_24_OUTPUT_SHAFT_ERROR (1.0f *M_PI)










#endif //DM_H723_LIB_GET_TARGET_ABSC_H
