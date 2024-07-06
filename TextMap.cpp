// TextMap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>
// Функция для приведения строки к нижнему регистру
void toLowerCase(std::string& str) 
{
	for (char& c : str) {
		c = std::tolower(c);
	}
}
// функция для удаления знаков препинания из строки
void removePunctuation(std::string& str) 
{
	std::string result;
	for (char c : str) {
		if (!std::ispunct(c)) {
			result += c;
		}
	}
	str = result;
}

int main() 
{
    std::ifstream file("in.txt");
    if (!file.is_open()) 
    {
        std::cerr << "Error open file in.txt" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordFrequency;

    std::string line;
    while (std::getline(file, line)) 
    {
        toLowerCase(line);

        removePunctuation(line);

        std::stringstream ss(line);
        std::string word;
        while (ss >> word) 
        {
            wordFrequency[word]++;
        }
    }

    file.close();

    std::cout << "Word 'and' freq: " << wordFrequency["and"] << std::endl;
    std::cout << "Word 'or' freq: " << wordFrequency["or"] << std::endl;
    std::cout << "Word 'has' freq: " << wordFrequency["has"] << std::endl;

    // Ищем самое длинное и самое частотное слово
    std::pair<std::string, int> longestWord = { "", 0 };
    std::pair<std::string, int> mostFrequentWord = { "", 0 };

    for (const auto& kv : wordFrequency) 
    {
        if (kv.first.size() > longestWord.first.size())
            longestWord = { kv.first, kv.second };
        

        if (kv.second > mostFrequentWord.second) 
            mostFrequentWord = { kv.first, kv.second };
        
    }

    // Печатаем самое длинное и самое частотное слово
    std::cout << "Longest word: " << longestWord.first << " (" << longestWord.second << " times)" << std::endl;
    std::cout << "Most freq word: " << mostFrequentWord.first << " (" << mostFrequentWord.second << " times)" << std::endl;

    return 0;
}