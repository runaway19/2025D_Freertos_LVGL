#include "AD9959.H"

uint8_t CSR_DATA0[1] = {0x10};     // 开 CH0
uint8_t CSR_DATA1[1] = {0x20};      // 开 CH1
uint8_t CSR_DATA2[1] = {0x40};      // 开 CH2
uint8_t CSR_DATA3[1] = {0x80};      // 开 CH3		
																	
 uint8_t FR1_DATA[3] = {0xD0,0x00,0x00};//20倍频 Charge pump control = 75uA FR1<23> -- VCO gain control =0时 system clock below 160 MHz;
uint8_t FR2_DATA[2] = {0x20,0x00};//default Value = 0x0000
uint8_t CFR_DATA[3] = {0x00,0x03,0x02};//default Value = 0x000302	   
																	
uint8_t CPOW0_DATA[2] = {0x00,0x00};//default Value = 0x0000   @ = POW/2^14*360
																	


uint8_t LSRR_DATA[2] = {0x00,0x00};//default Value = 0x----
																	
uint8_t RDW_DATA[4] = {0x00,0x00,0x00,0x00};//default Value = 0x--------
																	
uint8_t FDW_DATA[4] = {0x00,0x00,0x00,0x00};//default Value = 0x--------

//AD9959初始化
void Init_AD9959(void)  
{  			
//	GPIO_InitTypeDef GPIO_InitStruct;
	Intserve();  //IO口初始化
  IntReset();  //AD9959复位  
	
  WriteData_AD9959(FR1_ADD,3,FR1_DATA,1);//写功能寄存器1
  WriteData_AD9959(FR2_ADD,2,FR2_DATA,1);
//	WriteData_AD9959(CFR_ADD, 3, CFR_DATA, 1);

} 
//延时
void delay1 (uint32_t us)
{
    uint32_t cycles = us * 42; 
    volatile uint32_t count = cycles;
    while(count--);
}
//IO口初始化
void Intserve(void)		   
{   
		AD9959_PWR_0;
    CS_1;
    SCLK_0;
    UPDATE_0;
    PS0_0;
    PS1_0;
    PS2_0;
    PS3_0;
    SDIO0_0;
    SDIO1_0;
    SDIO2_0;
    SDIO3_0;
}
//AD9959复位
void IntReset(void)	  
{
  Reset_0;
	delay1(1);
	Reset_1;
	delay1(30);
	Reset_0;
}
 //AD9959更新数据
