CC  := gcc
CFLAGS  := -g -O0 -I. $(CCFLAGS) -O0 -std=c89
SRCS    := $(wildcard *.c) # 当前目录下的所有的.c文件 
OBJS    := $(SRCS:.c=.o) # 将所有的.c文件名替换为.o
REDISLIB 	:= libredis.a

all:$(REDISLIB) gccr

# ***************************************************************
# C compilations
zmalloc.o: zmalloc.c zmalloc.h
	$(CC) $(CFLAGS) -c zmalloc.c

adlist.o: adlist.c adlist.h
	$(CC) $(CFLAGS) -c adlist.c

$(REDISLIB):$(OBJS)
	-rm -f $(REDISLIB)
	ar cr $(REDISLIB) $(OBJS)
	ranlib $(REDISLIB)

# ***************************************************************
# Entry to reconstruct the gccr script

gccr: makefile
	@echo '#!/bin/bash' > gccr
	@echo 'INCLUDE='\"`pwd`\" >> gccr
	@echo 'REDISLIB="$$INCLUDE/libredis.a"' >> gccr
	@echo 'LIBRARIES="$$REDISLIB"' >> gccr
	@echo 'gcc -g -I$$INCLUDE $$* $$LIBRARIES' >> gccr
	@chmod a+x gccr
	@echo '[gccr script created]'

clean:
	rm -f *.o
	rm -f $(BINS)
	rm -f $(REDISLIB)
	rm -f gccr
