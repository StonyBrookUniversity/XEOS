/*******************************************************************************
 * XEOS - x86 Experimental Operating System
 * 
 * Copyright (C) 2010 Jean-David Gadina (macmade@eosgarden.com)
 * All rights reserved
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  -   Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *  -   Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *  -   Neither the name of 'Jean-David Gadina' nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

#include <hal/hal.h>
#include "private/video.h"
#include "private/interrupts.h"
#include "system.h"

void kernel_main( void );
void kernel_main( void )
{
    kernel_video_set_fg( KERNEL_VIDEO_COLOR_WHITE );
    kernel_video_set_bg( KERNEL_VIDEO_COLOR_LIGHTBLUE );
    kernel_video_clear();
    
    hal_idt_init( 0x08, kernel_interrupt_default_handler );
    
    hal_idt_set_descriptor( HAL_INT_DIVIDE_ERROR,                   kernel_interrupt_divide_error,                   0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_DEBUG_EXCEPTION,                kernel_interrupt_debug_exception,                0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_NMI_INTERRUPT,                  kernel_interrupt_nmi_interrupt,                  0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_BREAKPOINT_EXCEPTION,           kernel_interrupt_breakpoint_exception,           0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_OVERFLOW_EXCEPTION,             kernel_interrupt_overflow_exception,             0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_BOUND_RANGE_EXCEEDED_EXCEPTION, kernel_interrupt_bound_range_exceeded_exception, 0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_INVALID_OPCODE_EXCEPTION,       kernel_interrupt_invalid_opcode_exception,       0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_DEVICE_NOT_AVAILABLE_EXCEPTION, kernel_interrupt_device_not_available_exception, 0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_DOUBLE_FAULT_EXCEPTION,         kernel_interrupt_double_fault_exception,         0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_COPROCESSOR_SEGMENT_OVERRUN,    kernel_interrupt_coprocessor_segment_overrun,    0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_INVALID_TSS_EXCEPTION,          kernel_interrupt_invalid_tss_exception,          0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_SEGMENT_NOT_PRESENT,            kernel_interrupt_segment_not_present,            0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_STACK_FAULT_EXCEPTION,          kernel_interrupt_stack_fault_exception,          0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_GENERAL_PROTECTION_EXCEPTION,   kernel_interrupt_general_protection_exception,   0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_PAGE_FAULT_EXCEPTION,           kernel_interrupt_page_fault_exception,           0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_FLOATING_POINT_ERROR_EXCEPTION, kernel_interrupt_floating_point_error_exception, 0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_ALIGNMENT_CHECK_EXCEPTION,      kernel_interrupt_alignment_check_exception,      0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_MACHINE_CHECK_EXCEPTION,        kernel_interrupt_machine_check_exception,        0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    hal_idt_set_descriptor( HAL_INT_SIMD_FLOATING_POINT_EXCEPTION,  kernel_interrupt_simd_floating_point_exception,  0x08, HAL_IDT_FLAG_PRESENT | HAL_IDT_FLAG_32BITS );
    
    for( ; ; );
}

