include source.mk

CPPFLAGS += -DSTD_ISO_8583=$(YEAR)

TSTDIR	:= $(TSTDIR)/ISO-8583/$(MODULE)
OBJDIR	:= $(OBJDIR)/ISO-8583/$(MODULE)/$(YEAR)
vpath %.cpp $(TSTDIR)
vpath %$(SHAREDLIBLINKEXT) $(BINDIR)
vpath %.h   $(INCDIR)
vpath %.a   $(LIBDIR)

LDLIBS	+= -L $(LIBDIR) 
LDLIBS	+= -lISO-8583-DTE-$(YEAR)$(SUFFIX) -lISO-8583-DTT$(SUFFIX)
LDLIBS	+= $(POCOLIBS) 

OBJS 	+= $(patsubst %.cpp,%.o,$(CPP_SRCS))
DEPS 	+= $(patsubst %.cpp,%.d,$(CPP_SRCS))

OBJS    := $(addprefix $(OBJDIR)/, $(OBJS))
DEPS 	:= $(addprefix $(OBJDIR)/, $(DEPS))


OUT 	= $(BINDIR)/ISO-8583-$(MODULE)-$(YEAR)-TEST$(SUFFIX)

$(info TSTDIR=$(TSTDIR))
$(info OBJDIR=$(OBJDIR))

test: $(OUT)

runtest: $(OUT)
	$(OUT) -all

# Tool invocations
$(OUT): $(OBJS) $(USER_OBJS)
	$(CXX)  -o $(OUT) $(OBJS) $(USER_OBJS) $(LDFLAGS) $(LDLIBS)
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(LIBRARIES)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) $(BINDIR)/$(OUT)
	-@echo ' '


# Each subdirectory must supply rules for building sources it contributes
$(OBJDIR)/%.o: %.cpp
	$(COMPILE.cc) $(OUTPUT_OPTION) -MMD -MP -MF"$(@:%.o=%.d)"  $<
	@echo ' '

-include $(DEPS)


.PHONY: all clean dependents 
.SECONDARY:

