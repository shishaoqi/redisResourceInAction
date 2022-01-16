CC  := gcc
CFLAGS  := -g -I. $(CCFLAGS) -std=c99
SRCS    := $(wildcard *.c) # 当前目录下的所有的.c文件 
OBJS    := $(SRCS:.c=.o) # 将所有的.c文件名替换为.o
REDISLIB 	:= libredis.a

all:$(REDISLIB) gccr

# ***************************************************************
# C compilations
zmalloc.o: zmalloc.c zmalloc.h
	$(CC) $(CFLAGS) -c zmalloc.c

endianconv.o: endianconv.c endianconv.h  endianconv.c
	$(CC) $(CFLAGS) -c endianconv.c

redisassert.o: redisassert.c redisassert.h
	$(CC) $(CFLAGS) -c redisassert.c

sha256.o: sha256.c sha256.h
	$(CC) $(CFLAGS) -c sha256.c

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

sds.o: sds.c sds.h
	$(CC) $(CFLAGS) -c sds.c

ziplist.o: ziplist.c ziplist.h
	$(CC) $(CFLAGS) -c ziplist.c

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
