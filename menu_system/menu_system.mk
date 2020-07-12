BASE_DIR = ../
include $(BASE_DIR)/directives.mk

CC = g++

OBJDIR = objdir

INC = -I$(BASE_DIR)

OBJS = \
       $(OBJDIR)/button.o      \
       $(OBJDIR)/menu.o        \
       $(OBJDIR)/menu_bar.o    \
       $(OBJDIR)/menu_system.o \
       $(OBJDIR)/text.o        \
#

LIBNAME = libmenu_system.a

all: directories $(OBJS)
	@echo "archiving $(LIBNAME)"
	@ar rcs $(LIBNAME) $(OBJS)

directories:
	@mkdir -p $(OBJDIR)

clean:
	@rm -r $(OBJDIR) $(LIBNAME)
	@echo "cleaned menu-system library"

$(OBJDIR)/%.o: %.cpp
	@echo "compiling $^"
	@$(CC) $^ $(DIRECTIVES) $(INC) -c -o $@
