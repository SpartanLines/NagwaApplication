using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using WordsUnscrambler.Workers;
using WordsUnscrambler.Data;

namespace WordsUnscrambler
{
    class Program
    {
        private static readonly FileReader _fileReader = new FileReader();
        private static readonly WordMatcher _wordMatcher = new WordMatcher();
        private const string wordListFileName = "wordlist.txt";
        static void Main(string[] args)
        {
            bool ContinueWordUnscramble = true;
            do{
                Console.WriteLine("Please enter the option- F for File and M for Manual");
                var option=Console.ReadLine() ?? string.Empty;
                switch(option.ToUpper())
                {
                    case "F":
                        Console.Write("Enter Scrambled Words File Name: ");
                        ExecuteScrambledWordsInFile();
                        break;
                    case "M":
                        Console.Write("Enter Scrambled Words manually: ");
                        ExecuteScrambledWordsManualEntry();
                        break;
                    default:
                        Console.Write("Option Was Not Recognized. ");
                        break;
                }
                var ContinueWordUnscrambleDecision = string.Empty;
                do
                {
                    Console.WriteLine("Do you want to continue? Y/N");
                    ContinueWordUnscrambleDecision = (Console.ReadLine() ?? string.Empty);
                } while (!ContinueWordUnscrambleDecision.Equals("Y", StringComparison.OrdinalIgnoreCase)
                      && !ContinueWordUnscrambleDecision.Equals("N", StringComparison.OrdinalIgnoreCase));

                ContinueWordUnscramble = ContinueWordUnscrambleDecision.Equals("Y", StringComparison.OrdinalIgnoreCase);
            }while(ContinueWordUnscramble);
        }
        private static void ExecuteScrambledWordsInFile()
        {
            var manualInput = Console.ReadLine() ?? string.Empty;
            string[] scrambledWords = manualInput.Split(',');
            DisplayMatchedUnscrambledWords(scrambledWords);
        }
        private static void ExecuteScrambledWordsManualEntry()
        {
            var filename = Console.ReadLine() ?? string.Empty;
            string[] scrambledWords = _fileReader.Read(filename);
            DisplayMatchedUnscrambledWords(scrambledWords);
        }
        private static void DisplayMatchedUnscrambledWords(string [] scrambledWords)
        {
            string[] wordList = _fileReader.Read(wordListFileName);
            List<MatchedWord> matchedWords = _wordMatcher.Match(scrambledWords, wordList);
            if (matchedWords.Any()) 
            {
                foreach (var matchedWord in matchedWords)
                {
                    Console.WriteLine("Match found for {0},{1}", matchedWord.ScrambledWord, matchedWord.Word);
                }
            }
            else
            {
                Console.WriteLine("No Matches have been found. ");
            }
        }
    }
}
