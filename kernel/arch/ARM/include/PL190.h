#ifndef __EP9302_VIC_H
#define __EP9302_VIC_H

#define IRQ_COMMRX				2
#define IRQ_COMMTX				3
#define IRQ_TIMER1				4

#define IRQ_TIMER2				5
#define IRQ_AACINTR				6
#define IRQ_DMAM2P0				7
#define IRQ_DMAM2P1				8
#define IRQ_DMAM2P2				9

#define IRQ_DMAM2P3				10
#define IRQ_DMAM2P4				11
#define IRQ_DMAM2P5				12
#define IRQ_DMAM2P6				13
#define IRQ_DMAM2P7				14

#define IRQ_DMAM2P8				15
#define IRQ_DMAM2P9				16
#define IRQ_DMAM2M0				17
#define IRQ_DMAM2M1				18
#define IRQ_GPIO0MUX			19

#define IRQ_GPIO1MUX			20
#define IRQ_GPIO2MUX			21
#define IRQ_GPIO3MUX			22
#define IRQ_UART1RX				23
#define IRQ_UART1TX				24

#define IRQ_UART2RX				25
#define IRQ_UART2TX				26
#define IRQ_UART3RX				27
#define IRQ_UART3TX				28
#define IRQ_KEY					29

#define IRQ_TOUCH				30
#define VIC1_VALID_IRQ_MASK		0x7ffffffc
#define IRQ_EXT0				32
#define IRQ_EXT1				33

#define IRQ_EXT2				34
#define IRQ_64HZ				35
#define IRQ_WATCHDOG			36
#define IRQ_RTC					37
#define IRQ_IRDA				38

#define IRQ_ETHERNET			39
#define IRQ_EXT3				40
#define IRQ_PROG				41
#define IRQ_1HZ					42
#define IRQ_VSYNC				43

#define IRQ_VIDEO_FIFO			44
#define IRQ_SSP1RX				45
#define IRQ_SSP1TX				46
#define IRQ_GPIO4MUX			47
#define IRQ_GPIO5MUX			48

#define IRQ_GPIO6MUX			49
#define IRQ_GPIO7MUX			50
#define IRQ_TIMER3				51
#define IRQ_UART1				52
#define IRQ_SSP					53

#define IRQ_UART2				54
#define IRQ_UART3				55
#define IRQ_USB					56

#define IRQ_ETHERNET_PME		57
#define IRQ_DSP					58
	
#define IRQ_GPIO_AB				59
#define IRQ_SAI					60
#define VIC2_VALID_IRQ_MASK		0x1fffffff

#define IRQ_GPIO(x)				(64 + (((x) + (((x) >> 2) & 8)) & 0x1f))

#define NR_IRQS					(64 + 24)
#define BOARD_IRQ(x)			(NR_IRQS + (x))
#define BOARD_IRQS				32

#define TOTAL_IRQS					(NR_IRQS + BOARD_IRQS)

#endif		/*EP9302_VIC_H*/

