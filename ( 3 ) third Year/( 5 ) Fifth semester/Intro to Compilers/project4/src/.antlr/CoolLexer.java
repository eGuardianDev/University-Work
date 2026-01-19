// Generated from /home/dogewithfedora2/Documents/uni/Compilers/project4/cw4/src/CoolLexer.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class CoolLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		SEMI=1, OCURLY=2, CCURLY=3, OPAREN=4, COMMA=5, CPAREN=6, COLON=7, AT=8, 
		DOT=9, PLUS=10, MINUS=11, STAR=12, SLASH=13, TILDE=14, LT=15, EQ=16, DARROW=17, 
		ASSIGN=18, LE=19, CLASS=20, ELSE=21, FI=22, IF=23, IN=24, INHERITS=25, 
		ISVOID=26, LET=27, LOOP=28, POOL=29, THEN=30, WHILE=31, CASE=32, ESAC=33, 
		NEW=34, OF=35, NOT=36, BOOL_CONST=37, INT_CONST=38, OBJECTID=39, TYPEID=40, 
		WS=41, STR_BEGIN=42, COMM_BEGIN=43, COMM_ERR1=44, LCOMM_BEGIN=45, ERROR=46, 
		STR_CONST=47, STR_END=48, STR_ESC_NL=49, ESC_BS=50, ESC_FF=51, ESC_TAB=52, 
		ESC_NULL=53, ESC_ANY=54, NULL=55, STR_NL=56, STR_ERR=57, STR_ANY=58, ESTR_END=59, 
		ESTR_ESC_NL=60, ESTR_NL=61, ESTR_ANY=62, OCOMM=63, CCOMM=64, COMM_SKIP=65, 
		COMM_ERR=66, LCOMM_END=67, LCOMM_SKIP=68;
	public static final int
		STR=1, ESTR=2, COMM=3, LCOMM=4;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE", "STR", "ESTR", "COMM", "LCOMM"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"SEMI", "OCURLY", "CCURLY", "OPAREN", "COMMA", "CPAREN", "COLON", "AT", 
			"DOT", "PLUS", "MINUS", "STAR", "SLASH", "TILDE", "LT", "EQ", "DARROW", 
			"ASSIGN", "LE", "CLASS", "ELSE", "FI", "IF", "IN", "INHERITS", "ISVOID", 
			"LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "NEW", "OF", 
			"NOT", "BOOL_CONST", "INT_CONST", "OBJECTID", "TYPEID", "WS", "STR_BEGIN", 
			"COMM_BEGIN", "COMM_ERR1", "LCOMM_BEGIN", "ERROR", "STR_CONST", "STR_END", 
			"STR_ESC_NL", "ESC_BS", "ESC_FF", "ESC_TAB", "ESC_NULL", "ESC_ANY", "NULL", 
			"STR_NL", "STR_ERR", "STR_ANY", "ESTR_END", "ESTR_ESC_NL", "ESTR_NL", 
			"ESTR_ANY", "OCOMM", "CCOMM", "COMM_SKIP", "COMM_ERR", "LCOMM_END", "LCOMM_SKIP"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'{'", "'}'", "'('", "','", "')'", "':'", "'@'", "'.'", 
			"'+'", "'-'", "'*'", "'/'", "'~'", "'<'", "'='", "'=>'", "'<-'", "'<='", 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, "'--'", null, "'?'", null, null, null, null, null, null, null, 
			null, null, null, null, null, "'\\n'", null, null, null, null, null, 
			null, "'\\n'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "SEMI", "OCURLY", "CCURLY", "OPAREN", "COMMA", "CPAREN", "COLON", 
			"AT", "DOT", "PLUS", "MINUS", "STAR", "SLASH", "TILDE", "LT", "EQ", "DARROW", 
			"ASSIGN", "LE", "CLASS", "ELSE", "FI", "IF", "IN", "INHERITS", "ISVOID", 
			"LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "NEW", "OF", 
			"NOT", "BOOL_CONST", "INT_CONST", "OBJECTID", "TYPEID", "WS", "STR_BEGIN", 
			"COMM_BEGIN", "COMM_ERR1", "LCOMM_BEGIN", "ERROR", "STR_CONST", "STR_END", 
			"STR_ESC_NL", "ESC_BS", "ESC_FF", "ESC_TAB", "ESC_NULL", "ESC_ANY", "NULL", 
			"STR_NL", "STR_ERR", "STR_ANY", "ESTR_END", "ESTR_ESC_NL", "ESTR_NL", 
			"ESTR_ANY", "OCOMM", "CCOMM", "COMM_SKIP", "COMM_ERR", "LCOMM_END", "LCOMM_SKIP"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	    enum class ErrorCode {
	        STR_CONTAINS_ESC_NULL,
	        STR_CONTAINS_NULL,
	        STR_CONTAINS_NEW_LINE,
	        STR_CONTAINS_EOF,
	        STR_TOO_LONG,
	        COMMENT_CONTAINS_EOF,
	        UNMATCHED_COMMENT_END,
	        INVALID_SYMBOL
	    };

	    // Maximum length of a constant string literal (CSL) excluding the implicit
	    // null character that marks the end of the string.
	    const unsigned MAX_STR_CONST = 1024;
	    // Stores the current CSL as it's being built.
	    std::vector<char> string_buffer;

	    int add_char_to_str(char c) {
	        int l = string_buffer.size();
	        const int max_l = MAX_STR_CONST;
	        if (l == max_l) {
	            setMode(ESTR);

	            current_error_code = ErrorCode::STR_TOO_LONG;

	            // restore state invariants
	            string_buffer.clear();
	            string_start_char_index = -1;
	            return 0;
	         }
	        string_buffer.push_back(c);
	        return 1;
	    }

	    // ----------------------- booleans -------------------------

	    // A map from token ids to boolean values
	    std::map<int, bool> bool_values;

	    void assoc_bool_with_token(bool value) {
	        bool_values[tokenStartCharIndex] = value;

	        // hack: force symbol emission for get_bool_value by calling it
	        get_bool_value(tokenStartCharIndex);
	    }

	    bool get_bool_value(int token_start_char_index) {
	        return bool_values.at(token_start_char_index);
	    }

	    // ----------------------- string table -------------------------

	    // All unique strings found in the COOL source code.
	    std::vector<std::string> interned_strings;
	    // A reverse map from interned strings to their index.
	    std::unordered_map<std::string, int> istring_index;

	    // A map from token ids to interned string ids.
	    std::map<int, int> string_tokens;

	    // The index of the " char that starts the current string.
	    int string_start_char_index = -1;

	    void assoc_string_with_token() {
	        // Use the start char index as the token index.
	        //
	        // This assumes that no to tokens start at the same char, which is a
	        // valid assumption for the lexer.
	        int token_index = string_start_char_index;

	        // Get a view on the string buffer.
	        std::string str = {string_buffer.data(), string_buffer.size()};

	        int next_istring_index = interned_strings.size();
	        // Lookup the current string in the interned_strings.
	        auto it = istring_index.find(str);
	        if (it == istring_index.end()) {
	            // Store value of constant string literal.
	            interned_strings.push_back(std::string(str));

	            // Use a view on the interned string as a key in the istring_index
	            // table. Note that it is incorrect to the original str, since it
	            // points to temporary memory and would lead to errors during
	            // comparison internal to the unordered_map.
	            str = interned_strings[next_istring_index];
	            bool first_encounter = false;
	            std::tie(it, first_encounter) = istring_index.insert({str, next_istring_index});
	            assert(first_encounter);
	        }

	        // This will be the correct index for both cases.
	        int string_index = it->second;
	        string_tokens[token_index] = string_index;

	        // hack: force symbol emission for get_csl_text by calling it
	        get_csl_text(token_index);
	    }

	    // Returns the content of the constant string literal (CSL) that starts at
	    // the specified index. (The char at the given index is the opening " of the
	    // string.)
	    const std::string& get_csl_text(int token_start_char_index) {
	        return interned_strings[string_tokens[token_start_char_index]];
	    }

	    // ----------------------- error codes -------------------------

	    // A map from token ids to error codes.
	    std::map<int, ErrorCode> error_codes;

	    ErrorCode current_error_code;

	    void assoc_error_with_token(ErrorCode error_code) {
	        error_codes[tokenStartCharIndex] = error_code;
	    }

	    ErrorCode get_error_code(int token_start_char_index) {
	        return error_codes.at(token_start_char_index);
	    }


	public CoolLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "CoolLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 36:
			BOOL_CONST_action((RuleContext)_localctx, actionIndex);
			break;
		case 41:
			STR_BEGIN_action((RuleContext)_localctx, actionIndex);
			break;
		case 43:
			COMM_ERR1_action((RuleContext)_localctx, actionIndex);
			break;
		case 45:
			ERROR_action((RuleContext)_localctx, actionIndex);
			break;
		case 47:
			STR_END_action((RuleContext)_localctx, actionIndex);
			break;
		case 48:
			STR_ESC_NL_action((RuleContext)_localctx, actionIndex);
			break;
		case 49:
			ESC_BS_action((RuleContext)_localctx, actionIndex);
			break;
		case 50:
			ESC_FF_action((RuleContext)_localctx, actionIndex);
			break;
		case 51:
			ESC_TAB_action((RuleContext)_localctx, actionIndex);
			break;
		case 52:
			ESC_NULL_action((RuleContext)_localctx, actionIndex);
			break;
		case 53:
			ESC_ANY_action((RuleContext)_localctx, actionIndex);
			break;
		case 54:
			NULL_action((RuleContext)_localctx, actionIndex);
			break;
		case 55:
			STR_NL_action((RuleContext)_localctx, actionIndex);
			break;
		case 56:
			STR_ERR_action((RuleContext)_localctx, actionIndex);
			break;
		case 57:
			STR_ANY_action((RuleContext)_localctx, actionIndex);
			break;
		case 58:
			ESTR_END_action((RuleContext)_localctx, actionIndex);
			break;
		case 60:
			ESTR_NL_action((RuleContext)_localctx, actionIndex);
			break;
		case 65:
			COMM_ERR_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void BOOL_CONST_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			 assoc_bool_with_token(true); 
			break;
		case 1:
			 assoc_bool_with_token(false); 
			break;
		}
	}
	private void STR_BEGIN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:

			  // clear the buffer, just in case
			  string_buffer.clear();
			  string_start_char_index = tokenStartCharIndex;

			break;
		}
	}
	private void COMM_ERR1_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:

			  assoc_error_with_token(ErrorCode::UNMATCHED_COMMENT_END);
			  setType(ERROR);

			break;
		}
	}
	private void ERROR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 assoc_error_with_token(ErrorCode::INVALID_SYMBOL); 
			break;
		}
	}
	private void STR_END_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:

			  assoc_string_with_token();

			  // modify token to turn it into a STR_CONST
			  tokenStartCharIndex = string_start_char_index;
			  setType(STR_CONST);

			  // restore state invariants
			  string_buffer.clear();
			  string_start_char_index = -1;

			break;
		}
	}
	private void STR_ESC_NL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 add_char_to_str('\n'); 
			break;
		}
	}
	private void ESC_BS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 add_char_to_str('\b'); 
			break;
		}
	}
	private void ESC_FF_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 add_char_to_str('\f'); 
			break;
		}
	}
	private void ESC_TAB_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 add_char_to_str('\t'); 
			break;
		}
	}
	private void ESC_NULL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:

			  current_error_code = ErrorCode::STR_CONTAINS_ESC_NULL;

			  // restore state invariants
			  string_buffer.clear();
			  string_start_char_index = -1;

			break;
		}
	}
	private void ESC_ANY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 add_char_to_str(getText()[1]); 
			break;
		}
	}
	private void NULL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:

			  current_error_code = ErrorCode::STR_CONTAINS_NULL;

			  // restore state invariants
			  string_buffer.clear();
			  string_start_char_index = -1;

			break;
		}
	}
	private void STR_NL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:

			  assoc_error_with_token(ErrorCode::STR_CONTAINS_NEW_LINE);
			  setType(ERROR);

			  // restore state invariants
			  string_buffer.clear();
			  string_start_char_index = -1;

			break;
		}
	}
	private void STR_ERR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:

			  assoc_error_with_token(ErrorCode::STR_CONTAINS_EOF);
			  setType(ERROR);

			break;
		}
	}
	private void STR_ANY_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 add_char_to_str(getText()[0]); 
			break;
		}
	}
	private void ESTR_END_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:

			  assoc_error_with_token(current_error_code);
			  setType(ERROR);

			break;
		}
	}
	private void ESTR_NL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:

			  assoc_error_with_token(current_error_code);
			  setType(ERROR);

			break;
		}
	}
	private void COMM_ERR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:

			  assoc_error_with_token(ErrorCode::COMMENT_CONTAINS_EOF);
			  setType(ERROR);

			break;
		}
	}

	public static final String _serializedATN =
		"\u0004\u0000D\u01c7\u0006\uffff\uffff\u0006\uffff\uffff\u0006\uffff\uffff"+
		"\u0006\uffff\uffff\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002"+
		"\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002"+
		"\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002"+
		"\u0018\u0007\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002"+
		"\u001b\u0007\u001b\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002"+
		"\u001e\u0007\u001e\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007"+
		"!\u0002\"\u0007\"\u0002#\u0007#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007"+
		"&\u0002\'\u0007\'\u0002(\u0007(\u0002)\u0007)\u0002*\u0007*\u0002+\u0007"+
		"+\u0002,\u0007,\u0002-\u0007-\u0002.\u0007.\u0002/\u0007/\u00020\u0007"+
		"0\u00021\u00071\u00022\u00072\u00023\u00073\u00024\u00074\u00025\u0007"+
		"5\u00026\u00076\u00027\u00077\u00028\u00078\u00029\u00079\u0002:\u0007"+
		":\u0002;\u0007;\u0002<\u0007<\u0002=\u0007=\u0002>\u0007>\u0002?\u0007"+
		"?\u0002@\u0007@\u0002A\u0007A\u0002B\u0007B\u0002C\u0007C\u0001\u0000"+
		"\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003"+
		"\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0006"+
		"\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001"+
		"\n\u0001\n\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\r\u0001\r\u0001"+
		"\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0015\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001"+
		"\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001b\u0001"+
		"\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001c\u0001\u001c\u0001"+
		"\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001"+
		"\u001e\u0001\u001e\u0001\u001f\u0001\u001f\u0001\u001f\u0001\u001f\u0001"+
		"\u001f\u0001 \u0001 \u0001 \u0001 \u0001 \u0001!\u0001!\u0001!\u0001!"+
		"\u0001\"\u0001\"\u0001\"\u0001#\u0001#\u0001#\u0001#\u0001$\u0001$\u0001"+
		"$\u0001$\u0001$\u0001$\u0001$\u0001$\u0001$\u0001$\u0001$\u0003$\u0114"+
		"\b$\u0001%\u0004%\u0117\b%\u000b%\f%\u0118\u0001&\u0001&\u0005&\u011d"+
		"\b&\n&\f&\u0120\t&\u0001\'\u0001\'\u0005\'\u0124\b\'\n\'\f\'\u0127\t\'"+
		"\u0001(\u0004(\u012a\b(\u000b(\f(\u012b\u0001(\u0001(\u0001)\u0001)\u0001"+
		")\u0001)\u0001)\u0001)\u0001*\u0001*\u0001*\u0001*\u0001*\u0001*\u0001"+
		"+\u0001+\u0001+\u0001+\u0001+\u0001,\u0001,\u0001,\u0001,\u0001,\u0001"+
		",\u0001-\u0001-\u0001-\u0001.\u0001.\u0001/\u0001/\u0003/\u014e\b/\u0001"+
		"/\u0001/\u0001/\u0001/\u00010\u00010\u00010\u00010\u00010\u00010\u0001"+
		"0\u00011\u00011\u00011\u00011\u00011\u00011\u00011\u00012\u00012\u0001"+
		"2\u00012\u00012\u00012\u00012\u00013\u00013\u00013\u00013\u00013\u0001"+
		"3\u00013\u00014\u00014\u00014\u00014\u00014\u00014\u00014\u00014\u0001"+
		"5\u00015\u00015\u00015\u00015\u00015\u00016\u00016\u00036\u0180\b6\u0001"+
		"6\u00016\u00016\u00016\u00016\u00017\u00017\u00037\u0189\b7\u00017\u0001"+
		"7\u00017\u00017\u00018\u00018\u00018\u00018\u00019\u00019\u00019\u0001"+
		"9\u00019\u0001:\u0001:\u0001:\u0001:\u0001:\u0001;\u0001;\u0001;\u0001"+
		";\u0001;\u0001<\u0001<\u0001<\u0001<\u0001<\u0001=\u0001=\u0001=\u0001"+
		"=\u0001>\u0001>\u0001>\u0001>\u0001>\u0001>\u0001?\u0001?\u0001?\u0001"+
		"?\u0001?\u0001?\u0001@\u0001@\u0001@\u0001@\u0001A\u0001A\u0001A\u0001"+
		"A\u0001B\u0001B\u0001B\u0001B\u0001B\u0001C\u0001C\u0001C\u0001C\u0000"+
		"\u0000D\u0005\u0001\u0007\u0002\t\u0003\u000b\u0004\r\u0005\u000f\u0006"+
		"\u0011\u0007\u0013\b\u0015\t\u0017\n\u0019\u000b\u001b\f\u001d\r\u001f"+
		"\u000e!\u000f#\u0010%\u0011\'\u0012)\u0013+\u0014-\u0015/\u00161\u0017"+
		"3\u00185\u00197\u001a9\u001b;\u001c=\u001d?\u001eA\u001fC E!G\"I#K$M%"+
		"O&Q\'S(U)W*Y+[,]-_.a/c0e1g2i3k4m5o6q7s8u9w:y;{<}=\u007f>\u0081?\u0083"+
		"@\u0085A\u0087B\u0089C\u008bD\u0005\u0000\u0001\u0002\u0003\u0004\u0016"+
		"\u0002\u0000CCcc\u0002\u0000LLll\u0002\u0000AAaa\u0002\u0000SSss\u0002"+
		"\u0000EEee\u0002\u0000FFff\u0002\u0000IIii\u0002\u0000NNnn\u0002\u0000"+
		"HHhh\u0002\u0000RRrr\u0002\u0000TTtt\u0002\u0000VVvv\u0002\u0000OOoo\u0002"+
		"\u0000DDdd\u0002\u0000PPpp\u0002\u0000WWww\u0002\u0000UUuu\u0001\u0000"+
		"09\u0001\u0000az\u0004\u000009AZ__az\u0001\u0000AZ\u0002\u0000\t\r  \u01ca"+
		"\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000"+
		"\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000"+
		"\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011"+
		"\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015"+
		"\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019"+
		"\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d"+
		"\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000!\u0001"+
		"\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000%\u0001\u0000\u0000"+
		"\u0000\u0000\'\u0001\u0000\u0000\u0000\u0000)\u0001\u0000\u0000\u0000"+
		"\u0000+\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000\u0000\u0000/"+
		"\u0001\u0000\u0000\u0000\u00001\u0001\u0000\u0000\u0000\u00003\u0001\u0000"+
		"\u0000\u0000\u00005\u0001\u0000\u0000\u0000\u00007\u0001\u0000\u0000\u0000"+
		"\u00009\u0001\u0000\u0000\u0000\u0000;\u0001\u0000\u0000\u0000\u0000="+
		"\u0001\u0000\u0000\u0000\u0000?\u0001\u0000\u0000\u0000\u0000A\u0001\u0000"+
		"\u0000\u0000\u0000C\u0001\u0000\u0000\u0000\u0000E\u0001\u0000\u0000\u0000"+
		"\u0000G\u0001\u0000\u0000\u0000\u0000I\u0001\u0000\u0000\u0000\u0000K"+
		"\u0001\u0000\u0000\u0000\u0000M\u0001\u0000\u0000\u0000\u0000O\u0001\u0000"+
		"\u0000\u0000\u0000Q\u0001\u0000\u0000\u0000\u0000S\u0001\u0000\u0000\u0000"+
		"\u0000U\u0001\u0000\u0000\u0000\u0000W\u0001\u0000\u0000\u0000\u0000Y"+
		"\u0001\u0000\u0000\u0000\u0000[\u0001\u0000\u0000\u0000\u0000]\u0001\u0000"+
		"\u0000\u0000\u0000_\u0001\u0000\u0000\u0000\u0000a\u0001\u0000\u0000\u0000"+
		"\u0001c\u0001\u0000\u0000\u0000\u0001e\u0001\u0000\u0000\u0000\u0001g"+
		"\u0001\u0000\u0000\u0000\u0001i\u0001\u0000\u0000\u0000\u0001k\u0001\u0000"+
		"\u0000\u0000\u0001m\u0001\u0000\u0000\u0000\u0001o\u0001\u0000\u0000\u0000"+
		"\u0001q\u0001\u0000\u0000\u0000\u0001s\u0001\u0000\u0000\u0000\u0001u"+
		"\u0001\u0000\u0000\u0000\u0001w\u0001\u0000\u0000\u0000\u0002y\u0001\u0000"+
		"\u0000\u0000\u0002{\u0001\u0000\u0000\u0000\u0002}\u0001\u0000\u0000\u0000"+
		"\u0002\u007f\u0001\u0000\u0000\u0000\u0003\u0081\u0001\u0000\u0000\u0000"+
		"\u0003\u0083\u0001\u0000\u0000\u0000\u0003\u0085\u0001\u0000\u0000\u0000"+
		"\u0003\u0087\u0001\u0000\u0000\u0000\u0004\u0089\u0001\u0000\u0000\u0000"+
		"\u0004\u008b\u0001\u0000\u0000\u0000\u0005\u008d\u0001\u0000\u0000\u0000"+
		"\u0007\u008f\u0001\u0000\u0000\u0000\t\u0091\u0001\u0000\u0000\u0000\u000b"+
		"\u0093\u0001\u0000\u0000\u0000\r\u0095\u0001\u0000\u0000\u0000\u000f\u0097"+
		"\u0001\u0000\u0000\u0000\u0011\u0099\u0001\u0000\u0000\u0000\u0013\u009b"+
		"\u0001\u0000\u0000\u0000\u0015\u009d\u0001\u0000\u0000\u0000\u0017\u009f"+
		"\u0001\u0000\u0000\u0000\u0019\u00a1\u0001\u0000\u0000\u0000\u001b\u00a3"+
		"\u0001\u0000\u0000\u0000\u001d\u00a5\u0001\u0000\u0000\u0000\u001f\u00a7"+
		"\u0001\u0000\u0000\u0000!\u00a9\u0001\u0000\u0000\u0000#\u00ab\u0001\u0000"+
		"\u0000\u0000%\u00ad\u0001\u0000\u0000\u0000\'\u00b0\u0001\u0000\u0000"+
		"\u0000)\u00b3\u0001\u0000\u0000\u0000+\u00b6\u0001\u0000\u0000\u0000-"+
		"\u00bc\u0001\u0000\u0000\u0000/\u00c1\u0001\u0000\u0000\u00001\u00c4\u0001"+
		"\u0000\u0000\u00003\u00c7\u0001\u0000\u0000\u00005\u00ca\u0001\u0000\u0000"+
		"\u00007\u00d3\u0001\u0000\u0000\u00009\u00da\u0001\u0000\u0000\u0000;"+
		"\u00de\u0001\u0000\u0000\u0000=\u00e3\u0001\u0000\u0000\u0000?\u00e8\u0001"+
		"\u0000\u0000\u0000A\u00ed\u0001\u0000\u0000\u0000C\u00f3\u0001\u0000\u0000"+
		"\u0000E\u00f8\u0001\u0000\u0000\u0000G\u00fd\u0001\u0000\u0000\u0000I"+
		"\u0101\u0001\u0000\u0000\u0000K\u0104\u0001\u0000\u0000\u0000M\u0113\u0001"+
		"\u0000\u0000\u0000O\u0116\u0001\u0000\u0000\u0000Q\u011a\u0001\u0000\u0000"+
		"\u0000S\u0121\u0001\u0000\u0000\u0000U\u0129\u0001\u0000\u0000\u0000W"+
		"\u012f\u0001\u0000\u0000\u0000Y\u0135\u0001\u0000\u0000\u0000[\u013b\u0001"+
		"\u0000\u0000\u0000]\u0140\u0001\u0000\u0000\u0000_\u0146\u0001\u0000\u0000"+
		"\u0000a\u0149\u0001\u0000\u0000\u0000c\u014b\u0001\u0000\u0000\u0000e"+
		"\u0153\u0001\u0000\u0000\u0000g\u015a\u0001\u0000\u0000\u0000i\u0161\u0001"+
		"\u0000\u0000\u0000k\u0168\u0001\u0000\u0000\u0000m\u016f\u0001\u0000\u0000"+
		"\u0000o\u0177\u0001\u0000\u0000\u0000q\u017d\u0001\u0000\u0000\u0000s"+
		"\u0186\u0001\u0000\u0000\u0000u\u018e\u0001\u0000\u0000\u0000w\u0192\u0001"+
		"\u0000\u0000\u0000y\u0197\u0001\u0000\u0000\u0000{\u019c\u0001\u0000\u0000"+
		"\u0000}\u01a1\u0001\u0000\u0000\u0000\u007f\u01a6\u0001\u0000\u0000\u0000"+
		"\u0081\u01aa\u0001\u0000\u0000\u0000\u0083\u01b0\u0001\u0000\u0000\u0000"+
		"\u0085\u01b6\u0001\u0000\u0000\u0000\u0087\u01ba\u0001\u0000\u0000\u0000"+
		"\u0089\u01be\u0001\u0000\u0000\u0000\u008b\u01c3\u0001\u0000\u0000\u0000"+
		"\u008d\u008e\u0005;\u0000\u0000\u008e\u0006\u0001\u0000\u0000\u0000\u008f"+
		"\u0090\u0005{\u0000\u0000\u0090\b\u0001\u0000\u0000\u0000\u0091\u0092"+
		"\u0005}\u0000\u0000\u0092\n\u0001\u0000\u0000\u0000\u0093\u0094\u0005"+
		"(\u0000\u0000\u0094\f\u0001\u0000\u0000\u0000\u0095\u0096\u0005,\u0000"+
		"\u0000\u0096\u000e\u0001\u0000\u0000\u0000\u0097\u0098\u0005)\u0000\u0000"+
		"\u0098\u0010\u0001\u0000\u0000\u0000\u0099\u009a\u0005:\u0000\u0000\u009a"+
		"\u0012\u0001\u0000\u0000\u0000\u009b\u009c\u0005@\u0000\u0000\u009c\u0014"+
		"\u0001\u0000\u0000\u0000\u009d\u009e\u0005.\u0000\u0000\u009e\u0016\u0001"+
		"\u0000\u0000\u0000\u009f\u00a0\u0005+\u0000\u0000\u00a0\u0018\u0001\u0000"+
		"\u0000\u0000\u00a1\u00a2\u0005-\u0000\u0000\u00a2\u001a\u0001\u0000\u0000"+
		"\u0000\u00a3\u00a4\u0005*\u0000\u0000\u00a4\u001c\u0001\u0000\u0000\u0000"+
		"\u00a5\u00a6\u0005/\u0000\u0000\u00a6\u001e\u0001\u0000\u0000\u0000\u00a7"+
		"\u00a8\u0005~\u0000\u0000\u00a8 \u0001\u0000\u0000\u0000\u00a9\u00aa\u0005"+
		"<\u0000\u0000\u00aa\"\u0001\u0000\u0000\u0000\u00ab\u00ac\u0005=\u0000"+
		"\u0000\u00ac$\u0001\u0000\u0000\u0000\u00ad\u00ae\u0005=\u0000\u0000\u00ae"+
		"\u00af\u0005>\u0000\u0000\u00af&\u0001\u0000\u0000\u0000\u00b0\u00b1\u0005"+
		"<\u0000\u0000\u00b1\u00b2\u0005-\u0000\u0000\u00b2(\u0001\u0000\u0000"+
		"\u0000\u00b3\u00b4\u0005<\u0000\u0000\u00b4\u00b5\u0005=\u0000\u0000\u00b5"+
		"*\u0001\u0000\u0000\u0000\u00b6\u00b7\u0007\u0000\u0000\u0000\u00b7\u00b8"+
		"\u0007\u0001\u0000\u0000\u00b8\u00b9\u0007\u0002\u0000\u0000\u00b9\u00ba"+
		"\u0007\u0003\u0000\u0000\u00ba\u00bb\u0007\u0003\u0000\u0000\u00bb,\u0001"+
		"\u0000\u0000\u0000\u00bc\u00bd\u0007\u0004\u0000\u0000\u00bd\u00be\u0007"+
		"\u0001\u0000\u0000\u00be\u00bf\u0007\u0003\u0000\u0000\u00bf\u00c0\u0007"+
		"\u0004\u0000\u0000\u00c0.\u0001\u0000\u0000\u0000\u00c1\u00c2\u0007\u0005"+
		"\u0000\u0000\u00c2\u00c3\u0007\u0006\u0000\u0000\u00c30\u0001\u0000\u0000"+
		"\u0000\u00c4\u00c5\u0007\u0006\u0000\u0000\u00c5\u00c6\u0007\u0005\u0000"+
		"\u0000\u00c62\u0001\u0000\u0000\u0000\u00c7\u00c8\u0007\u0006\u0000\u0000"+
		"\u00c8\u00c9\u0007\u0007\u0000\u0000\u00c94\u0001\u0000\u0000\u0000\u00ca"+
		"\u00cb\u0007\u0006\u0000\u0000\u00cb\u00cc\u0007\u0007\u0000\u0000\u00cc"+
		"\u00cd\u0007\b\u0000\u0000\u00cd\u00ce\u0007\u0004\u0000\u0000\u00ce\u00cf"+
		"\u0007\t\u0000\u0000\u00cf\u00d0\u0007\u0006\u0000\u0000\u00d0\u00d1\u0007"+
		"\n\u0000\u0000\u00d1\u00d2\u0007\u0003\u0000\u0000\u00d26\u0001\u0000"+
		"\u0000\u0000\u00d3\u00d4\u0007\u0006\u0000\u0000\u00d4\u00d5\u0007\u0003"+
		"\u0000\u0000\u00d5\u00d6\u0007\u000b\u0000\u0000\u00d6\u00d7\u0007\f\u0000"+
		"\u0000\u00d7\u00d8\u0007\u0006\u0000\u0000\u00d8\u00d9\u0007\r\u0000\u0000"+
		"\u00d98\u0001\u0000\u0000\u0000\u00da\u00db\u0007\u0001\u0000\u0000\u00db"+
		"\u00dc\u0007\u0004\u0000\u0000\u00dc\u00dd\u0007\n\u0000\u0000\u00dd:"+
		"\u0001\u0000\u0000\u0000\u00de\u00df\u0007\u0001\u0000\u0000\u00df\u00e0"+
		"\u0007\f\u0000\u0000\u00e0\u00e1\u0007\f\u0000\u0000\u00e1\u00e2\u0007"+
		"\u000e\u0000\u0000\u00e2<\u0001\u0000\u0000\u0000\u00e3\u00e4\u0007\u000e"+
		"\u0000\u0000\u00e4\u00e5\u0007\f\u0000\u0000\u00e5\u00e6\u0007\f\u0000"+
		"\u0000\u00e6\u00e7\u0007\u0001\u0000\u0000\u00e7>\u0001\u0000\u0000\u0000"+
		"\u00e8\u00e9\u0007\n\u0000\u0000\u00e9\u00ea\u0007\b\u0000\u0000\u00ea"+
		"\u00eb\u0007\u0004\u0000\u0000\u00eb\u00ec\u0007\u0007\u0000\u0000\u00ec"+
		"@\u0001\u0000\u0000\u0000\u00ed\u00ee\u0007\u000f\u0000\u0000\u00ee\u00ef"+
		"\u0007\b\u0000\u0000\u00ef\u00f0\u0007\u0006\u0000\u0000\u00f0\u00f1\u0007"+
		"\u0001\u0000\u0000\u00f1\u00f2\u0007\u0004\u0000\u0000\u00f2B\u0001\u0000"+
		"\u0000\u0000\u00f3\u00f4\u0007\u0000\u0000\u0000\u00f4\u00f5\u0007\u0002"+
		"\u0000\u0000\u00f5\u00f6\u0007\u0003\u0000\u0000\u00f6\u00f7\u0007\u0004"+
		"\u0000\u0000\u00f7D\u0001\u0000\u0000\u0000\u00f8\u00f9\u0007\u0004\u0000"+
		"\u0000\u00f9\u00fa\u0007\u0003\u0000\u0000\u00fa\u00fb\u0007\u0002\u0000"+
		"\u0000\u00fb\u00fc\u0007\u0000\u0000\u0000\u00fcF\u0001\u0000\u0000\u0000"+
		"\u00fd\u00fe\u0007\u0007\u0000\u0000\u00fe\u00ff\u0007\u0004\u0000\u0000"+
		"\u00ff\u0100\u0007\u000f\u0000\u0000\u0100H\u0001\u0000\u0000\u0000\u0101"+
		"\u0102\u0007\f\u0000\u0000\u0102\u0103\u0007\u0005\u0000\u0000\u0103J"+
		"\u0001\u0000\u0000\u0000\u0104\u0105\u0007\u0007\u0000\u0000\u0105\u0106"+
		"\u0007\f\u0000\u0000\u0106\u0107\u0007\n\u0000\u0000\u0107L\u0001\u0000"+
		"\u0000\u0000\u0108\u0109\u0005t\u0000\u0000\u0109\u010a\u0007\t\u0000"+
		"\u0000\u010a\u010b\u0007\u0010\u0000\u0000\u010b\u010c\u0007\u0004\u0000"+
		"\u0000\u010c\u0114\u0006$\u0000\u0000\u010d\u010e\u0005f\u0000\u0000\u010e"+
		"\u010f\u0007\u0002\u0000\u0000\u010f\u0110\u0007\u0001\u0000\u0000\u0110"+
		"\u0111\u0007\u0003\u0000\u0000\u0111\u0112\u0007\u0004\u0000\u0000\u0112"+
		"\u0114\u0006$\u0001\u0000\u0113\u0108\u0001\u0000\u0000\u0000\u0113\u010d"+
		"\u0001\u0000\u0000\u0000\u0114N\u0001\u0000\u0000\u0000\u0115\u0117\u0007"+
		"\u0011\u0000\u0000\u0116\u0115\u0001\u0000\u0000\u0000\u0117\u0118\u0001"+
		"\u0000\u0000\u0000\u0118\u0116\u0001\u0000\u0000\u0000\u0118\u0119\u0001"+
		"\u0000\u0000\u0000\u0119P\u0001\u0000\u0000\u0000\u011a\u011e\u0007\u0012"+
		"\u0000\u0000\u011b\u011d\u0007\u0013\u0000\u0000\u011c\u011b\u0001\u0000"+
		"\u0000\u0000\u011d\u0120\u0001\u0000\u0000\u0000\u011e\u011c\u0001\u0000"+
		"\u0000\u0000\u011e\u011f\u0001\u0000\u0000\u0000\u011fR\u0001\u0000\u0000"+
		"\u0000\u0120\u011e\u0001\u0000\u0000\u0000\u0121\u0125\u0007\u0014\u0000"+
		"\u0000\u0122\u0124\u0007\u0013\u0000\u0000\u0123\u0122\u0001\u0000\u0000"+
		"\u0000\u0124\u0127\u0001\u0000\u0000\u0000\u0125\u0123\u0001\u0000\u0000"+
		"\u0000\u0125\u0126\u0001\u0000\u0000\u0000\u0126T\u0001\u0000\u0000\u0000"+
		"\u0127\u0125\u0001\u0000\u0000\u0000\u0128\u012a\u0007\u0015\u0000\u0000"+
		"\u0129\u0128\u0001\u0000\u0000\u0000\u012a\u012b\u0001\u0000\u0000\u0000"+
		"\u012b\u0129\u0001\u0000\u0000\u0000\u012b\u012c\u0001\u0000\u0000\u0000"+
		"\u012c\u012d\u0001\u0000\u0000\u0000\u012d\u012e\u0006(\u0002\u0000\u012e"+
		"V\u0001\u0000\u0000\u0000\u012f\u0130\u0005\"\u0000\u0000\u0130\u0131"+
		"\u0006)\u0003\u0000\u0131\u0132\u0001\u0000\u0000\u0000\u0132\u0133\u0006"+
		")\u0004\u0000\u0133\u0134\u0006)\u0002\u0000\u0134X\u0001\u0000\u0000"+
		"\u0000\u0135\u0136\u0005(\u0000\u0000\u0136\u0137\u0005*\u0000\u0000\u0137"+
		"\u0138\u0001\u0000\u0000\u0000\u0138\u0139\u0006*\u0005\u0000\u0139\u013a"+
		"\u0006*\u0002\u0000\u013aZ\u0001\u0000\u0000\u0000\u013b\u013c\u0005*"+
		"\u0000\u0000\u013c\u013d\u0005)\u0000\u0000\u013d\u013e\u0001\u0000\u0000"+
		"\u0000\u013e\u013f\u0006+\u0006\u0000\u013f\\\u0001\u0000\u0000\u0000"+
		"\u0140\u0141\u0005-\u0000\u0000\u0141\u0142\u0005-\u0000\u0000\u0142\u0143"+
		"\u0001\u0000\u0000\u0000\u0143\u0144\u0006,\u0007\u0000\u0144\u0145\u0006"+
		",\u0002\u0000\u0145^\u0001\u0000\u0000\u0000\u0146\u0147\t\u0000\u0000"+
		"\u0000\u0147\u0148\u0006-\b\u0000\u0148`\u0001\u0000\u0000\u0000\u0149"+
		"\u014a\u0005?\u0000\u0000\u014ab\u0001\u0000\u0000\u0000\u014b\u014d\u0005"+
		"\"\u0000\u0000\u014c\u014e\u0005\u0000\u0000\u0001\u014d\u014c\u0001\u0000"+
		"\u0000\u0000\u014d\u014e\u0001\u0000\u0000\u0000\u014e\u014f\u0001\u0000"+
		"\u0000\u0000\u014f\u0150\u0006/\t\u0000\u0150\u0151\u0001\u0000\u0000"+
		"\u0000\u0151\u0152\u0006/\n\u0000\u0152d\u0001\u0000\u0000\u0000\u0153"+
		"\u0154\u0005\\\u0000\u0000\u0154\u0155\u0005n\u0000\u0000\u0155\u0156"+
		"\u0001\u0000\u0000\u0000\u0156\u0157\u00060\u000b\u0000\u0157\u0158\u0001"+
		"\u0000\u0000\u0000\u0158\u0159\u00060\u0002\u0000\u0159f\u0001\u0000\u0000"+
		"\u0000\u015a\u015b\u0005\\\u0000\u0000\u015b\u015c\u0005b\u0000\u0000"+
		"\u015c\u015d\u0001\u0000\u0000\u0000\u015d\u015e\u00061\f\u0000\u015e"+
		"\u015f\u0001\u0000\u0000\u0000\u015f\u0160\u00061\u0002\u0000\u0160h\u0001"+
		"\u0000\u0000\u0000\u0161\u0162\u0005\\\u0000\u0000\u0162\u0163\u0005f"+
		"\u0000\u0000\u0163\u0164\u0001\u0000\u0000\u0000\u0164\u0165\u00062\r"+
		"\u0000\u0165\u0166\u0001\u0000\u0000\u0000\u0166\u0167\u00062\u0002\u0000"+
		"\u0167j\u0001\u0000\u0000\u0000\u0168\u0169\u0005\\\u0000\u0000\u0169"+
		"\u016a\u0005t\u0000\u0000\u016a\u016b\u0001\u0000\u0000\u0000\u016b\u016c"+
		"\u00063\u000e\u0000\u016c\u016d\u0001\u0000\u0000\u0000\u016d\u016e\u0006"+
		"3\u0002\u0000\u016el\u0001\u0000\u0000\u0000\u016f\u0170\u0005\\\u0000"+
		"\u0000\u0170\u0171\u0005\u0000\u0000\u0000\u0171\u0172\u0001\u0000\u0000"+
		"\u0000\u0172\u0173\u00064\u000f\u0000\u0173\u0174\u0001\u0000\u0000\u0000"+
		"\u0174\u0175\u00064\u0010\u0000\u0175\u0176\u00064\u0002\u0000\u0176n"+
		"\u0001\u0000\u0000\u0000\u0177\u0178\u0005\\\u0000\u0000\u0178\u0179\t"+
		"\u0000\u0000\u0000\u0179\u017a\u00065\u0011\u0000\u017a\u017b\u0001\u0000"+
		"\u0000\u0000\u017b\u017c\u00065\u0002\u0000\u017cp\u0001\u0000\u0000\u0000"+
		"\u017d\u017f\u0005\u0000\u0000\u0000\u017e\u0180\u0005\u0000\u0000\u0001"+
		"\u017f\u017e\u0001\u0000\u0000\u0000\u017f\u0180\u0001\u0000\u0000\u0000"+
		"\u0180\u0181\u0001\u0000\u0000\u0000\u0181\u0182\u00066\u0012\u0000\u0182"+
		"\u0183\u0001\u0000\u0000\u0000\u0183\u0184\u00066\u0010\u0000\u0184\u0185"+
		"\u00066\u0002\u0000\u0185r\u0001\u0000\u0000\u0000\u0186\u0188\u0005\n"+
		"\u0000\u0000\u0187\u0189\u0005\u0000\u0000\u0001\u0188\u0187\u0001\u0000"+
		"\u0000\u0000\u0188\u0189\u0001\u0000\u0000\u0000\u0189\u018a\u0001\u0000"+
		"\u0000\u0000\u018a\u018b\u00067\u0013\u0000\u018b\u018c\u0001\u0000\u0000"+
		"\u0000\u018c\u018d\u00067\n\u0000\u018dt\u0001\u0000\u0000\u0000\u018e"+
		"\u018f\t\u0000\u0000\u0000\u018f\u0190\u0005\u0000\u0000\u0001\u0190\u0191"+
		"\u00068\u0014\u0000\u0191v\u0001\u0000\u0000\u0000\u0192\u0193\t\u0000"+
		"\u0000\u0000\u0193\u0194\u00069\u0015\u0000\u0194\u0195\u0001\u0000\u0000"+
		"\u0000\u0195\u0196\u00069\u0002\u0000\u0196x\u0001\u0000\u0000\u0000\u0197"+
		"\u0198\u0005\"\u0000\u0000\u0198\u0199\u0006:\u0016\u0000\u0199\u019a"+
		"\u0001\u0000\u0000\u0000\u019a\u019b\u0006:\n\u0000\u019bz\u0001\u0000"+
		"\u0000\u0000\u019c\u019d\u0005\\\u0000\u0000\u019d\u019e\u0005n\u0000"+
		"\u0000\u019e\u019f\u0001\u0000\u0000\u0000\u019f\u01a0\u0006;\u0002\u0000"+
		"\u01a0|\u0001\u0000\u0000\u0000\u01a1\u01a2\u0005\n\u0000\u0000\u01a2"+
		"\u01a3\u0006<\u0017\u0000\u01a3\u01a4\u0001\u0000\u0000\u0000\u01a4\u01a5"+
		"\u0006<\n\u0000\u01a5~\u0001\u0000\u0000\u0000\u01a6\u01a7\t\u0000\u0000"+
		"\u0000\u01a7\u01a8\u0001\u0000\u0000\u0000\u01a8\u01a9\u0006=\u0002\u0000"+
		"\u01a9\u0080\u0001\u0000\u0000\u0000\u01aa\u01ab\u0005(\u0000\u0000\u01ab"+
		"\u01ac\u0005*\u0000\u0000\u01ac\u01ad\u0001\u0000\u0000\u0000\u01ad\u01ae"+
		"\u0006>\u0005\u0000\u01ae\u01af\u0006>\u0002\u0000\u01af\u0082\u0001\u0000"+
		"\u0000\u0000\u01b0\u01b1\u0005*\u0000\u0000\u01b1\u01b2\u0005)\u0000\u0000"+
		"\u01b2\u01b3\u0001\u0000\u0000\u0000\u01b3\u01b4\u0006?\n\u0000\u01b4"+
		"\u01b5\u0006?\u0002\u0000\u01b5\u0084\u0001\u0000\u0000\u0000\u01b6\u01b7"+
		"\t\u0000\u0000\u0000\u01b7\u01b8\u0001\u0000\u0000\u0000\u01b8\u01b9\u0006"+
		"@\u0002\u0000\u01b9\u0086\u0001\u0000\u0000\u0000\u01ba\u01bb\t\u0000"+
		"\u0000\u0000\u01bb\u01bc\u0005\u0000\u0000\u0001\u01bc\u01bd\u0006A\u0018"+
		"\u0000\u01bd\u0088\u0001\u0000\u0000\u0000\u01be\u01bf\u0005\n\u0000\u0000"+
		"\u01bf\u01c0\u0001\u0000\u0000\u0000\u01c0\u01c1\u0006B\n\u0000\u01c1"+
		"\u01c2\u0006B\u0002\u0000\u01c2\u008a\u0001\u0000\u0000\u0000\u01c3\u01c4"+
		"\t\u0000\u0000\u0000\u01c4\u01c5\u0001\u0000\u0000\u0000\u01c5\u01c6\u0006"+
		"C\u0002\u0000\u01c6\u008c\u0001\u0000\u0000\u0000\r\u0000\u0001\u0002"+
		"\u0003\u0004\u0113\u0118\u011e\u0125\u012b\u014d\u017f\u0188\u0019\u0001"+
		"$\u0000\u0001$\u0001\u0006\u0000\u0000\u0001)\u0002\u0005\u0001\u0000"+
		"\u0005\u0003\u0000\u0001+\u0003\u0005\u0004\u0000\u0001-\u0004\u0001/"+
		"\u0005\u0004\u0000\u0000\u00010\u0006\u00011\u0007\u00012\b\u00013\t\u0001"+
		"4\n\u0002\u0002\u0000\u00015\u000b\u00016\f\u00017\r\u00018\u000e\u0001"+
		"9\u000f\u0001:\u0010\u0001<\u0011\u0001A\u0012";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}