/**
 * @file      : main.c
 * @brief     : 程序入口文件
 * @author    : huenrong (huenrong1028@outlook.com)
 * @date      : 2023-02-04 14:45:04
 *
 * @copyright : Copyright (c) 2023 huenrong
 *
 * @history   : date       author          description
 *              2023-02-04 huenrong        创建文件
 *
 */

#include <stdio.h>

#include "./linux_pwm/pwm.h"

// PWM定义
#define PWM_CHIP_0 0

/**
 * @brief  : 程序入口
 * @param  : argc: 输入参数, 参数个数
 * @param  : argv: 输入参数, 参数列表
 * @return : 成功: 0
 *           失败: 其它
 */
int main(int argc, char *argv[])
{
    // 导出设备
    if (!pwm_export(PWM_CHIP_0))
    {
        printf("export pwmchip%d fail\n", PWM_CHIP_0);

        return -1;
    }

    // 使能PWM
    if (!pwm_enable(PWM_CHIP_0))
    {
        printf("enable pwmchip%d fail\n", PWM_CHIP_0);

        return -1;
    }

    // 设置周期
    if (!pwm_set_period(PWM_CHIP_0, 50000))
    {
        printf("set pwmchip%d period fail\n", PWM_CHIP_0);

        return -1;
    }

    // 设置占空比
    if (!pwm_set_duty_cycle(PWM_CHIP_0, 10000))
    {
        printf("set pwmchip%d duty_cycle fail\n", PWM_CHIP_0);

        return -1;
    }

    // 取消导出
    if (!pwm_unexport(PWM_CHIP_0))
    {
        printf("unexport pwmchip%d fail\n", PWM_CHIP_0);

        return -1;
    }

    return 0;
}
