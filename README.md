Some resources:

1. [C++ Modules in VS 2015 Update 1](https://blogs.msdn.microsoft.com/vcblog/2015/12/03/c-modules-in-vs-2015-update-1/)
2. [Latest draft](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/n4637.pdf)

Problems in Visual C++ 2017:

1. Using Standard Library modules:

    * internal compiler error when using std::string in module
    * link errors using std::ofstream