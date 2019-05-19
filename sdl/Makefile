CMAKE = cmake

TOP = $(PWD)
WORK_DIR = $(TOP)/.work
BUILD_DIR = $(WORK_DIR)/build
INSTALL_DIR = $(WORK_DIR)/install

BINS = drawLine miniPaint

all: prep build

.PHONY: prep
.SILENT: prep
prep:
	if [ ! -d $(WORK_DIR) ]; then \
		mkdir $(WORK_DIR); \
	fi;
	if [ ! -d $(BUILD_DIR) ]; then \
		mkdir $(BUILD_DIR); \
	fi;
	if [ ! -d $(INSTALL_DIR) ]; then \
		mkdir $(INSTALL_DIR); \
	fi;


.PHONY: build
build: configure
	@cd $(BUILD_DIR) && make
	@cd $(BUILD_DIR) && make install

.PHONY: configure
configure:
	@cd $(BUILD_DIR) && $(CMAKE) \
		-DCMAKE_INSTALL_PREFIX=$(INSTALL_DIR) \
		../../


define exec =
.PHONY: exec/$(1)
exec/$(1): build
	$(INSTALL_DIR)/bin/$(1)
endef

$(foreach bin,$(BINS),$(eval $(call exec,$(bin))))

.PHONE: clean
clean:
	@rm -rf $(WORK_DIR)
