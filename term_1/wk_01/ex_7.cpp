#include <iostream>
#include <sstream>

class FibSeq{
public:
    FibSeq(int first, int second): first(first), second(second), third(0){}

    friend std::ostream& operator<<(std::ostream& os, FibSeq& sequence);
private:
    int first, second, third;

    int next(){
        third = first + second;
        first = second;
        second = third;
        return third;
    }
};

std::ostream& operator<<(std::ostream& os, FibSeq& sequence){
    os << sequence.next() << std::endl;
    return os;
}

void stream_sequence(std::ostream& stream, FibSeq& sequence, const int quantity){
    for (int i=0; i<quantity; i++ ){
        stream << sequence;
    }
}

int main(int argc, char** argv){
    // process cmd args (NAIVE):
    if (argc != 2){
        std::cerr << "Error: wrong number of arguments. N value required. Aborting..." << std::endl;
        return -1;
    }

    std::istringstream ss(argv[1]);
    int n;
    if (!(ss >> n)) {
        std::cerr << "Invalid number: " << argv[1] << '\n';
    } else if (!ss.eof()) {
        std::cerr << "Trailing characters after number: " << argv[1] << std::endl;
    }

    std::cout<< "n = " << n << std::endl;
    // print sequence to stdout
    auto sequence = FibSeq(1, 1);
    stream_sequence(std::cout, sequence, n-2);

    return 0;
}
