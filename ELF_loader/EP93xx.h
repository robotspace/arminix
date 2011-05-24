#ifndef REGS_H
#define REGS_H

/* AMBA bus mapping */
#define AHB_PHYS_BASE						0x80000000
#define AHB_SIZE							0x00100000

#define APB_PHYS_BASE						0x80800000
#define APB_SIZE							0x00200000

/* DMA controller */
#define DMA_BASE							(AHB_PHYS_BASE + 0x00000000)

/* Ethernet controller */
#define ETHERNET_BASE						(AHB_PHYS_BASE + 0x00010000)

/* USB controller */
#define USB_BASE							(AHB_PHYS_BASE + 0x00020000)

/* Raster engine */
#define RASTER_BASE							(AHB_PHYS_BASE + 0x00030000)

/* SDRAM controller */
#define SDRAM_CONTROLLER_BASE				(AHB_PHYS_BASE + 0x00060000)
#define SDRAM_GL_CONFIG						(*((volatile unsigned int *) (SDRAM_CONTROLLER_BASE + 0x04)))
#define SDRAM_REFRSH_TIMR					(*((volatile unsigned int *) (SDRAM_CONTROLLER_BASE + 0x08)))
#define SDRAM_BOOT_STS						(*((volatile unsigned int *) (SDRAM_CONTROLLER_BASE + 0x0C)))
#define SDRAM_DEV_CFG_1						(*((volatile unsigned int *) (SDRAM_CONTROLLER_BASE + 0x10)))
#define SDRAM_DEV_CFG_2						(*((volatile unsigned int *) (SDRAM_CONTROLLER_BASE + 0x14)))
#define SDRAM_DEV_CFG_3						(*((volatile unsigned int *) (SDRAM_CONTROLLER_BASE + 0x18)))
#define SDRAM_DEV_CFG_4						(*((volatile unsigned int *) (SDRAM_CONTROLLER_BASE + 0x1C)))

/* SMC and PCMCIA controller */
#define SMC_BASE							(AHB_PHYS_BASE + 0x00080000)

/* boot rom base */
#define BOOT_ROM_BASE						(AHB_PHYS_BASE + 0x00090000)

/* IDE controller */
#define IDE_BASE							(AHB_PHYS_BASE + 0x000a0000)

/* Vectored Interrupt Controller 1*/
#define VIC1_BASE							(AHB_PHYS_BASE + 0x000b0000)

#define VIC1IRQStatus						(*((volatile unsigned int *) VIC1_BASE))
#define VIC1FIQStatus						(*((volatile unsigned int *) (VIC1_BASE + 0x4)))
#define VIC1RawIntr							(*((volatile unsigned int *) (VIC1_BASE + 0x8)))
#define VIC1IntSelect						(*((volatile unsigned int *) (VIC1_BASE + 0xC)))
#define VIC1IntEnable						(*((volatile unsigned int *) (VIC1_BASE + 0x10)))
#define VIC1IntEnClear						(*((volatile unsigned int *) (VIC1_BASE + 0x14)))
#define VIC1SoftInt							(*((volatile unsigned int *) (VIC1_BASE + 0x18)))
#define VIC1SoftIntClear					(*((volatile unsigned int *) (VIC1_BASE + 0x1C)))
#define VIC1Protection						(*((volatile unsigned int *) (VIC1_BASE + 0x20)))
#define VIC1VectAddr						(*((volatile unsigned int *) (VIC1_BASE + 0x30)))
#define VIC1DefVectAddr						(*((volatile unsigned int *) (VIC1_BASE + 0x34)))

