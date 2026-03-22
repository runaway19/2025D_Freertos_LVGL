/* USER CODE BEGIN Header */
/*
 ******************************************************************************
 *    硬件接线
 *    LCD            F4�?发板        
 * ----------------------------------------------------------------------------
 *    GND       ->      GND         
 *    VCC       ->      5V        
 *    LCD_CS    ->      PE6       
 *    LCD_RST   ->      PC1       
 *    LCD_RS    ->      PC0       
 *    SDI(MOSI) ->      PB5       
 *    SCK       ->      PB3       
 *    LED       ->      3.3V
 *    SDO(MISO) ->      PB4       
 *    CTP_SCL   ->      PB8       
 *    CTP_RST   ->      PB7       
 *    CTP_SDA   ->      PB9       
 *    CTP_INT   ->      PB6       
 ****************************************************************************** 
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "my_fun.h"
#include "usart.h"
#include "gpio.h"
#include "adc.h"
#include "LCD.h"
#include "touch.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_demos.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern uint16_t adc_buffer[];
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
osSemaphoreId SPI1_Send_OK; // 定义信号量，用于SPI1发完成标志位
uint8_t CTP_INT_Flag;       // 触摸屏中断标志位
/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId BlinkLED2Handle;
osThreadId LVGL_TaskHandleHandle;
osThreadId FT6336_ScanTaskHandle;
osThreadId key_changemodeHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void BlinkLED2_Task(void const * argument);
void LVGL_TaskHandler_Task(void const * argument);
void FT6336_Scan_Task(void const * argument);
void key_change_mode(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  osSemaphoreDef(SPI1_Send_OK);                                   // 定义名为SPI1_Send_OK的信号量
  SPI1_Send_OK = osSemaphoreCreate(osSemaphore(SPI1_Send_OK), 1); // 创建名为SPI1_Send_OK的信号量实例，并初始化为1

  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of BlinkLED2 */
  osThreadDef(BlinkLED2, BlinkLED2_Task, osPriorityBelowNormal, 0, 128);
  BlinkLED2Handle = osThreadCreate(osThread(BlinkLED2), NULL);

  /* definition and creation of LVGL_TaskHandle */
  osThreadDef(LVGL_TaskHandle, LVGL_TaskHandler_Task, osPriorityNormal, 0, 2304);
  LVGL_TaskHandleHandle = osThreadCreate(osThread(LVGL_TaskHandle), NULL);

  /* definition and creation of FT6336_ScanTask */
  osThreadDef(FT6336_ScanTask, FT6336_Scan_Task, osPriorityAboveNormal, 0, 128);
  FT6336_ScanTaskHandle = osThreadCreate(osThread(FT6336_ScanTask), NULL);

  /* definition and creation of key_changemode */
  osThreadDef(key_changemode, key_change_mode, osPriorityIdle, 0, 128);
  key_changemodeHandle = osThreadCreate(osThread(key_changemode), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  USART1_Printf("%d : Run StartDefaultTask\r\n", osKernelSysTick());
  /* Infinite loop */
  for (;;)
  {
    osDelay(100);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_BlinkLED2_Task */
/**
 * @brief BlinkLED2线程，用于LED2闪烁.
 * @param argument: Not used
 * @note LED2闪烁
 * @retval None
 */
/* USER CODE END Header_BlinkLED2_Task */
void BlinkLED2_Task(void const * argument)
{
  /* USER CODE BEGIN BlinkLED2_Task */
  USART1_Printf("%d : Run BlinkLED2_Task\r\n", osKernelSysTick());
  /* Infinite loop */
  for (;;)
  {
    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin); // LED2电平翻转
    osDelay(500);
  }
  /* USER CODE END BlinkLED2_Task */
}

/* USER CODE BEGIN Header_LVGL_TaskHandler_Task */
/**
 * @brief Function implementing the LVGL_TaskHandle thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_LVGL_TaskHandler_Task */
void LVGL_TaskHandler_Task(void const * argument)
{
  /* USER CODE BEGIN LVGL_TaskHandler_Task */
  USART1_Printf("%d : Run LVGL_TaskHandler_Task\r\n", osKernelSysTick());
  lv_init(); // LVGL初始
  USART1_Printf("%d : lv_init() Finish\r\n", osKernelSysTick());
  lv_port_disp_init(); // LVGL显示初始
  USART1_Printf("%d : lv_port_disp_init() Finish\r\n", osKernelSysTick());
  LCD_Switch_Dir(0); // 旋转屏幕方向
  USART1_Printf("%d : LCD_Switch_Dir(0) Finish\r\n", osKernelSysTick());

  // LVGL自带示例程序
  lv_demo_widgets();
  //  lv_demo_stress();
  //  lv_demo_benchmark();
  //  lv_demo_music();

  USART1_Printf("%d : LCD ID:%d\r\n", osKernelSysTick(), LCD_Read_ID());

  /* Infinite loop */
  for (;;)
  {
    lv_task_handler(); // LVGL任务处理
    osDelay(5);        // 延时5ms
  }
  /* USER CODE END LVGL_TaskHandler_Task */
}

/* USER CODE BEGIN Header_FT6336_Scan_Task */
/**
 * @brief Function implementing the FT6336_ScanTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_FT6336_Scan_Task */
void FT6336_Scan_Task(void const * argument)
{
  /* USER CODE BEGIN FT6336_Scan_Task */
  lv_port_indev_init(); // LVGL输入设备初始
  USART1_Printf("%d : lv_port_indev_init() Finish\r\n", osKernelSysTick());
  /* Infinite loop */
  for (;;)
  {
    if (CTP_INT_Flag == 1)
    {
      tp_dev.scan(); // 扫描触摸
      CTP_INT_Flag = 0;
    }
    osDelay(10);
  }
  /* USER CODE END FT6336_Scan_Task */
}

/* USER CODE BEGIN Header_key_change_mode */
/**
* @brief Function implementing the key_changemode thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_key_change_mode */
void key_change_mode(void const * argument)
{
  /* USER CODE BEGIN key_change_mode */
	//按键切换工作模式
  /* Infinite loop */


  for(;;)
  {
		USART1_Printf("is_SHORT:%d\n",detect_short());

			for (int i = 0; i < 8; i++) 
			{
					for (int j = 0; j < 8; j++) 
					{
						if(short_matrix[i][j])
						{
							USART1_Printf("GPIO:%d,%d\n", i+1,j+1);
						}
					}
			}


		
//		uint8_t type = is_SFTP();
//		USART1_Printf("is_SFTP:%d\n",  read_gpio_level(GPIOC, RX_9_Pin));
			
//		USART1_Printf("is_SFTP:%d\n", type);
    osDelay(20);
  }
  /* USER CODE END key_change_mode */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
