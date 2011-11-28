#include <ruby.h>

struct my_struct {
        int x;
        int y;
        int z;
};

static VALUE
hello_world()
{
        return rb_str_new2("hello, world!");
}

static VALUE
rb_my_struct_alloc(VALUE klass)
{
	struct my_struct *s;
        //s = ALLOC(struct my_struct);
        //return Data_Wrap_Struct(klass, 0, free, s);
	return Data_Make_Struct(klass, struct my_struct, 0, free, s);
}

static VALUE
rb_my_struct_init(int argc, VALUE *argv, VALUE self)
{
        struct my_struct *s;
        VALUE x, y, z;

        Data_Get_Struct(self, struct my_struct, s);

        rb_scan_args(argc, argv, "03", &x, &y, &z);

        if (!NIL_P(x)) {
                s->x = NUM2INT(x);
        } else {
                s->x = 1;
        }

        if (!NIL_P(y)) {
                s->y = NUM2INT(y);
        } else {
                s->y = 2;
        }

        if (!NIL_P(z)) {
                s->z = NUM2INT(z);
        } else {
                s->z = 3;
        }

        return self;
}

#define MAKE_GETTER(name)                                       \
        static VALUE                                            \
        rb_my_struct_##name(VALUE self)                         \
        {                                                       \
                struct my_struct *s;                            \
                Data_Get_Struct(self, struct my_struct, s);     \
                return INT2NUM(s->name);                        \
        }

#define MAKE_SETTER(name)                                               \
        static VALUE                                                    \
        rb_my_struct_set_##name(int argc, VALUE *argv, VALUE self)      \
        {                                                               \
                struct my_struct *s;                                    \
                VALUE var;                                              \
                rb_scan_args(argc, argv, "1", &var);                    \
                Data_Get_Struct(self, struct my_struct, s);             \
                s->name = NUM2INT(var);                                 \
                return var;                                             \
        }

MAKE_GETTER(x);
MAKE_SETTER(x);
MAKE_GETTER(y);
MAKE_SETTER(y);
MAKE_GETTER(z);
MAKE_SETTER(z);

void
Init_native_playground()
{
        VALUE mNativePlayground = rb_define_module("NativePlayground");
        rb_define_singleton_method(mNativePlayground, "hello_world", hello_world, 0);

        VALUE cMyStruct = rb_define_class_under(mNativePlayground, "MyStruct", rb_cObject);
        rb_define_alloc_func(cMyStruct, rb_my_struct_alloc);
	rb_define_method(cMyStruct, "initialize", rb_my_struct_init, -1);
        rb_define_method(cMyStruct, "x", rb_my_struct_x, 0);
        rb_define_method(cMyStruct, "x=", rb_my_struct_set_x, -1);
        rb_define_method(cMyStruct, "y", rb_my_struct_y, 0);
        rb_define_method(cMyStruct, "y=", rb_my_struct_set_y, -1);
        rb_define_method(cMyStruct, "z", rb_my_struct_z, 0);
        rb_define_method(cMyStruct, "z=", rb_my_struct_set_z, -1);
}
