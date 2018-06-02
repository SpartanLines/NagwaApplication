using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace WordsUnscrambler.Workers
{
    class FileReader
    {
        public string[] Read(string wordListFileName)
        {
            string[] fileContent;
            try
            {
                 fileContent = File.ReadAllLines(wordListFileName);
            }
            catch(Exception ex)
            {
                throw new Exception(ex.Message);
            }
            return fileContent;
        }
    }
}
