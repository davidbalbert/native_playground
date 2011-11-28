#include <ruby.h>

static VALUE hello_world()
{
  return rb_str_new2("hello, world!");
}

Init_native_playground()
{
  VALUE mNativePlayground = rb_define_module("NativePlayground");
  rb_define_singleton_method(mNativePlayground, "hello_world", hello_world, 0);
}
