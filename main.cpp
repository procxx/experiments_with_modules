import std.core;
import manager;

int main() {
    M m;

    for(int i = 0; i < 10; i++) {
        m.m_vec.push_back(i);
    }

    for(auto v: m.m_vec) {
        std::cout << v << std::endl;
    }
    // printf("%d\n", m.b());

    // std::cout << m.b() << std::endl;

    return 0;
}