#define VIC1VectAddr0						(*((volatile unsigned int *) (VIC1_BASE+0x100)))
#define VIC1VectAddr1						(*((volatile unsigned int *) (VIC1_BASE+0x104)))
#define VIC1VectAddr2						(*((volatile unsigned int *) (VIC1_BASE+0x108)))
#define VIC1VectAddr3						(*((volatile unsigned int *) (VIC1_BASE+0x10C)))
#define VIC1VectAddr4						(*((volatile unsigned int *) (VIC1_BASE+0x110)))
#define VIC1VectAddr5						(*((volatile unsigned int *) (VIC1_BASE+0x114)))
#define VIC1VectAddr6						(*((volatile unsigned int *) (VIC1_BASE+0x118)))
#define VIC1VectAddr7						(*((volatile unsigned int *) (VIC1_BASE+0x11C)))
#define VIC1VectAddr8						(*((volatile unsigned int *) (VIC1_BASE+0x120)))
#define VIC1VectAddr9						(*((volatile unsigned int *) (VIC1_BASE+0x124)))
#define VIC1VectAddr10						(*((volatile unsigned int *) (VIC1_BASE+0x128)))
#define VIC1VectAddr11						(*((volatile unsigned int *) (VIC1_BASE+0x12C)))
#define VIC1VectAddr12						(*((volatile unsigned int *) (VIC1_BASE+0x130)))
#define VIC1VectAddr13						(*((volatile unsigned int *) (VIC1_BASE+0x134)))
#define VIC1VectAddr14						(*((volatile unsigned int *) (VIC1_BASE+0x138)))
#define VIC1VectAddr15						(*((volatile unsigned int *) (VIC1_BASE+0x13C)))

#define VIC1VectCntl0						(*((volatile unsigned int *) (VIC1_BASE+0x200)))
#define VIC1VectCntl1						(*((volatile unsigned int *) (VIC1_BASE+0x204)))
#define VIC1VectCntl2						(*((volatile unsigned int *) (VIC1_BASE+0x208)))
#define VIC1VectCntl3						(*((volatile unsigned int *) (VIC1_BASE+0x20C)))
#define VIC1VectCntl4						(*((volatile unsigned int *) (VIC1_BASE+0x210)))
#define VIC1VectCntl5						(*((volatile unsigned int *) (VIC1_BASE+0x214)))
#define VIC1VectCntl6						(*((volatile unsigned int *) (VIC1_BASE+0x218)))
#define VIC1VectCntl7						(*((volatile unsigned int *) (VIC1_BASE+0x21C)))
#define VIC1VectCntl8						(*((volatile unsigned int *) (VIC1_BASE+0x220)))
#define VIC1VectCntl9						(*((volatile unsigned int *) (VIC1_BASE+0x224)))
#define VIC1VectCntl10						(*((volatile unsigned int *) (VIC1_BASE+0x228)))
#define VIC1VectCntl11						(*((volatile unsigned int *) (VIC1_BASE+0x22C)))
#define VIC1VectCntl12						(*((volatile unsigned int *) (VIC1_BASE+0x230)))
#define VIC1VectCntl13						(*((volatile unsigned int *) (VIC1_BASE+0x234)))
#define VIC1VectCntl14						(*((volatile unsigned int *) (VIC1_BASE+0x238)))
#define VIC1VectCntl15						(*((volatile unsigned int *) (VIC1_BASE+0x23C)))

#define VIC1PeriphID0						(*((volatile unsigned int *) (VIC1_BASE+0xFE0)))
#define VIC1PeriphID1						(*((volatile unsigned int *) (VIC1_BASE+0xFE4)))
#define VIC1PeriphID2						(*((volatile unsigned int *) (VIC1_BASE+0xFE8)))
#define VIC1PeriphID3						(*((volatile unsigned int *) (VIC1_BASE+0xFEC)))

/* Vectored Interrupt Controller 2*/
#define VIC2_BASE							(AHB_PHYS_BASE + 0x000c0000)

