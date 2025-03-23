CSRCS += $(wildcard $(LVGL_DIR)/app/src/*.c)
CSRCS += $(wildcard $(LVGL_DIR)/app/custom/*.c)
CSRCS += $(wildcard $(LVGL_DIR)/app/generated/*.c)
CSRCS += $(wildcard $(LVGL_DIR)/app/generated/guider_fonts/*.c)
CSRCS += $(wildcard $(LVGL_DIR)/app/generated/images/*.c)

INCLUDE_DIRS = custom generated generated/guider_customer_fonts src

FULL_INCLUDE_DIRS = $(addprefix $(LVGL_DIR)/app/,$(INCLUDE_DIRS))

CFLAGS += $(foreach dir,$(FULL_INCLUDE_DIRS),-I$(dir))

CFLAGS += -I/mnt/disk5/ssd202/buildroot-2024.02.1/output/staging/usr/include/hiredis
CFLAGS += -I/mnt/disk5/ssd202/buildroot-2024.02.1/output/staging/usr/include/

LDFLAGS += -L/mnt/disk5/ssd202/buildroot-2024.02.1/output/target/usr/lib -lhiredis -ljansson
