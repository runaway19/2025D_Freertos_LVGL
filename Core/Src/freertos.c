/* USER CODE BEGIN Header */

/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "my_fun.h"
#include "my_lvgl.h"
#include "my_board.h"
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
extern uint8_t start_mode;
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
osThreadId LVGL_TaskHandleHandle;
osThreadId LCD_ScanTaskHandle;
osThreadId CHANGE_LVGLHandle;
osMutexId lvgl_mutexHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void LVGL_TaskHandler_Task(void const * argument);
void LCD_Scan_Task(void const * argument);
void CHANGE_LVGL_TASK(void const * argument);

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
  /* Create the mutex(es) */
  /* definition and creation of lvgl_mutex */
  osMutexDef(lvgl_mutex);
  lvgl_mutexHandle = osMutexCreate(osMutex(lvgl_mutex));

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

  /* definition and creation of LVGL_TaskHandle */
  osThreadDef(LVGL_TaskHandle, LVGL_TaskHandler_Task, osPriorityNormal, 0, 2304);
  LVGL_TaskHandleHandle = osThreadCreate(osThread(LVGL_TaskHandle), NULL);

  /* definition and creation of LCD_ScanTask */
  osThreadDef(LCD_ScanTask, LCD_Scan_Task, osPriorityAboveNormal, 0, 128);
  LCD_ScanTaskHandle = osThreadCreate(osThread(LCD_ScanTask), NULL);

  /* definition and creation of CHANGE_LVGL */
  osThreadDef(CHANGE_LVGL, CHANGE_LVGL_TASK, osPriorityHigh, 0, 1024);
  CHANGE_LVGLHandle = osThreadCreate(osThread(CHANGE_LVGL), NULL);

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

	//LVGL初始
	init_lvgl();
	
  /* Infinite loop */
  for (;;)
  {
		//添加互斥
		if (osMutexWait(lvgl_mutexHandle, osWaitForever) == osOK) 
    {
      lv_task_handler(); 
      osMutexRelease(lvgl_mutexHandle); 
    }
    osDelay(5);        // 延时5ms
  }
  /* USER CODE END LVGL_TaskHandler_Task */
}

/* USER CODE BEGIN Header_LCD_Scan_Task */
/**
* @brief Function implementing the LCD_ScanTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LCD_Scan_Task */
void LCD_Scan_Task(void const * argument)
{
  /* USER CODE BEGIN LCD_Scan_Task */
	lv_port_indev_init(); // LVGL输入设备初始
  USART1_Printf("%d : lv_port_indev_init() Finish\r\n", osKernelSysTick());
  /* Infinite loop */
  for(;;)
  {    
		if (CTP_INT_Flag == 1)
    {
      tp_dev.scan(); // 扫描触摸
      CTP_INT_Flag = 0;
    }
    osDelay(10);
  }
  /* USER CODE END LCD_Scan_Task */
}

/* USER CODE BEGIN Header_CHANGE_LVGL_TASK */
/**
* @brief Function implementing the CHANGE_LVGL thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CHANGE_LVGL_TASK */
void CHANGE_LVGL_TASK(void const * argument)
{
  /* USER CODE BEGIN CHANGE_LVGL_TASK */
  /* Infinite loop */
  for(;;)
  {
		//添加互斥
		if (osMutexWait(lvgl_mutexHandle, osWaitForever) == osOK) 
    {
				if(start_mode == 1)
				{
					change_label_mode_one();
				}
				if(start_mode == 2)
				{
					change_label_mode_two();
				}
        osMutexRelease(lvgl_mutexHandle);
    }
    osDelay(500);
  }
  /* USER CODE END CHANGE_LVGL_TASK */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