#define VIC2IRQStatus						(*((volatile unsigned int *) VIC2_BASE))
#define VIC2FIQStatus						(*((volatile unsigned int *) (VIC2_BASE + 0x4)))
#define VIC2RawIntr							(*((volatile unsigned int *) (VIC2_BASE + 0x8)))
#define VIC2IntSelect						(*((volatile unsigned int *) (VIC2_BASE + 0xC)))
#define VIC2IntEnable						(*((volatile unsigned int *) (VIC2_BASE + 0x10)))
#define VIC2IntEnClear						(*((volatile unsigned int *) (VIC2_BASE + 0x14)))
#define VIC2SoftInt							(*((volatile unsigned int *) (VIC2_BASE + 0x18)))
#define VIC2SoftIntClear					(*((volatile unsigned int *) (VIC2_BASE + 0x1C)))
#define VIC2Protection						(*((volatile unsigned int *) (VIC2_BASE + 0x20)))
#define VIC2VectAddr						(*((volatile unsigned int *) (VIC2_BASE + 0x30)))
#define VIC2DefVectAddr						(*((volatile unsigned int *) (VIC2_BASE + 0x34)))

#define VIC2VectAddr0						(*((volatile unsigned int *) (VIC2_BASE+0x100)))
#define VIC2VectAddr1						(*((volatile unsigned int *) (VIC2_BASE+0x104)))
#define VIC2VectAddr2						(*((volatile unsigned int *) (VIC2_BASE+0x108)))
#define VIC2VectAddr3						(*((volatile unsigned int *) (VIC2_BASE+0x10C)))
#define VIC2VectAddr4						(*((volatile unsigned int *) (VIC2_BASE+0x110)))
#define VIC2VectAddr5						(*((volatile unsigned int *) (VIC2_BASE+0x114)))
#define VIC2VectAddr6						(*((volatile unsigned int *) (VIC2_BASE+0x118)))
#define VIC2VectAddr7						(*((volatile unsigned int *) (VIC2_BASE+0x11C)))
#define VIC2VectAddr8						(*((volatile unsigned int *) (VIC2_BASE+0x120)))
#define VIC2VectAddr9						(*((volatile unsigned int *) (VIC2_BASE+0x124)))
#define VIC2VectAddr10						(*((volatile unsigned int *) (VIC2_BASE+0x128)))
#define VIC2VectAddr11						(*((volatile unsigned int *) (VIC2_BASE+0x12C)))
#define VIC2VectAddr12						(*((volatile unsigned int *) (VIC2_BASE+0x130)))
#define VIC2VectAddr13						(*((volatile unsigned int *) (VIC2_BASE+0x134)))
#define VIC2VectAddr14						(*((volatile unsigned int *) (VIC2_BASE+0x138)))
#define VIC2VectAddr15						(*((volatile unsigned int *) (VIC2_BASE+0x13C)))

#define VIC2VectCntl0						(*((volatile unsigned int *) (VIC2_BASE+0x200)))
#define VIC2VectCntl1						(*((volatile unsigned int *) (VIC2_BASE+0x204)))
#define VIC2VectCntl2						(*((volatile unsigned int *) (VIC2_BASE+0x208)))
#define VIC2VectCntl3						(*((volatile unsigned int *) (VIC2_BASE+0x20C)))
#define VIC2VectCntl4						(*((volatile unsigned int *) (VIC2_BASE+0x210)))
#define VIC2VectCntl5						(*((volatile unsigned int *) (VIC2_BASE+0x214)))
#define VIC2VectCntl6						(*((volatile unsigned int *) (VIC2_BASE+0x218)))
#define VIC2VectCntl7						(*((volatile unsigned int *) (VIC2_BASE+0x21C)))
#define VIC2VectCntl8						(*((volatile unsigned int *) (VIC2_BASE+0x220)))
#define VIC2VectCntl9						(*((volatile unsigned int *) (VIC2_BASE+0x224)))
#define VIC2VectCntl10						(*((volatile unsigned int *) (VIC2_BASE+0x228)))
#define VIC2VectCntl11						(*((volatile unsigned int *) (VIC2_BASE+0x22C)))
#define VIC2VectCntl12						(*((volatile unsigned int *) (VIC2_BASE+0x230)))
#define VIC2VectCntl13						(*((volatile unsigned int *) (VIC2_BASE+0x234)))
#define VIC2VectCntl14						(*((volatile unsigned int *) (VIC2_BASE+0x238)))
#define VIC2VectCntl15						(*((volatile unsigned int *) (VIC2_BASE+0x23C)))

