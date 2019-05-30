extern unsigned char __heap_base;

unsigned int bump_pointer = &__heap_base;
void* malloc(int n) {
  unsigned int r = bump_pointer;
  bump_pointer += n;
  return (void *)r;
}

void free(void* p) {
  // lol
}

char* strcpy(char* dest, const char* src) {
  // TODO: if (dest == NULL) return NULL;
  char *ptr = dest;
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return ptr;
}

int foo() {
  return 42;
}

int bar(int x) {
  return x*3;
}

int lol(char* ptr) {
  strcpy(ptr, "YOLO :)");
  return 0;
}

int meh(char* ptr) {
  strcpy(
    ptr,
    "from catipsum.com: Paw at beetle and eat it before it gets away"
  );
  return 0;
}
