TARGET := wasm32

all:
	clang \
		--target=$(TARGET) \
		-O3 \
		-flto \
		-nostdlib \
		-Wl,--no-entry \
		-Wl,--export-all \
		-Wl,--lto-O3 \
		-Wl,-z,stack-size=16384 \
		-o lol.wasm \
		lol.c -v

with-if:
	clang \
		--target=$(TARGET) \
		-emit-llvm -c -S \
		lol.c
	llc \
		-march=$(TARGET) \
		lol.ll