void IO_Update(void)  
{
	UPDATE_0;
	delay1(2);
	UPDATE_1;
	delay1(4);
	UPDATE_0;
}
/*--------------------------------------------
函数功能：控制器通过SPI向AD9959写数据
RegisterAddress: 寄存器地址
NumberofRegisters: 所含字节数
*RegisterData: 数据起始地址
temp: 是否更新IO寄存器
----------------------------------------------*/
void WriteData_AD9959(uint8_t RegisterAddress, uint8_t NumberofRegisters, uint8_t *RegisterData,uint8_t temp)
{
	uint8_t	ControlValue = 0;
	uint8_t	ValueToWrite = 0;
	uint8_t	RegisterIndex = 0;
	uint8_t	i = 0;

	ControlValue = RegisterAddress;
//写入地址
	SCLK_0;
	CS_0;	 
	for(i=0; i<8; i++)
	{
		SCLK_0;
		if(0x80 == (ControlValue & 0x80))
		SDIO0_1;	  
		else
		SDIO0_0;	  
		SCLK_1;
		ControlValue <<= 1;
	}
	SCLK_0;
//写入数据
	for (RegisterIndex=0; RegisterIndex<NumberofRegisters; RegisterIndex++)
	{
		ValueToWrite = RegisterData[RegisterIndex];
		for (i=0; i<8; i++)
		{
			SCLK_0;
			if(0x80 == (ValueToWrite & 0x80))
			SDIO0_1;	  
			else
			SDIO0_0;	  
			SCLK_1;
			ValueToWrite <<= 1;
		}
		SCLK_0;		
	}	
	if(temp != 0)
	IO_Update();	
  CS_1;
} 
/*---------------------------------------
函数功能：设置通道输出频率
Channel:  输出通道
Freq:     输出频率
---------------------------------------*/
void Write_frequence(uint8_t Channel,uint32_t Freq)
{	 
		uint8_t CFTW0_DATA[4] ={0x00,0x00,0x00,0x00};	//中间变量
	  uint32_t Temp;            
	  Temp=(uint32_t)Freq*8.589934592;	   //将输入频率因子分为四个字节  8.589934592=(2^32)/500000000 其中500M=25M*20(倍频数可编程)
	  CFTW0_DATA[3]=(uint8_t)Temp;
	  CFTW0_DATA[2]=(uint8_t)(Temp>>8);
	  CFTW0_DATA[1]=(uint8_t)(Temp>>16);
	  CFTW0_DATA[0]=(uint8_t)(Temp>>24);
	  if(Channel==0)	  
	  {
			WriteData_AD9959(CSR_ADD,1,CSR_DATA0,1);//控制寄存器写入CH0通道
      WriteData_AD9959(CFTW0_ADD,4,CFTW0_DATA,1);//CTW0 address 0x04.输出CH0设定频率
		}
	  else if(Channel==1)	
	  {
			WriteData_AD9959(CSR_ADD,1,CSR_DATA1,1);//控制寄存器写入CH1通道
      WriteData_AD9959(CFTW0_ADD,4,CFTW0_DATA,1);//CTW0 address 0x04.输出CH1设定频率	
	  }
	  else if(Channel==2)	
	  {
			WriteData_AD9959(CSR_ADD,1,CSR_DATA2,1);//控制寄存器写入CH2通道
      WriteData_AD9959(CFTW0_ADD,4,CFTW0_DATA,1);//CTW0 address 0x04.输出CH2设定频率	
	  }
	  else if(Channel==3)	
	  {
			WriteData_AD9959(CSR_ADD,1,CSR_DATA3,1);//控制寄存器写入CH3通道
      WriteData_AD9959(CFTW0_ADD,4,CFTW0_DATA,1);//CTW0 address 0x04.输出CH3设定频率	
	  }																																																																										 
	
} 
/*---------------------------------------
函数功能：设置通道输出幅度
Channel:  输出通道
Ampli:    输出幅度
---------------------------------------*/
void Write_Amplitude(uint8_t Channel, uint16_t Ampli)
{ 
	uint16_t A_temp;//=0x23ff;
	uint8_t ACR_DATA[3] = {0x00,0x00,0x00};//default Value = 0x--0000 Rest = 18.91/Iout 
	
  A_temp=Ampli|0x1000;
	ACR_DATA[2] = (uint8_t)A_temp;  //低位数据
  ACR_DATA[1] = (uint8_t)(A_temp>>8); //高位数据
  if(Channel==0)
  {
		WriteData_AD9959(CSR_ADD,1,CSR_DATA0,1); 
    WriteData_AD9959(ACR_ADD,3,ACR_DATA,1); 
	}
  else if(Channel==1)
  {
		WriteData_AD9959(CSR_ADD,1,CSR_DATA1,1); 
    WriteData_AD9959(ACR_ADD,3,ACR_DATA,1);
	}
  else if(Channel==2)
  {
	  WriteData_AD9959(CSR_ADD,1,CSR_DATA2,1); 
    WriteData_AD9959(ACR_ADD,3,ACR_DATA,1); 
	}
  else if(Channel==3)
  {
		WriteData_AD9959(CSR_ADD,1,CSR_DATA3,1); 
    WriteData_AD9959(ACR_ADD,3,ACR_DATA,1); 
	}
}
/*---------------------------------------
函数功能：设置通道输出相位
Channel:  输出通道
Phase:    输出相位,范围：0~16383(对应角度：0°~360°)
---------------------------------------*/
void Write_Phase(uint8_t Channel,uint16_t Phase)
{
	uint16_t P_temp=0;
  P_temp=(uint16_t)Phase;
	CPOW0_DATA[1]=(uint8_t)P_temp;
	CPOW0_DATA[0]=(uint8_t)(P_temp>>8);
	if(Channel==0)
  {
		WriteData_AD9959(CSR_ADD,1,CSR_DATA0,1); 
    WriteData_AD9959(CPOW0_ADD,2,CPOW0_DATA,1);
  }
  else if(Channel==1)
  {
		WriteData_AD9959(CSR_ADD,1,CSR_DATA1,1); 
    WriteData_AD9959(CPOW0_ADD,2,CPOW0_DATA,1);
  }
  else if(Channel==2)
  {
		WriteData_AD9959(CSR_ADD,1,CSR_DATA2,1); 
    WriteData_AD9959(CPOW0_ADD,2,CPOW0_DATA,1);
  }
  else if(Channel==3)
  {
		WriteData_AD9959(CSR_ADD,1,CSR_DATA3,1); 
    WriteData_AD9959(CPOW0_ADD,2,CPOW0_DATA,1);
  }
}
