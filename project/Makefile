# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AS		= $(CC)


all: main.elf


#additional rules for files

main.elf: ${COMMON_OBJECTS} main.o stateMachine.o led.o buzzer.o switches.o wdInterruptHandler.o p2_interrupt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf

led.c: led.h stateMachine.h
buzzer.c: buzzer.h
switches.c: switches.h buzzer.h led.h

wdInterruptHandler.c: stateMachine.h led.h switches.h buzzer.h

stateMachine.c: led.h stateMachine.h switches.h

main.c: led.h buzzer.h switches.h
