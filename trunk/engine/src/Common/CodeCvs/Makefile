ROOT_DIR:=../../../..

include $(ROOT_DIR)/Makefile.include

CPPFILE=$(wildcard *.cpp)
CFILE=$(wildcard *.c)
MODULES:=$(CPPFILE:%.cpp=%.o) $(CFILE:%.c=%.o)

INCLUDE:=-I.. -I$(ROOT_DIR)/$(ENGINE_DIR)/include -I$(ROOT_DIR)/$(ENGINE_DIR)/sdk/inc -I$(ROOT_DIR)/$(IMPLIB_DIR)/inc -I$(ROOT_DIR)/$(IMPLIB_DIR)/inc/tinyxml

all: $(MODULES)
	@$(ECHO) $(STR_COPY)
	@$(CP) *.o ../

ifneq ($(MAKECMDGOALS),clean)
include $(MODULES:.o=.d)
endif

clean:
	@$(ECHO) $(STR_CLEAN)
	@$(RM) -f *.o *.d
