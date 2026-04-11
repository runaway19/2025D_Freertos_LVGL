#ifndef __FLASH_H__
#define __FLASH_H__

#include "main.h"

#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* 32 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08008000) /* 32 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08010000) /* 32 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x08018000) /* 32 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08020000) /* 128 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08040000) /* 256 Kbytes */

/*准备写入的测试数据*/
#define DATA_32                 ((uint32_t)0x87645321)

/* Exported types -----------------------------------------------------*/
/* Exported constants -------------------------------------------------*/
/* 要擦除内部FLASH的起始地址 */
#define FLASH_USER_START_ADDR   ADDR_FLASH_SECTOR_5
/* 要擦除内部FLASH的结束地址 */
#define FLASH_USER_END_ADDR     ADDR_FLASH_SECTOR_5

int InternalFlash_Test(void);

#endif
