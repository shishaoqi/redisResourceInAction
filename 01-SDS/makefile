CC  := gcc
CFLAGS  := -w -std=gnu99 -ggdb -ffunction-sections 
LFLAGS  := -lpthread
SRCS    := $(wildcard *.c) # 当前目录下的所有的.c文件 
OBJS    := $(SRCS:.c=.o) # 将所有的.c文件名替换为.o
REDISLIB    := libredis.a

all:$(REDISLIB) gccr


# ***************************************************************
# C compilations

sds.o: sds.c sds.h makefile
	$(CC) $(CFLAGS) -c sds.c

zmalloc.o: zmalloc.c zmalloc.h makefile
	$(CC) $(CFLAGS) -c zmalloc.c

$(REDISLIB):$(OBJS)
	-rm -f $(REDISLIB)
	ar cr $(REDISLIB) $(OBJS)
	ranlib $(REDISLIB)

# ***************************************************************
# Entry to reconstruct the gccr script

gccr: makefile
	@echo '#! /bin/csh -f' > gccr
	@echo 'set INCLUDE =' `pwd` >> gccr
	@echo 'set REDISLIB = $$INCLUDE/libredis.a' >> gccr
	@echo 'set LIBRARIES = ($$REDISLIB -lX11 -lm)' >> gccr
	@echo 'foreach x ($$*)' >> gccr
	@echo '  if ("x$$x" == "x-c") then' >> gccr
	@echo '    set LIBRARIES = ""' >> gccr
	@echo '    break' >> gccr
	@echo '  endif' >> gccr
	@echo 'end' >> gccr
	@echo 'gcc -g -I$$INCLUDE $$* $$LIBRARIES' >> gccr
	@chmod a+x gccr
	@echo '[gccr script created]'

clean:
	rm -f *.o
	rm -f $(BINS)
	rm -f $(REDISLIB)
	rm -f gccr