#define VIC2PeriphID0						(*((volatile unsigned int *) (VIC2_BASE+0xFE0)))
#define VIC2PeriphID1						(*((volatile unsigned int *) (VIC2_BASE+0xFE4)))
#define VIC2PeriphID2						(*((volatile unsigned int *) (VIC2_BASE+0xFE8)))
#define VIC2PeriphID3						(*((volatile unsigned int *) (VIC2_BASE+0xFEC)))

/* Timers */
#define TIMER_BASE							(APB_PHYS_BASE + 0x00010000)
#define TIMER1_LOAD							(*((volatile unsigned int *) (TIMER_BASE + (0x00))))
#define TIMER1_VALUE						(*((volatile unsigned int *) (TIMER_BASE + (0x04))))
#define TIMER1_CONTROL						(*((volatile unsigned int *) (TIMER_BASE + (0x08))))
#define TIMER1_CLEAR						(*((volatile unsigned int *) (TIMER_BASE + (0x0c))))
#define TIMER2_LOAD							(*((volatile unsigned int *) (TIMER_BASE + (0x20))))
#define TIMER2_VALUE						(*((volatile unsigned int *) (TIMER_BASE + (0x24))))
#define TIMER2_CONTROL						(*((volatile unsigned int *) (TIMER_BASE + (0x28))))
#define TIMER2_CLEAR						(*((volatile unsigned int *) (TIMER_BASE + (0x2c))))
#define TIMER3_LOAD							(*((volatile unsigned int *) (TIMER_BASE + (0x80))))
#define TIMER3_VALUE						(*((volatile unsigned int *) (TIMER_BASE + (0x84))))
#define TIMER3_CONTROL						(*((volatile unsigned int *) (TIMER_BASE + (0x88))))
#define TIMER3_CLEAR						(*((volatile unsigned int *) (TIMER_BASE + (0x8c))))
#define TIMER4_VALUE_LOW					(*((volatile unsigned int *) (TIMER_BASE + (0x60))))
#define TIMER4_VALUE_HIGH					(*((volatile unsigned int *) (TIMER_BASE + (0x64))))

/* I2S controller */
#define I2S_BASE							(APB_PHYS_BASE + 0x00020000)

/* Security */
#define	SECURITY_BASE						(APB_PHYS_BASE + 0x00030000)

/* GPIO */
#define GPIO_BASE							(APB_PHYS_BASE + 0x00040000)
#define	GPIO_PADR							(*((volatile unsigned int *) (GPIO_BASE)))
#define	GPIO_PBDR							(*((volatile unsigned int *) (GPIO_BASE + (0x04))))
#define	GPIO_PCDR							(*((volatile unsigned int *) (GPIO_BASE + (0x08))))
#define	GPIO_PDDR							(*((volatile unsigned int *) (GPIO_BASE + (0x0C))))
#define	GPIO_PEDR							(*((volatile unsigned int *) (GPIO_BASE + (0x20))))
#define	GPIO_PFDR							(*((volatile unsigned int *) (GPIO_BASE + (0x30))))
#define	GPIO_PGDR							(*((volatile unsigned int *) (GPIO_BASE + (0x38))))
#define	GPIO_PHDR							(*((volatile unsigned int *) (GPIO_BASE + (0x40))))

