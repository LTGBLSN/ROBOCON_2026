//
// Created by 21481 on 2026/7/7.
//


#include "cmsis_os.h"
#include "main.h"
#include "uart_printf.h"
#include "math.h"
#include "CHASSIS_TASK.h"

#include "ABSC_GET_TASK.h"
#include "GET_RC_TASK.h"


void CHASSIS_TASK()
{
    osDelay(ABSC_INIT_MS);
    while (1)
    {
        get_time();

        leg_control();




        osDelay(1);
    }
}


void leg_control()
{
    if (rcData.rc.s[0] == 3)
    {
        // LEFT_BEHIND_X = 0.0f;
        // LEFT_BEHIND_Z = -0.2f;
        //
        // RIGHT_BEHIND_X = 0.0f;
        // RIGHT_BEHIND_Z = -0.2f;
        //
        // LEFT_FRONT_X = 0.0f;
        // LEFT_FRONT_Z = -0.2f;
        //
        // RIGHT_FRONT_X = 0.0f;
        // RIGHT_FRONT_Z = -0.2f;

        // get_motor_shaft_angle();

        if (rcData.rc.s[1] == 2)
        {
            MOTOR_11_TARGET_OUTPUT_SHAFT = 0.0f * M_PI ;
            MOTOR_12_TARGET_OUTPUT_SHAFT = 1.0f * M_PI ;
            MOTOR_13_TARGET_OUTPUT_SHAFT = 0.0f * M_PI ;
            MOTOR_14_TARGET_OUTPUT_SHAFT = 1.0f * M_PI ;
            MOTOR_21_TARGET_OUTPUT_SHAFT = 0.0f * M_PI ;
            MOTOR_22_TARGET_OUTPUT_SHAFT = 1.0f * M_PI ;
            MOTOR_23_TARGET_OUTPUT_SHAFT = 0.0f * M_PI ;
            MOTOR_24_TARGET_OUTPUT_SHAFT = 1.0f * M_PI ;
        }
        else
        {
            MOTOR_11_TARGET_OUTPUT_SHAFT = -0.1f * M_PI ;
            MOTOR_12_TARGET_OUTPUT_SHAFT = 1.0f * M_PI ;
            MOTOR_13_TARGET_OUTPUT_SHAFT = -0.1f * M_PI ;
            MOTOR_14_TARGET_OUTPUT_SHAFT = 1.0f * M_PI ;
            MOTOR_21_TARGET_OUTPUT_SHAFT = -0.1f * M_PI ;
            MOTOR_22_TARGET_OUTPUT_SHAFT = 1.0f * M_PI ;
            MOTOR_23_TARGET_OUTPUT_SHAFT = -0.1f * M_PI ;
            MOTOR_24_TARGET_OUTPUT_SHAFT = 1.0f * M_PI ;
        }




    }
    else if (rcData.rc.s[0] == 1)
    {
        chassis_height = 0.187f;
        chassis_speed = (float)rcData.rc.ch[1]/660.0f * 0.1f;
        chassis_yaw_speed = (float)rcData.rc.ch[2]/660.0f * 0.1f;

        LEFT_BEHIND_X = gait_x(timeA, chassis_speed + chassis_yaw_speed );
        LEFT_BEHIND_Z = -chassis_height + gait_z(timeA, 0.04f );

        LEFT_FRONT_X = gait_x(timeB, chassis_speed + chassis_yaw_speed );
        LEFT_FRONT_Z = -chassis_height + gait_z(timeB, 0.04f );

        RIGHT_BEHIND_X = gait_x(timeB, chassis_speed - chassis_yaw_speed );
        RIGHT_BEHIND_Z = -chassis_height + gait_z(timeB, 0.04f );

        RIGHT_FRONT_X = gait_x(timeA, chassis_speed - chassis_yaw_speed );
        RIGHT_FRONT_Z = -chassis_height + gait_z(timeA, 0.04f );

        get_motor_shaft_angle();


    }
}



void get_time()
{
    if (rcData.rc.s[0] == 1)
    {
        if (timeA < T_time)
        {
            timeA++;
        } else
        {
            timeA = 0;
        }
    } else
    {
        timeA = 0;
    }

    if (rcData.rc.s[0] == 1)
    {
        if (timeB < T_time)
        {
            timeB++;
        } else
        {
            timeB = 0;
        }
    } else
    {
        timeB = T_time * 0.5f;
    }





}


float gait_x(float real_time, float step_length)
{
    float x = 0.0f;

    if (real_time < T_time * 0.5)
    {
        x = -step_length * 0.5f + real_time / (T_time * 0.5f) * step_length;

    } else
    {
        x = step_length * 0.5f - (real_time - T_time * 0.5f) / (T_time * 0.5f) * step_length;
    }

    return x;
}


float gait_z(float real_time, float step_height)
{
    float z = 0.0f;

    if (real_time < T_time * 0.5)
    {
        z = step_height * sinf(real_time / (T_time * 0.5f) * (float)M_PI);

    } else
    {
        z = 0.0f;
    }

    return z;
}





