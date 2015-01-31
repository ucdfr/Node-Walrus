/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 *this code is just genreate can bus message with payload as:
 * const uint8_t test_message[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
 * ========================================
*/
#include <project.h>
#include "can_manager.h"
#include <math.h>

int main()
{
    uint8_t msg[8];
    double x=0;
    uint32_t sin_y=0;
    uint32_t cos_y=0;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    can_init();
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        sin_y=(uint32_t)round(sin(x)*0xffff);
        cos_y=(uint32_t)round(cos(x)*0xffff);
        //msg[0~3] is left
        msg[0]=0x0;
        msg[1]=0x0;
        msg[2]=(sin_y>>8)&0xff;
        msg[3]=(sin_y)&0xff;
        //msg[4~7] is right
        msg[0]=0x0;
        msg[1]=0x0;
        msg[2]=(cos_y>>8)&0xff;
        msg[3]=(cos_y)&0xff;
        
        can_test_send(0x205,msg);
        x=x+0.001;
        CyDelay(10);
    }
}

/* [] END OF FILE */