#define	GPIO_PADDR							(*((volatile unsigned int *) (GPIO_BASE + (0x10))))
#define	GPIO_PBDDR							(*((volatile unsigned int *) (GPIO_BASE + (0x14))))
#define	GPIO_PCDDR							(*((volatile unsigned int *) (GPIO_BASE + (0x18))))
#define	GPIO_PDDDR							(*((volatile unsigned int *) (GPIO_BASE + (0x1C))))
#define	GPIO_PEDDR							(*((volatile unsigned int *) (GPIO_BASE + (0x24))))
#define	GPIO_PFDDR							(*((volatile unsigned int *) (GPIO_BASE + (0x34))))
#define	GPIO_PGDDR							(*((volatile unsigned int *) (GPIO_BASE + (0x3C))))
#define	GPIO_PHDDR							(*((volatile unsigned int *) (GPIO_BASE + (0x44))))

#define GPIO_F_INT_TYPE1					(*((volatile unsigned int *) (GPIO_BASE + (0x4c))))
#define GPIO_F_INT_TYPE2					(*((volatile unsigned int *) (GPIO_BASE + (0x50))))
#define GPIO_F_INT_ACK						(*((volatile unsigned int *) (GPIO_BASE + (0x54))))
#define GPIO_F_INT_ENABLE					(*((volatile unsigned int *) (GPIO_BASE + (0x58))))
#define GPIO_F_INT_STATUS					(*((volatile unsigned int *) (GPIO_BASE + (0x5c))))
#define GPIO_F_INT_RAW_STATUS				(*((volatile unsigned int *) (GPIO_BASE + (0x60))))
#define GPIO_F_DEBOUNCE						(*((volatile unsigned int *) (GPIO_BASE + (0x64))))

#define GPIO_A_INT_TYPE1					(*((volatile unsigned int *) (GPIO_BASE + (0x90))))
#define GPIO_A_INT_TYPE2					(*((volatile unsigned int *) (GPIO_BASE + (0x94))))
#define GPIO_A_INT_ACK						(*((volatile unsigned int *) (GPIO_BASE + (0x98))))
#define GPIO_A_INT_ENABLE					(*((volatile unsigned int *) (GPIO_BASE + (0x9c))))
#define GPIO_A_INT_STATUS					(*((volatile unsigned int *) (GPIO_BASE + (0xa0))))
#define GPIO_A_INT_RAW_STATUS				(*((volatile unsigned int *) (GPIO_BASE + (0xa4))))
#define GPIO_A_DEBOUNCE						(*((volatile unsigned int *) (GPIO_BASE + (0xa8))))

#define GPIO_B_INT_TYPE1					(*((volatile unsigned int *) (GPIO_BASE + (0xac))))
#define GPIO_B_INT_TYPE2					(*((volatile unsigned int *) (GPIO_BASE + (0xb0))))
#define GPIO_B_INT_ACK						(*((volatile unsigned int *) (GPIO_BASE + (0xb4))))
#define GPIO_B_INT_ENABLE					(*((volatile unsigned int *) (GPIO_BASE + (0xb8))))
#define GPIO_B_INT_STATUS					(*((volatile unsigned int *) (GPIO_BASE + (0xbc))))
#define GPIO_B_INT_RAW_STATUS				(*((volatile unsigned int *) (GPIO_BASE + (0xc0))))
#define GPIO_B_DEBOUNCE						(*((volatile unsigned int *) (GPIO_BASE + (0xc4))))

#define GPIO_EE_DRIVE						(*((volatile unsigned int *) (GPIO_BASE + (0xc8))))

/* AC97 controller */
#define AC97_BASE							(APB_PHYS_BASE + 0x00080000)

/* SPI controller */
#define SPI_BASE							(APB_PHYS_BASE + 0x000a0000)

/* IRDA controller */
#define IRDA_BASE							(APB_PHYS_BASE + 0x000b0000)

/* UART1 controller*/
#define UART1_BASE							(APB_PHYS_BASE + 0x000c0000)

