import std.core;
module Actor;

export template<typename T> 
void foo(T t) {
    printf("%s\n", t);
}

export int f(int a) {
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCDNAME__);
    foo(__FUNCDNAME__);
    return a*a;
}