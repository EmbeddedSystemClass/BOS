/*
    BitzOS (BOS) V0.1.4 - Copyright (C) 2018 Hexabitz
    All rights reserved
		
    File Name     : BOS_dma.h
    Description   : Header file for for BOS communication/backend DMAs. 
*/
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BOS_DMA_H
#define BOS_DMA_H


/* Includes ------------------------------------------------------------------*/
#include "BOS.h"


/* External definitions -------------------------------------------------------*/
#define MSG_DMA_PRIORITY 					DMA_PRIORITY_HIGH					// Messaging backend priority
#define STREAM_DMA_PRIORITY 			DMA_PRIORITY_MEDIUM
#define FRONTEND_DMA_PRIORITY 		DMA_PRIORITY_LOW


/* External variables ---------------------------------------------------------*/

extern UART_HandleTypeDef* dmaStreamDst[6];
extern uint32_t dmaStreamCount[6];
extern uint32_t dmaStreamTotal[6];

/* External functions ---------------------------------------------------------*/
extern void SwitchMsgDMAToStream(uint8_t port);
extern void SwitchStreamDMAToMsg(uint8_t port);
extern BOS_Status StartDMAstream(UART_HandleTypeDef* huartSrc, UART_HandleTypeDef* huartDst, uint8_t num);




#endif /* BOS_DMA_H */

/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/
