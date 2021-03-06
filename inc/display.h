/**
 * @file control.h
 * @author Shoma Gane <shomagan@gmail.com>
 *         Ayrat Girfanov <girfanov.ayrat@yandex.ru>
 * @defgroup inc
 * @ingroup inc
 * @version 0.1 
 * @brief  TODO!!! write brief in 
 */
/*
 * Copyright (c) 2018 Snema Service
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the sofi PLC.
 *
 * Author: Shoma Gane <shomagan@gmail.com>
 *         Ayrat Girfanov <girfanov.ayrat@yandex.ru>
 */
#ifndef DISPLAY_H
#define DISPLAY_H 1
 
/*add includes below */
#include "type_def.h"
#include "stm32f1xx_hal.h"
#include "fonts.h"
/*add includes before */
#ifdef __cplusplus 
   extern "C" {
#endif
/*add functions and variable declarations below */

typedef enum{
   SKIN_FULL = 0,
   SKIN_TIME,
   SKIN_TEMP,
}skin_t;
extern const char skin_descr[][20];

typedef struct {
    u8 x0;
    u8 y0;
    u8 x1;
    u8 y1;
}brick_t;

typedef enum {
    BRICK_NONE = 0,
    BRICK_FILL,
    BRICK_EMPTY,
}brick_state_t;

void display_task( const void *parameters);
void navigation_task( const void *parameters);
uint8_t align_text_center(char* string, FontDef_t font);
uint8_t align_text_right(char* string, FontDef_t font);
uint32_t uint32_pow(uint16_t x, uint8_t pow);
float float_pow(float x, int pow);
void restore_params(void);
int set_def_params(void);
#define DISPLAY_TASK_PERIOD 500
/*add functions and variable declarations before */
#ifdef __cplusplus
}
#endif
#endif //DISPLAY_H
