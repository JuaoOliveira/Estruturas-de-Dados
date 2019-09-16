CCOPTION = Wall std=gnu++11 D__USE_MINGW_ANSI_STDIO=1
FLAGS = $(addprefix -,$(CCOPTION))
CC = g++
OBJ = deque.o 
SRC_DIR = /home/joao/Estruturas-de-Dados/source/trabalhos

output.out: $(OBJ) 
	 $(CC) $(FLAGS) $(OBJ) -o output.out 

deque.o: $(SRC_DIR)/deque.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)/deque.cpp -o deque.o 


clean: 
	rm $(OBJ_DIR)/*.o
	rm $(BUILD_DIR)/*.out
