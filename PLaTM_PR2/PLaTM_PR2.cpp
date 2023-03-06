#include "Tables.h"

using namespace std;

const string Keywords = "Keywords.txt";
const string Operators = "Operators.txt";
const string Separators = "Separators.txt";
const string Brackets = "Brackets.txt";
const string Specials = "Specials.txt";

int main()
{
   Tables tables
   (
      Keywords,
      Operators,
      Separators,
      Brackets,
      Specials
   );

   // Проверка поиска в постоянных таблицах.
   tables.SearchOnStatic("int");

   // Добавление в переменные таблицы.
   pair<int, int> a = tables.IncludeInDynamic("counter", Int, false);
   pair<int, int> b = tables.IncludeInDynamic("counter", Int, false);
   tables.IncludeInDynamic("132", Int);
   tables.IncludeInDynamic("siztable", Int, false);
   tables.IncludeInDynamic("IsProgram", Int, false);
   tables.IncludeInDynamic("table213", Int, false);
   tables.IncludeInDynamic("421", Int);

   // Возвращение адреса идентификатора.
   pair<int, int> SearchResult = tables.SearchOnDynamic("siztable");

   // Возвращение структуры, содержащей атрибуты.
   Variable *identifier = tables.SearchOnDynamic(SearchResult);

   // Изменение атрибута Type.
   tables.SetType(SearchResult, Void);

   // Атрибут изменился.
   identifier = tables.SearchOnDynamic(SearchResult);

   return 0;
}