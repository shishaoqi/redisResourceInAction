CC  := gcc
#CFLAGS  := -w -std=gnu99 -ggdb -ffunction-sections # -w:关闭所有告警
CFLAGS = -g -I. $(CCFLAGS) -DUSE_JEMALLOC -I../deps/jemalloc/include
SRCS    := $(wildcard *.c) # 当前目录下的所有的.c文件 
OBJS    := $(SRCS:.c=.o) # 将所有的.c文件名替换为.o
REDISLIB	:= libredis.a
DEPENDENCY_TARGETS=jemalloc
FINAL_LIBS=-lm -ldl -lpthread
USE_JEMALLOC =

ifeq ($(MALLOC),jemalloc)
	CFLAGS+= -DUSE_JEMALLOC -I./deps/jemalloc/include
	FINAL_LIBS := $(FINAL_LIBS)
	USE_JEMALLOC += -DUSE_JEMALLOC
endif

all:gccr $(REDISLIB)

# ***************************************************************
# C compilations
zmalloc.o: zmalloc.c zmalloc.h
	$(CC) $(CFLAGS) -c zmalloc.c $(FINAL_LIBS)

sds.o: sds.c sds.h
	$(CC) $(CFLAGS) -c sds.c $(FINAL_LIBS)

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
	@echo 'set LIBRARIES = ($$REDISLIB $$INCLUDE/deps/jemalloc/lib/libjemalloc.a -lX11 -lm -ldl -lpthread)' >> gccr
	@echo 'foreach x ($$*)' >> gccr
	@echo '  if ("x$$x" == "x-c") then' >> gccr
	@echo '    set LIBRARIES = ""' >> gccr
	@echo '    break' >> gccr
	@echo '  endif' >> gccr
	@echo 'end' >> gccr
	@echo 'gcc -g -I$$INCLUDE -I$$INCLUDE/deps/jemalloc/include $$* $$LIBRARIES' >> gccr
	@chmod a+x gccr
	@echo '[gccr script created]'
	-(cd ./deps && $(MAKE) $(DEPENDENCY_TARGETS))

clean:
	rm -f *.o
	rm -f $(BINS)
	rm -f $(REDISLIB)
	rm -f gccr
