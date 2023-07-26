#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int findVowel (string word) {
  int index = 0;
  for (int i = 0; i < word.length(); i++) {
    if (word.at(i) == 'a' || word.at(i) == 'e' || word.at(i) == 'i' || word.at(i) == 'o' || word.at(i) == 'u'
        || word.at(i) == 'A' || word.at(i) == 'E' || word.at(i) == 'I' || word.at(i) == 'O' || word.at(i) == 'U') {
        index = i;
        break;
    }
  }
  return index;
}

int main () {
  string sentence;

  while (true) {
    cout << "Enter a sentence to translate into pig latin: " << endl;

    getline(cin, sentence);

    if (sentence.compare("quit") == 0)
      break;

    int wordCount = 1;
    for (int i = 0; i < sentence.length(); i++) {
      if (sentence.at(i) == ' ')
        wordCount++;
    }

    string word;
    string sentArr[wordCount];
    int index = 0;
    for (int i = 0; i < sentence.length(); i++) {
      if (sentence.at(i) != ' ' || isalpha(sentence.at(i)) || ispunct(sentence.at(i)))
        word += sentence.at(i);
      else {
        sentArr[index] = word;
        index++;
        word = "";
      }

      if (i == sentence.length() - 1)
        sentArr[index] = word;
    }

    string newSentArr[wordCount];
    for (int i = 0; i < wordCount; i++) {
      int firstVowel = findVowel(sentArr[i]);
      string p1 = sentArr[i].substr(firstVowel);
      string p2 = sentArr[i].substr(0, firstVowel);
      if (firstVowel == 0)
        newSentArr[i] = p1 + p2 + "way";
      else
        newSentArr[i] = p1 + p2 + "ay";
    }

    for (int i = 0; i < wordCount; i++)
      cout << newSentArr[i] << " ";
    cout << endl;
  }

  return 0;
}