#define	UART1_DATA							(*((volatile unsigned int *) (UART1_BASE)))
#define	UART1_RX_STS						(*((volatile unsigned int *) (UART1_BASE + (0x004))))
#define	UART1_LINCTRLHIGH					(*((volatile unsigned int *) (UART1_BASE + (0x008))))
#define	UART1_LINCTRLMID					(*((volatile unsigned int *) (UART1_BASE + (0x00C))))
#define	UART1_LINCTRLLOW					(*((volatile unsigned int *) (UART1_BASE + (0x010))))
#define	UART1_CTRL							(*((volatile unsigned int *) (UART1_BASE + (0x014))))
#define	UART1_FLAG							(*((volatile unsigned int *) (UART1_BASE + (0x018))))
#define	UART1_INTID_INTCLR					(*((volatile unsigned int *) (UART1_BASE + (0x01C))))
#define	UART1_DMA_CTRL						(*((volatile unsigned int *) (UART1_BASE + (0x028))))
#define	UART1_MODEM_CTRL					(*((volatile unsigned int *) (UART1_BASE + (0x100))))
#define	UART1_MODEM_STS						(*((volatile unsigned int *) (UART1_BASE + (0x104))))
#define	UART1_HDLC_CTRL						(*((volatile unsigned int *) (UART1_BASE + (0x20C))))
#define	UART1_HDLC_ADD_MTCH_VAL				(*((volatile unsigned int *) (UART1_BASE + (0x210))))
#define	UART1_HDLC_ADD_MASK					(*((volatile unsigned int *) (UART1_BASE + (0x214))))
#define	UART1_HDLC_RX_INFO_BUF				(*((volatile unsigned int *) (UART1_BASE + (0x218))))
#define	UART1_HDLC_STS						(*((volatile unsigned int *) (UART1_BASE + (0x21C))))

/* UART2 controller*/
#define UART2_BASE							(APB_PHYS_BASE + 0x000d0000)

#define	UART2_DATA							(*((volatile unsigned int *) (UART2_BASE)))
#define	UART2_RX_STS						(*((volatile unsigned int *) (UART2_BASE + (0x004))))
#define	UART2_LINCTRLHIGH					(*((volatile unsigned int *) (UART2_BASE + (0x008))))
#define	UART2_LINCTRLMID					(*((volatile unsigned int *) (UART2_BASE + (0x00C))))
#define	UART2_LINCTRLLOW					(*((volatile unsigned int *) (UART2_BASE + (0x010))))
#define	UART2_CTRL							(*((volatile unsigned int *) (UART2_BASE + (0x014))))
#define	UART2_FLAG							(*((volatile unsigned int *) (UART2_BASE + (0x018))))
#define	UART2_INTID_INTCLR					(*((volatile unsigned int *) (UART2_BASE + (0x01C))))
#define	UART2_IR_LOW_PWR_CNTR				(*((volatile unsigned int *) (UART1_BASE + (0x020))))
#define	UART2_DMA_CTRL						(*((volatile unsigned int *) (UART2_BASE + (0x028))))
#define	UART2_TMR							(*((volatile unsigned int *) (UART2_BASE + (0x084))))

/* UART3 controller*/
#define UART3_BASE							(APB_PHYS_BASE + 0x000e0000)

#define	UART3_DATA							(*((volatile unsigned int *) (UART3_BASE)))
#define	UART3_RX_STS						(*((volatile unsigned int *) (UART3_BASE + (0x004))))
#define	UART3_LINCTRLHIGH					(*((volatile unsigned int *) (UART3_BASE + (0x008))))
#define	UART3_LINCTRLMID					(*((volatile unsigned int *) (UART3_BASE + (0x00C))))
#define	UART3_LINCTRLLOW					(*((volatile unsigned int *) (UART3_BASE + (0x010))))
#define	UART3_CTRL							(*((volatile unsigned int *) (UART3_BASE + (0x014))))
#define	UART3_FLAG							(*((volatile unsigned int *) (UART3_BASE + (0x018))))
#define	UART3_INTID_INTCLR					(*((volatile unsigned int *) (UART3_BASE + (0x01C))))
#define	UART3_LOW_PWR_CNTR					(*((volatile unsigned int *) (UART3_BASE + (0x020))))
#define	UART3_DMA_CTRL						(*((volatile unsigned int *) (UART3_BASE + (0x028))))
#define	UART3_MODEM_CTRL					(*((volatile unsigned int *) (UART3_BASE + (0x100))))
#define	UART3_HDLC_CTRL						(*((volatile unsigned int *) (UART3_BASE + (0x20C))))
#define	UART3_HDLC_ADD_MTCH_VAL				(*((volatile unsigned int *) (UART3_BASE + (0x210))))
#define	UART3_HDLC_ADD_MASK					(*((volatile unsigned int *) (UART3_BASE + (0x214))))
#define	UART3_HDLC_RX_INFO_BUF				(*((volatile unsigned int *) (UART3_BASE + (0x218))))
#define	UART3_HDLC_STS						(*((volatile unsigned int *) (UART3_BASE + (0x21C))))

