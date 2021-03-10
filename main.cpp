#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generate();
bool probability_over(int over, int out_of);
bool is_vowel(char letter);
bool validate_letter(char new_letter, char previous_letter);

int main()
{
    srand(time(nullptr));
    size_t number_of_names {};
    bool more_names{true};
    do
    {
        std::cout << "How many names to generate: ";
        std::cin >> number_of_names;
        std::cout << "---------------------------------->"<< std::endl;
        for(size_t i {0}; i<number_of_names; i++)
        {
            std::string name = generate();
            std::cout << name << std::endl;
        }
        bool valid_response{false};
        std::cout<<std::endl;
        do
        {
            std::cout << "Generate More? (Y/N): ";
            char response{};
            std::cin >> response;
            if(response == 'Y' ||response == 'y') valid_response = true;
            else if(response == 'N' || response == 'n')
            {
                valid_response = true;
                more_names = false;
                std::cout << "Goodbye..."<<std::endl;
            }
            else std::cout<< "invalid response..." << std::endl;
        }while(!valid_response);
    }while(more_names);
    std::cout << std::endl;
    return 0;
}

std::string generate()
{
    std::string name{};
    size_t number_of_letters  = (rand() % 7) + 3;
    for(size_t j {0}; j<number_of_letters; j++)
    {
        //Upper
        if(j == 0)
        {
            int letter_numeric  = rand() % 26 + 65;
            char letter = letter_numeric;
            name.push_back(letter);
        }
        else
        {
        bool letter_accepted {false};
            char letter{};
            while(!letter_accepted)
            {
                int letter_numeric = rand() % 26 + 97;
                letter = letter_numeric;
                letter_accepted = validate_letter(letter, name.at(j-1));
            }
            name.push_back(letter);
        }
    }
    return name;
}

/*Determines if a letter is valid based on the previous letter.
 *The main filter for this random name generator.*/
bool validate_letter(char new_letter, char previous_letter)
{
    if(previous_letter == 'Q' || previous_letter == 'q')
    {
        if(new_letter == 'U' || new_letter == 'u') return true;
        if(is_vowel(new_letter) && probability_over(80,100)) return true;
        return false;
    }
    if(is_vowel(previous_letter) && !is_vowel(new_letter)) return true;
    if(!is_vowel(previous_letter) && is_vowel(new_letter)) return true;
    if(new_letter == 'H'||new_letter == 'h')
    {
        if((previous_letter == 'C' || previous_letter == 'c') && probability_over(20,100)) return true;
        if((previous_letter == 'S' || previous_letter == 's') && probability_over(20,100)) return true;
        if((previous_letter == 'T' || previous_letter == 't') && probability_over(20,100)) return true;
        if((previous_letter == 'P' || previous_letter == 'p') && probability_over(50,100)) return true;
    }
    if(is_vowel(previous_letter) && is_vowel(new_letter) && probability_over(30,100)) return true;
    if(!is_vowel(previous_letter) && !is_vowel(new_letter) && probability_over(98,100)) return true;
    return false;
}

bool is_vowel(char letter)
{
    bool vowel{false};
    if(letter == 65)vowel = true;
    if(letter == 69)vowel = true;
    if(letter == 73)vowel = true;
    if(letter == 79)vowel = true;
    if(letter == 85)vowel = true;
    if(letter == 97)vowel = true;
    if(letter == 101)vowel = true;
    if(letter == 105)vowel = true;
    if(letter == 111)vowel = true;
    if(letter == 117)vowel = true;
//    if(vowel) cout << letter << endl;
    return vowel;
}

bool probability_over(int over, int out_of)
{
    return rand()% out_of + 1 > over;
}
