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

const float x[63]={0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5,5.1,5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6,6.1,6.2};
const float const_y[63]={0,0.099833,0.19867,0.29552,0.38942,0.47943,0.56464,0.64422,0.71736,0.78333,0.84147,0.89121,0.93204,0.96356,0.98545,0.99749,0.99957,0.99166,0.97385,0.9463,0.9093,0.86321,0.8085,0.74571,0.67546,0.59847,0.5155,0.42738,0.33499,0.23925,0.14112,0.041581,-0.058374,-0.15775,-0.25554,-0.35078,-0.44252,-0.52984,-0.61186,-0.68777,-0.7568,-0.81828,-0.87158,-0.91617,-0.9516,-0.97753,-0.99369,-0.99992,-0.99616,-0.98245,-0.95892,-0.92581,-0.88345,-0.83227,-0.77276,-0.70554,-0.63127,-0.55069,-0.4646,-0.37388,-0.27942,-0.18216,-0.083089};



int main()
{
    int index=0;
    uint8_t msg[8];
    uint16_t left_y,right_y;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    can_init();
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
        if (index>=62){
            index=0;
        }
        left_y=(unsigned)(const_y[index]*400 + 400);
        right_y=(unsigned)(const_y[index]*-400 + 400);
        msg[0]=(left_y>>8)&0xff;
        msg[1]=(left_y)&0xff;
        //msg[4~7] is right
        msg[2]=(right_y>>8)&0xff;
        msg[3]=(right_y)&0xff;
        
        msg[4]=0x00;
        msg[5]=0x00;
        msg[6]=0x00;
        msg[7]=0x00;
        
        can_test_send(0x205,msg);
        index++;
        CyDelay(10);
    }
}

/* [] END OF FILE */
