#这里需要根据自己在linux上配置的opencv路径修改  
INCLUDES=-I/usr/local/Cellar/opencv/3.3.1_1/include/opencv -I/usr/local/Cellar/opencv/3.3.1_1/include -I/usr/local/Cellar/opencv/3.3.1_1/include/opencv2
LIBDIRS=`pkg-config --libs opencv`
LIBDIRS=`pkg-config opencv --libs`
 
OPT = -O3 -Wno-deprecated  
CC=g++  
  
.PHONY: all clean  
  
OBJS = capture.o
  
all : clean capture
	echo all:make complete
  
clean :
	rm -f *.o *~ capture
  
%.o:%.cpp  
	$(CC) -g -c $(INCLUDES) $+ $(OPT)  
  
capture : $(OBJS)
	$(CC) -g $(LIBDIRS) -o $@ $+ $(OPT)
