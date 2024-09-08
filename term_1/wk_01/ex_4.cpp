#include <iostream>
#include <fstream>

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

    std::string text_filename = "my_junk_file.txt";
    std::string bin_filename = "my_junk_file.bin";
    const int quontity = 20;

    // print sequence to stdout
    auto sequence = NSeq(1, 15);
    write_file(std::cout, sequence, quontity);

    // print sequence to text file
    sequence.reset();
    std::ofstream fout (text_filename, std::ios::out | std::ios::trunc);
    write_file(fout, sequence, quontity);
    fout.close();


    //read data from text file as ints and write to binary file
    std::ifstream fin(text_filename, std::ios::in);
    std::ofstream fout_bin (bin_filename, std::ios::out | std::ios::binary);

    if (!fin.is_open()) {
        std::cerr << "Could not open file '" << text_filename << "'" << std::endl;
        return EXIT_FAILURE;
    }

    int buffer;
    while (fin >> buffer) {
        std:: cout << "read buffer = " << buffer << std::endl;
        fout_bin.write((char *)&buffer, sizeof(buffer));
    }
    fin.close();
    fout_bin.close();

    return 0;
}
