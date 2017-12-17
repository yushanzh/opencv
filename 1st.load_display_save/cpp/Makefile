#这里需要根据自己在linux上配置的opencv路径修改  
INCLUDES=`pkg-config --cflags opencv`
LIBDIRS=`pkg-config --libs opencv`
  
OPT = -O3 -Wno-deprecated  
CC=g++  
  
.PHONY: all clean  
  
OBJS = load_display_save.o
  
all : load_display_save
	echo all:make complete
  
clean :
	rm -f *.o *~ load_display_save
  
%.o:%.cpp  
	$(CC) -c $(INCLUDES) $+ $(OPT)  
  
load_display_save : $(OBJS)
	$(CC) $(LIBDIRS) -o $@ $+ $(OPT)
