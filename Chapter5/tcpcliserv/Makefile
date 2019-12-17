include ../../Make.defines

PROGS =	tcpserv01 tcpserv02 tcpserv03 \
		tcpcli01 tcpcli03 tcpcli04

LIBPATH = ../${LIBS}

all:	${PROGS}

tcpserv01:	tcpserv01.o
		${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBPATH}

tcpserv02:	tcpserv02.o sigchildwait.o
		${CC} ${CFLAGS} -o $@ tcpserv02.o sigchildwait.o ${LIBPATH}

tcpserv03:	tcpserv03.o sigchildwait.o
		${CC} ${CFLAGS} -o $@ tcpserv03.o sigchildwait.o ${LIBPATH}

tcpserv08:	tcpserv08.o str_echo08.o sigchildwait.o
		${CC} ${CFLAGS} -o $@ tcpserv08.o str_echo08.o sigchildwait.o \
			${LIBPATH}

tcpserv09:	tcpserv09.o str_echo09.o sigchildwait.o
		${CC} ${CFLAGS} -o $@ tcpserv09.o str_echo09.o sigchildwait.o \
			${LIBPATH}

tcpcli01: tcpcli01.o
		${CC} ${CFLAGS} -o $@ tcpcli01.o ${LIBPATH}

tcpcli03: tcpcli03.o str_cli11.o
		${CC} ${CFLAGS} -o $@ tcpcli03.o str_cli11.o ${LIBPATH}

tcpcli04: tcpcli04.o
		${CC} ${CFLAGS} -o $@ tcpcli04.o ${LIBPATH}

tcpcli05: tcpcli05.o str_cli09.o
		${CC} ${CFLAGS} -o $@ tcpcli05.o str_cli09.o ${LIBPATH}

clean:
		rm -f ${PROGS} ${CLEANFILES}
