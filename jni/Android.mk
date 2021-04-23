LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := multibox
LOCAL_CFLAGS += -O3
LOCAL_LDFLAGS += -static
LOCAL_SRC_FILES += etc.c help.c main.c multibox.c
LOCAL_SRC_FILES += arch.c basename.c cat.c clear.c date.c hostname.c ln.c logname.c ls.c pwd.c reset.c sh.c test.c true.c uname.c whoami.c yes.c
include $(BUILD_EXECUTABLE)
