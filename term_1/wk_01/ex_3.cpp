#include <iostream>

class NSeq{
public:
    NSeq(int start, int counter_lim): start(start), counter_lim(counter_lim), value(start){}

    int next(){
        const int result = value;
        const int current_idx = value - start + 1;
        if(current_idx < counter_lim){
            value++;
        }
        return result;
    }
//    friend std::ostream& operator<<(std::ostream& os, NSeq& sequence);
private:
    int start, counter_lim, value;
};

std::ostream& operator<<(std::ostream& os, NSeq& sequence){
    os << sequence.next() << std::endl;
    return os;
}

int main()
{
    auto sequence = NSeq(1, 8);
    for (int i=0; i<10; i++ ){
        std::cout << sequence.next() << std::endl;
    }

    sequence = NSeq(-10, 7);
    for (int i=0; i<15; i++ ){
        std::cout << sequence;
    }

    return 0;
}
