build_type ?= Release
build_type_lower = ${shell echo ${build_type} | tr "[:upper:]" "[:lower:]"}

build_dir ?= build/${build_type_lower}
cmake_dir := $(CURDIR)

build_tests ?= OFF


all:
	@echo "Usage:"
	@echo "\tmake test"
	@echo "\tmake clean"
.PHONY: all


build:
	mkdir -p $(build_dir) && cd $(build_dir) && \
		cmake \
		-D CMAKE_BUILD_TYPE=$(build_type) \
		-D BOOST_HEADER_ONLY_ENBALE_TESTS=$(build_tests) \
		$(cmake_dir) && make
.PHONY: build


test:
	build_tests=ON $(MAKE) build
	make -C $(build_dir) run-tests
.PHONY: test


clean:
	rm -rf build
.PHONY: clean


# Redirect all undefined targets to cmake.
%:
	make -C $(build_dir) $@
.PHONY:
