# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinc -g

# Directories
SRC_DIR = src
OBJ_DIR = obj
SENSORS_OBJ_DIR = $(OBJ_DIR)/sensor
SUBSCRIBERS_OBJ_DIR = $(OBJ_DIR)/subscribers

# Source files
SRCS = main.c \
       $(SRC_DIR)/publisher.c \
       $(SRC_DIR)/sensor/door_sensor.c \
       $(SRC_DIR)/sensor/smoke_sensor.c \
       $(SRC_DIR)/sensor/motion_sensor.c \
       $(SRC_DIR)/sensor/temp_sensor.c \
       $(SRC_DIR)/subscribers/mobile_app_notifier.c \
       $(SRC_DIR)/subscribers/HAVC_system.c \
       $(SRC_DIR)/subscribers/light_system.c \
       $(SRC_DIR)/subscribers/alarm_system_controller.c

# Object files
OBJS = $(OBJ_DIR)/main.o \
       $(OBJ_DIR)/publisher.o \
       $(SENSORS_OBJ_DIR)/door_sensor.o \
       $(SENSORS_OBJ_DIR)/smoke_sensor.o \
       $(SENSORS_OBJ_DIR)/motion_sensor.o \
       $(SENSORS_OBJ_DIR)/temp_sensor.o \
       $(SUBSCRIBERS_OBJ_DIR)/mobile_app_notifier.o \
       $(SUBSCRIBERS_OBJ_DIR)/HAVC_system.o \
       $(SUBSCRIBERS_OBJ_DIR)/light_system.o \
       $(SUBSCRIBERS_OBJ_DIR)/alarm_system_controller.o

# Output executable
TARGET = smartHome

# Build rules
all: create_dirs $(TARGET)

create_dirs:
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	if not exist $(SENSORS_OBJ_DIR) mkdir $(SENSORS_OBJ_DIR)
	if not exist $(SUBSCRIBERS_OBJ_DIR) mkdir $(SUBSCRIBERS_OBJ_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile main
$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile publisher
$(OBJ_DIR)/publisher.o: $(SRC_DIR)/publisher.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile sensors
$(SENSORS_OBJ_DIR)/%.o: $(SRC_DIR)/sensor/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile subscribers
$(SUBSCRIBERS_OBJ_DIR)/%.o: $(SRC_DIR)/subscribers/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	-del /q /s $(OBJ_DIR)\* 2>nul || true
	-rmdir /s /q $(OBJ_DIR) 2>nul || true
	-del $(TARGET).exe 2>nul || true
