#include <iostream>
#include <fstream>
#include <sstream>

#include "Tables.h"
#include "Scanner.h"

using namespace std;

const string Keywords = "Keywords.txt";
const string Operators = "Operators.txt";
const string Separators = "Separators.txt";
const string Brackets = "Brackets.txt";
const string Specials = "Specials.txt";

const string testFile = "test.cpp";

int main()
{
   setlocale(LC_ALL, "");

   // ******************************** //
   // Это всё таблицы и работа с ними. //
   // ******************************** //
   Tables tables
   (
      Keywords,
      Operators,
      Separators,
      Brackets,
      Specials
   );

   //// Проверка поиска в постоянных таблицах.
   //tables.SearchOnStatic("int");

   //// Добавление в переменные таблицы.
   //pair<int, int> a = tables.IncludeInDynamic("counter", Int, false);
   //pair<int, int> b = tables.IncludeInDynamic("counter", Int, false);
   //tables.IncludeInDynamic("132", Int);
   //tables.IncludeInDynamic("siztable", Int, false);
   //tables.IncludeInDynamic("IsProgram", Int, false);
   //tables.IncludeInDynamic("table213", Int, false);
   //tables.IncludeInDynamic("421", Int);

   //// Возвращение адреса идентификатора.
   //pair<int, int> SearchResult = tables.SearchOnDynamic("siztable");

   //// Возвращение структуры, содержащей атрибуты.
   //Variable *identifier = tables.SearchOnDynamic(SearchResult);

   //// Изменение атрибута Type.
   //tables.SetType(SearchResult, Void);
   // 
   //// Атрибут изменился.
   //identifier = tables.SearchOnDynamic(SearchResult);


   // ******************************** //
   //  Это всё сканер и работа с ним.  //
   // ******************************** //

   string content;
   ifstream file(testFile);
   if (file) 
   {
      ostringstream ss;
      ss << file.rdbuf();
      content = ss.str();
   }
   file.close();

   auto scanner = Scanner(tables);
   scanner.StartScan(content);

   auto s_errors = scanner.GetErrors();
   auto tokens = scanner.GetTokens();
   auto tokenLineIndexes = scanner.GetTokenLineIndexes();

   for (auto &err : s_errors) 
      cout << err.line << "\t" << err.msg << '\n';

   if (s_errors.size() > 0)
      return 1;

   return 0;
}