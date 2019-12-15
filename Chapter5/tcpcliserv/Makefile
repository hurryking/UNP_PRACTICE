include ../../Make.defines

PROGS =	tcpserv01 tcpserv02

all:	${PROGS}

tcpserv01:	tcpserv01.o
		${CC} ${CFLAGS} -o $@ tcpserv01.o ../${LIBS}

tcpserv02:	tcpserv02.o sigchildwait.o
		${CC} ${CFLAGS} -o $@ tcpserv02.o sigchildwait.o ../${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
