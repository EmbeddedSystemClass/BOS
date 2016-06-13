/**
  ******************************************************************************
  * @file    BOS_eeprom.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    29-May-2012
  * @brief   This file contains all the functions prototypes for the EEPROM 
  *          emulation firmware library.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 
/*
		MODIFIED by Hexabitz for BitzOS (BOS) V0.0.0 - Copyright (C) 2016 Hexabitz
    All rights reserved
*/
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BOS_EEPROM_H
#define __BOS_EEPROM_H

/* Includes ------------------------------------------------------------------*/
#include "BOS.h"

/* Exported constants --------------------------------------------------------*/
/* Define the size of the sectors to be used */
#define PAGE_SIZE             ((uint32_t)0x0800)  /* Page size = 2KByte for STM32F07x 
																												and STM32F09x devices = 512 variables */
																												
/* EEPROM start address in Flash */
#define EEPROM_START_ADDRESS  ((uint32_t)0x08019000) /* EEPROM emulation start address:
                                                        from sector2, after 100KByte of used 
                                                        Flash memory */

/* Pages 0 and 1 base and end addresses */
#define PAGE0_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + 0x0000))
#define PAGE0_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (PAGE_SIZE - 1)))

#define PAGE1_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + 0x0800))
#define PAGE1_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (2 * PAGE_SIZE - 1)))

/* Used Flash pages for EEPROM emulation */
#define PAGE0                 ((uint16_t)0x0000)
#define PAGE1                 ((uint16_t)0x0001)

/* No valid page define */
#define NO_VALID_PAGE         ((uint16_t)0x00AB)

/* Page status definitions */
#define ERASED                ((uint16_t)0xFFFF)     /* Page is empty */
#define RECEIVE_DATA          ((uint16_t)0xEEEE)     /* Page is marked to receive data */
#define VALID_PAGE            ((uint16_t)0x0000)     /* Page containing valid data */

/* Valid pages in read and write defines */
#define READ_FROM_VALID_PAGE  ((uint8_t)0x00)
#define WRITE_IN_VALID_PAGE   ((uint8_t)0x01)

/* Page full define */
#define PAGE_FULL             ((uint8_t)0x80)

/* EEPROM Variables' number (up to 512 16-bit variables) */ 
#define NumOfEEPROMvar        512				

/* Exported variables --------------------------------------------------------*/
extern uint16_t VirtAddVarTab[NumOfEEPROMvar+1];

/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint16_t EE_Init(void);
uint16_t EE_ReadVariable(uint16_t VirtAddress, uint16_t* Data);
uint16_t EE_WriteVariable(uint16_t VirtAddress, uint16_t Data);
uint16_t Flash_WriteVariable(uint32_t Address, uint16_t Data);


#endif /* __BOS_EEPROM_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/