#include <iostream>

class NSeq{
public:
    NSeq(int start, int counter_lim): start(start), counter_lim(counter_lim), value(start){}

    int get_value(){
        return value;
    }

    void reset(){
        value = start;
    }

    friend std::ostream& operator<<(std::ostream& os, NSeq& sequence);

private:
    int start, counter_lim, value;

    int next(){
        const int result = value;
        const int current_idx = value - start + 1;
        if(current_idx < counter_lim){
            value++;
        }
        return result;
    }
};

std::ostream& operator<<(std::ostream& os, NSeq& sequence){
    os << sequence.next() << std::endl;
    return os;
}

void write_file(std::ostream& stream, NSeq& sequence, const int quantity){
    for (int i=0; i<quantity; i++ ){
        stream << sequence;
    }
}

int main(){
    std::cout << "Please input the n:" << std::endl;
    int n;
    std::cin >> n;
    // print sequence to stdout
    auto sequence = NSeq(1, n);
    write_file(std::cout, sequence, n);

    return 0;
}
