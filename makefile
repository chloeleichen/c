  # Type terminal commands as follows: make EXE=yourFileName (don't add extensions)
  
  # the compiler: gcc for C program, define as g++ for C+ use clang for Harvard stuff
  CC = clang

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Weverything
  
  # link THIS for the cs50 functions (add others as needed):
  LFLAGS = -lcs50

  # the build target executable:
  TARGET = $(EXE)

  all: $(TARGET)

  $(TARGET): $(TARGET).c ; $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LFLAGS)
