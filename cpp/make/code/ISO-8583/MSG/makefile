include $(YEAR).mk

CPPFLAGS+=-DSTD_ISO_8583=$(YEAR)

SRCDIR	:= $(SRCDIR)/ISO-8583/$(MODULE)
OBJDIR	:= $(OBJDIR)/ISO-8583/$(MODULE)/$(YEAR)
TARGET	:= ISO-8583-$(MODULE)-$(YEAR)$(SUFFIX)$(SHAREDLIBLINKEXT)

ifneq ($(OSNAME),Cygwin)
CXXFLAGS 	+= -fPIC
endif

ifeq ($(OSNAME),Cygwin)
LDFLAGS	 += -Wl,--out-implib=$(LIBDIR)/lib$(TARGET).a
else
#LDFLAGS	 += -Wl,-soname,ISO-8583-$(YEAR)
endif

vpath %.cpp $(SRCDIR)
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


OUT 	= $(LIBPREFIX)$(TARGET)
libexec: $(OUTDIR)/$(OUT)

# Tool invocations
$(OUTDIR)/$(OUT): $(OBJS) $(USER_OBJS)
	$(CXX) -shared -o $(OUTDIR)/$(OUT) $(OBJS) $(USER_OBJS) $(LDFLAGS) $(LDLIBS)  
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

