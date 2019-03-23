include ../Make.defines

PROGS = daytimetcpcli daytimetcpsrv daytimetcpsrv1 daytimetcpcliv6 daytimetcpsrvv6 byteorder

all:${PROGS}

daytimetcpcli: daytimetcpcli.o
        ${CC} ${CFLAGS} -o $@ daytimetcpcli.o ${LIBS}

daytimetcpsrv: daytimetcpsrv.o
        ${CC} ${CFLAGS} -o $@ daytimetcpsrv.o ${LIBS}

daytimetcpsrv1: daytimetcpsrv1.o
        ${CC} ${CFLAGS} -o $@ daytimetcpsrv1.o ${LIBS}


daytimetcpcliv6: daytimetcpcliv6.o
        ${CC} ${CFLAGS} -o $@ daytimetcpcliv6.o ${LIBS}

daytimetcpsrvv6: daytimetcpsrvv6.o
        ${CC} ${CFLAGS} -o $@ daytimetcpsrvv6.o ${LIBS}

byteorder: byteorder.o
        ${CC} ${CFLAGS} -o $@ byteorder.o ${LIBS}

clean:
        rm -f ${PROGS} ${CLEANFILES}
