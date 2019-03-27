CMAKE = cmake

TOP = $(PWD)
WORK_DIR = $(TOP)
BUILD_DIR = $(WORK_DIR)/build
INSTALL_DIR = $(WORK_DIR)/install

BINS = simpleTemplateTest nonTypeTemplateTest

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
configure: prep
	@cd $(BUILD_DIR) && $(CMAKE) \
		-DCMAKE_INSTALL_PREFIX=$(INSTALL_DIR) \
		$(TOP)


define exec =
.PHONY: exec/$(1)
exec/$(1): build
	$(INSTALL_DIR)/bin/$(1)
endef

$(foreach bin,$(BINS),$(eval $(call exec,$(bin))))

.PHONE: clean
clean:
	@rm -rf $(BUILD_DIR) $(INSTALL_DIR)
