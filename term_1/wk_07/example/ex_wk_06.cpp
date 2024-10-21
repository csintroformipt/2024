#include <array>
#include <algorithm>
#include <iostream>

template <class T>
class Euler
{
public:
    typedef typename T::_State _State;
    static _State make_step(_State& state, const float dt){
        auto f = T::dfdt(state);
        for (auto it = f.state.begin(); it != f.state.end(); ++it) {
           const int index = std::distance(f.state.begin(), it);
           f[index] = state[index] + dt*f[index];
        }
        return f;
    }
};
    
template <typename MP, int N>
class MyState
{
public:
    typedef MP ftype;
    typedef typename std::array<MP, N> container ;

    std::array<MP, N> state;

    size_t size() const{
        return state.size();
    }

    MP& operator[](int i) { return state[i]; }

    MyState () : state(std::array<MP,N>{}){};
    MyState (const std::array<MP, N>& s){
        std::copy_n(s.begin(), s.size(), state.begin());
    }
// private:
};

template <typename T, typename C>
class MyEquation
{
public:   
    // typedef T::container container;
    typedef T _State;
    typedef typename T::container container;
    static T dfdt(T& s){
        container ar {s[1], -s[0]}; 
        return T ( ar);
    }
};

class Config2d{
public:
    const int a = 1;
    const int b = 2;
};

void naive(int N){
    float dt = 0.01f;
    std::array<float, 2> init{1.0f, 0.0f}, next;
    for (int i=0; i< N; i++){
        next = {init[0] + dt * init[1], init[1] - dt * init[0]};

        
        // next[0] = init[0] + dt * init[1];
        // next[1] = init[1] - dt * init[0];

        std::swap (init, next);
    }
    std::cout << next[0] << next[1] << std::endl;
}

void generic(int N){
    typedef float myfloat;
    MyState<myfloat, 2> init {std::array<myfloat,2>{1.0f, 0.0f}};
    MyState<myfloat, 2> next;

    for (int i=0; i< N; i++){
        next = Euler<MyEquation<MyState<myfloat, 2>, Config2d>>::make_step(init, 0.001);
        std::swap(next, init);
    }   
    std::cout << next[0] << next[1] << std::endl;
}

#include <chrono>
int main()
{
    using namespace std::chrono;

    const int N = 2000'000; 

    auto start = high_resolution_clock::now();
    naive(N);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "naive timing: " << duration.count() << std::endl;

    start = high_resolution_clock::now();
    generic(N); 
    stop = high_resolution_clock::now();    
    duration = duration_cast<milliseconds>(stop - start);
    std::cout << "generic algorithm timing: " << duration.count() << std::endl;

    // 
    return 0;
}