lexer grammar CoolLexer;
tokens { STR_CONST, ERROR }
@lexer::members {
    const unsigned MAX_STR_CONST = 1024;
    std::vector<char> string_buffer;

    bool null_Symbol_ESCAPE =false;
    int charCount = 0;
    bool null_Symbol = false;
    std::map<int, bool> bool_values;

    void assoc_bool_with_token(bool value) {
        bool_values[tokenStartCharIndex] = value;
    }

    bool get_bool_value(int token_start_char_index) {
        return bool_values.at(token_start_char_index);
    }

     int isInStringMode() const {
        return charCount;
    }

    bool escaped = false;


}

// --------------- прости жетони -------------------

SEMI   : ';';
DARROW : '=>';

PLUS : '+'; 
MINUS : '-';
DIV : '/';
MUL : '*';
LESS : '<';
L_EQ : '<=';
EQ : '=';
DOT: '.';

OPEN_CURLY : '{';
CLOSE_CURLY : '}';
OPEN_BRAC : '(';
CLOSE_BRAC : ')';
COMMA : ',';
DOUBLE_POINTS : ':';
AT : '@';

WIGGLE : '~';

WS : [ \t\r\n\f\u000B]+ -> skip ;


// --------------- булеви константи -------------------

BOOL_CONST : 't' [Rr][Uu][Ee]     { assoc_bool_with_token(true); }
           | 'f' [Aa][Ll][Ss][Ee] { assoc_bool_with_token(false); };

// --------------- коментари -------------------

LINE_COMMENT 
  : '--' ~[\r\n]* -> skip
  ;  


UNMATCHED_COMMENT_END 
  : '*)'
    {
        setType(ERROR);
        setText("Unmatched *)");
    }
  ;

COMMENT
    : '(*' -> pushMode(COMMENT_MODE), skip;


// --------------- ключови думи -------------------
ASSIGN   : '<-'       ;
CASE     : 'case'     | 'CASE' ;
CLASS    : 'class'    | 'CLASS' ;
ELSE     : [Ee][Ll][Ss][Ee] ;
ESAC     : 'esac'     | 'ESAC' ;
FI       : 'fi'       | 'FI' ;
IF       : [Ii][Ff]   ;
IN       : 'in'       | 'IN' ;
INHERITS : 'inherits' | 'INHERITS' ;
ISVOID   : 'isvoid'   | 'ISVOID' ;
LE       : 'le'       | 'LE' ;
LET      : 'let'      | 'LET' ;
LOOP     : 'loop'     | 'LOOP' ;
NEW      : 'new'      | 'NEW' ;
NOT      : 'not'      | 'NOT' ;
OF       : 'of'       | 'OF' ;
POOL     : 'pool'     | 'POOL' ;
THEN     : 'then'     | 'THEN' ;
WHILE    : 'while'    | 'WHILE' ;


INT_CONST
  : 
    [0-9]+
  ;

// -------------- обекти -------------------

OBJECTID 
  : [a-z] [a-zA-Z0-9_]*
  ;
TYPEID 
  : [A-Z] [a-zA-Z0-9_]*
  ;

INVALID_SYMBOL
  : ~[A-Za-z0-9"']
  ;
  
INVALID_UNDERSCORE
  : '_'
    {
        setType(ERROR);
        setText("Invalid symbol \"_\"");
    } ->skip
  ;




// ------------- помощни режими --------------

STRING_START
  : '"' {
    charCount = 0;
    null_Symbol = false;
    null_Symbol_ESCAPE = false;

    string_buffer.clear();
  }
  -> pushMode(STRING_MODE), skip
  ;

ERROR_UNMATCHED_OPEN_COMMENT : . ;





mode STRING_MODE;


STRING_NEW_LINE_SLASH
  : '\\' '\n'
    {
      charCount++;
      string_buffer.push_back('\\');
      string_buffer.push_back('n');
    }
    -> skip
  ;

STRING_TAB
 : '\\' '\u0009'
 {
  charCount++;
  string_buffer.push_back('\\');
  string_buffer.push_back('t');
 }->skip;
STRING_FORMFEED
 : '\\' '\f'
 {
  charCount++;
  string_buffer.push_back('\\');
  string_buffer.push_back('f');
 }->skip;
STRING_BACKSPACE
 : '\\' '\u0008'
 {
  charCount++;
  string_buffer.push_back('\\');
  string_buffer.push_back('b');
 }->skip;
STRING_ESCAPE
 : '\u001b'
 {
  string_buffer.push_back('<');
  string_buffer.push_back('0');
  string_buffer.push_back('x');
  string_buffer.push_back('1');
  string_buffer.push_back('b');
  string_buffer.push_back('>');
 }->skip;

STRING_ESC_SEQ
  : '\\' [\\bntfl"]
    {
      charCount++;
      string_buffer.push_back('\\');
      string_buffer.push_back(getText()[1]);
    }
    -> skip
  ;

STRING_ESC_SEQ_NULL
  : '\\' '\u0000'
    {
      null_Symbol_ESCAPE = true;
    }
    -> skip
  ;


STRING_CARRIAGE_RETURN
 : '\u000D' 
 {
  string_buffer.push_back('<');
  string_buffer.push_back('0');
  string_buffer.push_back('x');
  string_buffer.push_back('0');
  string_buffer.push_back('d');
  string_buffer.push_back('>');
 }->skip;

STRING_SLASH_SYMBOL
  : '\\' [0-9a-zA-Z-]
    {
      charCount++;
      string_buffer.push_back(getText()[1]);
    }
    -> skip
  ;
STRING_NORMAL_CHARS
  : ~["\\\r\n\u001b]+
    {
      for (char c : getText())
      {
        charCount++;
        string_buffer.push_back(c);
      }
    }
    -> skip
  ;

STRING_NEW_LINE_UNESCPAED
 : '\n'{
    setType(ERROR);
    setText("String contains unescaped new line");
    charCount = 0;
 } -> popMode;

STRING_END
  : '"'
    {

      for(char c : string_buffer){
        if(c == '\0'){
          null_Symbol = true;
        }
      }
      if(null_Symbol){
        setType(ERROR);
        setText("String contains null character");
      
      } else if (charCount > MAX_STR_CONST) {
        setType(ERROR);
        setText("String constant too long");
      }else if (null_Symbol_ESCAPE){
        setType(ERROR);
        setText("String contains escaped null character");
      } else {

        setType(STR_CONST);
        setText( "\"" +std::string(string_buffer.begin(), string_buffer.end())+ "\"");
      }
      charCount = 0;
    }
    -> popMode
  ;


mode COMMENT_MODE;

    NESTED_COMMENT_START : '(*' -> pushMode(COMMENT_MODE), skip;
    NESTED_COMMENT_END   : '*)' -> popMode, skip;
    COMMENT_CONTENT      : . -> skip;
    

    UNCLOSED_COMMENT_AT_EOF
        : . EOF
        {
            setType(ERROR);
            setText("Unmatched (*");
            popMode(); // clean up if necessary
        }
        ;
