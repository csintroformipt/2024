#include <iostream>
#include <sstream>
#include <array>
#include <algorithm>
#include <iterator>

class FibSeq{
public:
    FibSeq(int first, int second): first(first), second(second), third(0){}
    int next(){
        third = first + second;
        first = second;
        second = third;
        return third;
    }
private:
    int first, second, third;
};

int main(int argc, char** argv){
    // process cmd args (NAIVE):
    if (argc != 2){
        std::cerr << "Warning: wrong number of arguments. N value required. Aborting..." << std::endl;
    }

    std::istringstream ss(argv[1]);
    int n;
    if (!(ss >> n)) {
        n = 10;
    } else if (!ss.eof()) {
        std::cerr << "Trailing characters after number: " << argv[1] << std::endl;
    }

    std::cout<< "n = " << n << std::endl;
    // print sequence to stdout
    auto sequence = FibSeq(1, 1);
    std::array<int, 10> my_array = {};

    for (auto& el: my_array){
        std::cout << el << std::endl;
    }

    for (auto& el: my_array){
        el = sequence.next();
    }

    std::cout << "print out with for loop:\n";
    for (auto& el: my_array){
        std::cout << el << " ";
    }
    std::cout << std::endl;

    std::cout << "print out with copy to std::cout :\n";
    std::copy(my_array.begin(), my_array.end(),
                          std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "print out inverse with copy to std::cout :\n";
    std::reverse_copy(my_array.begin(), my_array.end(),
                          std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "print out with copy only even to std::cout :\n";
    std::copy_if(my_array.begin(),
              my_array.end(),
              std::ostream_iterator<int>(std::cout, " "),
              [](int x) { return x % 2 == 0; }
    );
    std::cout << std::endl;

    std::cout << "what happens once you try acessing element out of range :\n";
    std::cout << "my_array[11] = " << my_array[11] << std::endl;
    std::cout << "my_array.at(11) = " << my_array.at(11) << std::endl;

    return 0;
}