void get_motor_shaft_angle()
{

    LEFT_BEHIND_VIRTUAL_LEG_LEARNTH = sqrtf(LEFT_BEHIND_X * LEFT_BEHIND_X + LEFT_BEHIND_Z * LEFT_BEHIND_Z);
    LEFT_BEHIND_VIRTUAL_LEG_ANGLE_047 = M_PI + atan2f(LEFT_BEHIND_Z, LEFT_BEHIND_X);
    LEFT_BEHIND_VIRTUAL_LEG_ANGLE_04 = calculate_opposite_angle(
        SMALL_LEG_LEARNTH, BIG_LEG_LEARNTH, LEFT_BEHIND_VIRTUAL_LEG_LEARNTH);
    LEFT_BEHIND_VIRTUAL_LEG_ANGLE_07 = LEFT_BEHIND_VIRTUAL_LEG_ANGLE_047 - LEFT_BEHIND_VIRTUAL_LEG_ANGLE_04;
    LEFT_BEHIND_VIRTUAL_LEG_ANGLE_0474 = LEFT_BEHIND_VIRTUAL_LEG_ANGLE_047 + LEFT_BEHIND_VIRTUAL_LEG_ANGLE_04;
    MOTOR_11_TARGET_OUTPUT_SHAFT = LEFT_BEHIND_VIRTUAL_LEG_ANGLE_07;
    MOTOR_12_TARGET_OUTPUT_SHAFT = LEFT_BEHIND_VIRTUAL_LEG_ANGLE_0474;

    RIGHT_BEHIND_VIRTUAL_LEG_LEARNTH = sqrtf(RIGHT_BEHIND_X * RIGHT_BEHIND_X + RIGHT_BEHIND_Z * RIGHT_BEHIND_Z);
    RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_047 = M_PI + atan2f(RIGHT_BEHIND_Z, RIGHT_BEHIND_X);
    RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_04 = calculate_opposite_angle(
        SMALL_LEG_LEARNTH, BIG_LEG_LEARNTH, RIGHT_BEHIND_VIRTUAL_LEG_LEARNTH);
    RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_07 = RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_047 - RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_04;
    RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_0474 = RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_047 + RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_04;
    MOTOR_21_TARGET_OUTPUT_SHAFT = RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_07;
    MOTOR_22_TARGET_OUTPUT_SHAFT = RIGHT_BEHIND_VIRTUAL_LEG_ANGLE_0474;

    LEFT_FRONT_VIRTUAL_LEG_LEARNTH = sqrtf(LEFT_FRONT_X * LEFT_FRONT_X + LEFT_FRONT_Z * LEFT_FRONT_Z);
    LEFT_FRONT_VIRTUAL_LEG_ANGLE_047 = M_PI + atan2f(LEFT_FRONT_Z, LEFT_FRONT_X);
    LEFT_FRONT_VIRTUAL_LEG_ANGLE_04 = calculate_opposite_angle(
        SMALL_LEG_LEARNTH, BIG_LEG_LEARNTH, LEFT_FRONT_VIRTUAL_LEG_LEARNTH);
    LEFT_FRONT_VIRTUAL_LEG_ANGLE_07 = LEFT_FRONT_VIRTUAL_LEG_ANGLE_047 - LEFT_FRONT_VIRTUAL_LEG_ANGLE_04;
    LEFT_FRONT_VIRTUAL_LEG_ANGLE_0474 = LEFT_FRONT_VIRTUAL_LEG_ANGLE_047 + LEFT_FRONT_VIRTUAL_LEG_ANGLE_04;
    MOTOR_13_TARGET_OUTPUT_SHAFT = LEFT_FRONT_VIRTUAL_LEG_ANGLE_07;
    MOTOR_14_TARGET_OUTPUT_SHAFT = LEFT_FRONT_VIRTUAL_LEG_ANGLE_0474;

    RIGHT_FRONT_VIRTUAL_LEG_LEARNTH = sqrtf(RIGHT_FRONT_X * RIGHT_FRONT_X + RIGHT_FRONT_Z * RIGHT_FRONT_Z);
    RIGHT_FRONT_VIRTUAL_LEG_ANGLE_047 = M_PI + atan2f(RIGHT_FRONT_Z, RIGHT_FRONT_X);
    RIGHT_FRONT_VIRTUAL_LEG_ANGLE_04 = calculate_opposite_angle(
        SMALL_LEG_LEARNTH, BIG_LEG_LEARNTH, RIGHT_FRONT_VIRTUAL_LEG_LEARNTH);
    RIGHT_FRONT_VIRTUAL_LEG_ANGLE_07 = RIGHT_FRONT_VIRTUAL_LEG_ANGLE_047 - RIGHT_FRONT_VIRTUAL_LEG_ANGLE_04;
    RIGHT_FRONT_VIRTUAL_LEG_ANGLE_0474 = RIGHT_FRONT_VIRTUAL_LEG_ANGLE_047 + RIGHT_FRONT_VIRTUAL_LEG_ANGLE_04;
    MOTOR_23_TARGET_OUTPUT_SHAFT = RIGHT_FRONT_VIRTUAL_LEG_ANGLE_07;
    MOTOR_24_TARGET_OUTPUT_SHAFT = RIGHT_FRONT_VIRTUAL_LEG_ANGLE_0474;
}


/**
 * @brief 使用余弦定理计算三角形中指定边的对角
 * @param a 第一条边的长度（对角将被计算）
 * @param b 第二条边的长度
 * @param c 第三条边的长度
 * @return 返回边a的对角，单位为弧度；如果输入不构成有效三角形则返回-1
 */
float calculate_opposite_angle(float a, float b, float c)
{
    // 检查是否构成有效的三角形
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return -1.0f; // 边长必须为正
    }

    // 三角形不等式检查
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        return -1.0f; // 不满足三角形不等式
    }

    // 使用余弦定理: cos(A) = (b? + c? - a?) / (2bc)
    float cos_angle = (b * b + c * c - a * a) / (2.0f * b * c);

    // 确保cos值在有效范围内 [-1, 1]，防止浮点数精度问题
    if (cos_angle > 1.0f)
    {
        cos_angle = 1.0f;
    } else if (cos_angle < -1.0f)
    {
        cos_angle = -1.0f;
    }

    // 计算角度（弧度）
    float angle_radians = acosf(cos_angle);

    return angle_radians;
}
