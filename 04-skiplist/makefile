CC  := gcc
CFLAGS  := -g -I. $(CCFLAGS)
SRCS    := $(wildcard *.c) # 当前目录下的所有的.c文件 
OBJS    := $(SRCS:.c=.o) # 将所有的.c文件名替换为.o
REDISLIB 	:= libredis.a

all:$(REDISLIB) gccr

# ***************************************************************
# C compilations
mt19937.o: mt19937.c mt19937.h
	$(CC) $(CFLAGS) -c mt19937.c

redisassert.o: redisassert.c redisassert.h
	$(CC) $(CFLAGS) -c redisassert.c

sds.o: sds.c sds.h
	$(CC) $(CFLAGS) -c sds.c

zmalloc.o: zmalloc.c zmalloc.h
	$(CC) $(CFLAGS) -c zmalloc.c

dict.o: dict.c dict.h  siphash.c
	$(CC) $(CFLAGS) -c dict.c

skiplist.o: skiplist.c skiplist.h
	$(CC) $(CFLAGS) -c skiplist.c

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
	@echo 'set LIBRARIES = $$REDISLIB' >> gccr
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
