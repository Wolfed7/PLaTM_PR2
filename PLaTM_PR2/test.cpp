int main()
{
   // Проверка токенизации присваиваний:
   int a = 1;
   int b, c = 3;
   b = 2;

   /*
   * Проверка распознавания и 
   * токенизации операторов и 
   * выражений if - else
   */
   if (a < b)
      c = b - a;
   else if (a == 1)
      c = a + b;
   else if (a != b)
   {
      c = a * b;
      return 1;
   }

   return 0;
}