/* Key matrix controller */
#define KEY_MATRIX_BASE						(APB_PHYS_BASE + 0x000f0000)

/* ADC (same as touchscreen controller */
#define ADC_BASE							(APB_PHYS_BASE + 0x00100000)

/* Touchscreen controller */
#define TOUCHSCREEN_BASE					(APB_PHYS_BASE + 0x00100000)

/* PWM controller */
#define PWM_BASE							(APB_PHYS_BASE + 0x00110000)

/* Real Time Clock */
#define RTC_BASE							(APB_PHYS_BASE + 0x00120000)
#define	RTC_DATA							(*((volatile unsigned int *) (RTC_BASE)))
#define	RTC_MATCH							(*((volatile unsigned int *) (RTC_BASE + (0x04))))
#define	RTC_STS								(*((volatile unsigned int *) (RTC_BASE + (0x08))))
#define	RTC_LOAD							(*((volatile unsigned int *) (RTC_BASE + (0x0C))))
#define	RTC_CTRL							(*((volatile unsigned int *) (RTC_BASE + (0x10))))
#define	RTC_SW_COMP							(*((volatile unsigned int *) (RTC_BASE + (0x98))))

/* System Controller */
#define SYSCON_BASE							(APB_PHYS_BASE + 0x00130000)
#define SYSCON_POWER_STATE					(*((volatile unsigned int *) (SYSCON_BASE)))
#define SYSCON_CLOCK_CONTROL				(*((volatile unsigned int *) (SYSCON_BASE + (0x04))))
#define SYSCON_HALT							(*((volatile unsigned int *) (SYSCON_BASE + (0x08))))
#define SYSCON_STANDBY						(*((volatile unsigned int *) (SYSCON_BASE + (0x0c))))
#define	SYSTEM_TICK_INT_ACK					(*((volatile unsigned int *) (SYSCON_BASE + (0x18))))
#define SYSCON_CLOCK_SET1					(*((volatile unsigned int *) (SYSCON_BASE + (0x20))))
#define SYSCON_CLOCK_SET2					(*((volatile unsigned int *) (SYSCON_BASE + (0x24))))
#define SYSCON_SCRATCHREG0					(*((volatile unsigned int *) (SYSCON_BASE + (0x40))))
#define SYSCON_SCRATCHREG1					(*((volatile unsigned int *) (SYSCON_BASE + (0x44))))
#define SYSCON_DEVICE_CONFIG				(*((volatile unsigned int *) (SYSCON_BASE + (0x80))))
#define SYSCON_SWLOCK						(*((volatile unsigned int *) (SYSCON_BASE + (0xc0))))
#define SYSCON_CHIP_ID						(*((volatile unsigned int *) (SYSCON_BASE + (0x94))))

/* Watch Dog Timer */
#define WATCHDOG_BASE						(APB_PHYS_BASE + 0x00140000)
#define WATCHDOG_CTRL						(*((volatile unsigned int *) (WATCHDOG_BASE)))
#define WATCHDOG_STATUS						(*((volatile unsigned int *) (WATCHDOG_BASE + (0x04))))

#endif	/*REGS_H*/
