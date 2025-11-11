#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "antlr4-runtime/antlr4-runtime.h"

#include "CoolLexer.h"

using namespace std;
using namespace antlr4;

string cool_token_to_string(Token *token) {
    auto token_type = token->getType();

    switch (token_type) {
        case static_cast<size_t>(-1) : return "EOF";

        case CoolLexer::SEMI: return "';'";
        case CoolLexer::PLUS  : return "'+'";
        case CoolLexer::MINUS : return "'-'";
        case CoolLexer::DIV   : return "'/'";
        case CoolLexer::MUL   : return "'*'";
        case CoolLexer::LESS  : return "'<'";
        case CoolLexer::L_EQ  : return "LE";
        case CoolLexer::EQ    : return "'='";
        case CoolLexer::DOT   : return "'.'";


        
        case CoolLexer::ASSIGN   : return  "ASSIGN" ;
        case CoolLexer::CASE     : return  "CASE" ;
        case CoolLexer::CLASS    : return  "CLASS" ;
        case CoolLexer::ELSE     : return  "ELSE" ;
        case CoolLexer::ESAC     : return  "ESAC" ;
        case CoolLexer::FI       : return  "FI" ;
        case CoolLexer::IF       : return  "IF" ;
        case CoolLexer::IN       : return  "IN" ;
        case CoolLexer::INHERITS : return  "INHERITS" ;
        case CoolLexer::ISVOID   : return  "ISVOID" ;
        case CoolLexer::LE       : return  "LE " ;
        case CoolLexer::LET      : return  "LET" ;
        case CoolLexer::LOOP     : return  "LOOP" ;
        case CoolLexer::NEW      : return  "NEW" ;
        case CoolLexer::NOT      : return  "NOT" ;
        case CoolLexer::OF       : return  "OF" ;
        case CoolLexer::POOL     : return  "POOL" ;
        case CoolLexer::THEN     : return  "THEN" ;
        case CoolLexer::WHILE    : return  "WHILE" ;



        case CoolLexer::OPEN_CURLY : return  "'{'";
        case CoolLexer::CLOSE_CURLY : return  "'}'";
        case CoolLexer::OPEN_BRAC : return  "'('";
        case CoolLexer::CLOSE_BRAC : return  "')'";
        case CoolLexer::COMMA : return  "','";
        case CoolLexer::DOUBLE_POINTS : return  "':'";
        case CoolLexer::AT : return  "'@'";
        case CoolLexer::WIGGLE : return  "'~'";



        case CoolLexer::DARROW: return "DARROW";
        case CoolLexer::BOOL_CONST: return "BOOL_CONST";
        case CoolLexer::STR_CONST: return "STR_CONST";
        case CoolLexer::OBJECTID: return "OBJECTID";
        case CoolLexer::INVALID_SYMBOL:
        case CoolLexer::ERROR: return "ERROR";
        case CoolLexer::INT_CONST: return "INT_CONST";
        case CoolLexer::TYPEID: return "TYPEID";

        default : return "<Invalid Token>: " + token->toString();
    }
}

void dump_cool_token(CoolLexer *lexer, ostream &out, Token *token) {
    if (token->getType() == static_cast<size_t>(-1)) {
        return;
    }
    
    
    out << "#" << token->getLine() << " " << cool_token_to_string(token);

    auto token_type = token->getType();
    auto token_start_char_index = token->getStartIndex();
    
    switch (token_type) {
    case CoolLexer::BOOL_CONST:
        out << " "
            << (lexer->get_bool_value(token_start_char_index) ? "true"
                                                              : "false");
        break;
    case CoolLexer::INVALID_SYMBOL:
        {
        int temp_val_of_invalid_symbol = (int)static_cast<unsigned char>(token->getText()[0]);
        if(temp_val_of_invalid_symbol < 33 || temp_val_of_invalid_symbol == 127){
                cout << ": Invalid symbol \"<0x"
                << std::uppercase << std::hex << std::setw(2) << std::setfill('0')
                << (int)static_cast<unsigned char>(token->getText()[0]) << ">\"";
        }else {
            cout << ": Invalid symbol \"";
            if(temp_val_of_invalid_symbol == 92){
                cout << '\\';
            }

            cout << token->getText() << "\"";   
        }
        }
        break;
    case CoolLexer::ERROR:
        cout << ":";
    case CoolLexer::OBJECTID:
    case CoolLexer::INT_CONST:
    case CoolLexer::TYPEID:
        out << " "
        << (token->getText());
        break;

    case CoolLexer::ERROR_UNMATCHED_OPEN_COMMENT:
        std::cout << " ERROR Unmatched (*";
        break;
    case CoolLexer::STR_CONST:
        std::string text = token->getText();
        std::string finalText = "";

        for(int i =0; i<text.size();++i){
            switch(text[i]){
                case '\t':
                    finalText += "\\t";
                    break;
                case '\f':
                    finalText += "\\f";
                    break;
                case 0x12:
                    finalText += "<0x12>";
                    break;
                case 0x0b:
                    finalText += "<0x0b>";
                    break;
               case '\n':
                    if(i > 0 && text[i-1] != '\\'){
                        finalText += "\\n";
                    }else{
                        finalText += 'n';
                    }
                    break;
                default:
                    finalText += text[i];
            }
        }
        

        std::cout << " "
                  << finalText;
        break;

    }

    out << endl;
}

int main(int argc, const char *argv[]) {
    ANTLRInputStream input(cin);
    CoolLexer lexer(&input);


    CommonTokenStream tokenStream(&lexer);

    tokenStream.fill(); 
    
    int lastLine = lexer.getLine(); 

    if(lexer.isInStringMode()){
        std::cout << "#" << lastLine << " ERROR: Unterminated string at EOF" << std::endl;
    }

    vector<Token *> tokens = tokenStream.getTokens();
    for (Token *token : tokens) {
        dump_cool_token(&lexer, cout, token);
    };
    return 0;
}
