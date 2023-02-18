CC  := gcc
CFLAGS  := -g -O0 -I. $(CCFLAGS) -std=c99 # intset.c:323:5: 错误：只允许在 C99 模式下使用‘for’循环初始化声明
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

intset.o: intset.c intset.h
	$(CC) $(CFLAGS) -c intset.c

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
