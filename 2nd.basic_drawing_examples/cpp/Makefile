#这里需要根据自己在linux上配置的opencv路径修改  
INCLUDES=`pkg-config --cflags opencv`
LIBDIRS=`pkg-config --libs opencv`
  
OPT = -O3 -Wno-deprecated  
CC=g++  
  
.PHONY: all clean  
  
OBJS = drawing.o
  
all : clean drawing
	echo all:make complete
  
clean :
	rm -f *.o *~ drawing
  
%.o:%.cpp  
	$(CC) -g -c $(INCLUDES) $+ $(OPT)  
  
drawing : $(OBJS)
	$(CC) -g $(LIBDIRS) -o $@ $+ $(OPT)
