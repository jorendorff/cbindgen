#[repr(C)]
struct Foo<T, U> {
    x: T,
    y: U,
}

type IntFoo<T> = Foo<i32, T>;

#[no_mangle]
extern "C" fn root(a: IntFoo<i32>)
{ }
