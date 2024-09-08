#include <iostream>
#include <sstream>
#include <array>

class HarmSeq{
public:
    HarmSeq(int start, size_t counter_lim): start(start), counter_lim(counter_lim), number(start){}

    int get_value(){
        return 1/number;
    }
    int next(){
        number++;
        return get_value();
    }
private:
    int start;
    size_t counter_lim;
    int number;
};

int main(int argc, char** argv){
    // process cmd args (NAIVE):
    size_t n;
    if (argc != 2){
        std::cerr << "Warning: wrong number of arguments. Exactly 1 argument is required." << std::endl;
        std::cout << "Setting n value to 10" << std::endl;
        n = 10;
    }
    else{
        std::istringstream ss(argv[1]);
        if (!(ss >> n)) {
            std::cerr << "Invalid number: " << argv[1] << '\n';
        } else if (!ss.eof()) {
            std::cerr << "Trailing characters after number: " << argv[1] << std::endl;
        }
    }

    std::cout<< "n = " << n << std::endl;
    // print sequence to stdout
    auto sequence = HarmSeq(1, n);
    std::array<int, 10> my_array = {};

    for (auto& el: my_array){
        std::cout << el << std::endl;
    }

    for (size_t i=0; i<n; i++){
        my_array[i] = sequence.next();
    }

    std::cout << "print out with for loop:\n";
    for (auto& el: my_array){
        std::cout << el << " ";
    }
    std::cout << std::endl;

    std::cout << "What the hell is going on??? XD" << std::endl;

    std::cout << "By the way try running this program with n==20 and n==200" << std::endl;

    return 0;
}
