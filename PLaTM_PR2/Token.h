#pragma once

enum TokenType
{
   TokenOperator,
   TokenSeparator,
   TokenWord,
   TokenConstant,
   TokenBracket,
   TokenError,
};

struct Token 
{
   size_t tableID;
   size_t rowID;
};