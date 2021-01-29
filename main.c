#include <xc.h>
#include "pic16f18854.h"
#include "init.h"
#include "i2c_master.h"

#define SLAVE_ADD 0x70
#define VOLTADE_ADD 0x68
uint8_t slave_feedback1, slave_feedback2, slave_feedback3;
void main(void) {
    init();
    I2C_Master_Start();        
    I2C_Master_Write((SLAVE_ADD << 1)|0); //7 bit address + Write(0)
    I2C_Master_Write(0x01); //傳0b0101 0101
    I2C_Master_Stop(); 
    
    I2C_Master_Start();  
    I2C_Master_Write((SLAVE_ADD << 1)|0);
    I2C_Master_RepeatedStart();
    I2C_Master_Write((VOLTADE_ADD << 1)|0); //7 bit address + Write(0)
    I2C_Master_Write(0x80);
    I2C_Master_Stop(); 
    
    I2C_Master_Start();
    I2C_Master_Write((SLAVE_ADD << 1)|0); //7 bit address + Write(0)
    I2C_Master_RepeatedStart();
    I2C_Master_Write((VOLTADE_ADD << 1)|1); //7 bit address + Read(1)
    slave_feedback1=I2C_Master_Read(1);
    slave_feedback2=I2C_Master_Read(0);
    I2C_Master_Stop();
    
    
    
    
//可以不用對電壓的寫    
//    I2C_Master_Start(); 
//    I2C_Master_Write((VOLTADE_ADD << 1)|0); //7 bit address + Write(0)
//    I2C_Master_Write(0x90);
//    I2C_Master_Stop();//read後會過36ms才stop
    
//    I2C_Master_Start(); 
//    I2C_Master_Write((VOLTADE_ADD << 1)|1); //7 bit address + Read(1)
//    slave_feedback1=I2C_Master_Read(1);
//    slave_feedback2=I2C_Master_Read(0);
//    I2C_Master_Stop();//read後會過36ms才stop
    
   
    while(1){
    ;
    }
}
