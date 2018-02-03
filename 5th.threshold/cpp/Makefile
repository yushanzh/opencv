#这里需要根据自己在linux上配置的opencv路径修改  
INCLUDES=`pkg-config --cflags opencv`
LIBDIRS=`pkg-config --libs opencv`
  
OPT = -O3 -Wno-deprecated  
CC=g++  
  
.PHONY: all clean  
  
OBJS =  threshold.o
  
all : clean  threshold
	echo all:make complete
  
clean :
	rm -f *.o *~ threshold
  
%.o:%.cpp  
	$(CC) -g -c $(INCLUDES) $+ $(OPT)  
  
threshold : $(OBJS)
	$(CC) -g $(LIBDIRS) -o threshold threshold.o $(OPT)

