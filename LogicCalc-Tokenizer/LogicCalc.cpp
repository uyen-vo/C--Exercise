#include <iostream>
#include <stdexcept>
using namespace std;

struct Token {
	char kind;
	bool nature;
	Token(char ch) : kind(ch), nature(0) {}
	Token(char ch, bool type) : kind(ch), nature(type) {}
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() : full(false), buffer(0) {}
	void putback(Token t) {
		if (full) throw runtime_error("putback into a full buffer");
		buffer = t;
		full = true;
	}
	Token get() {
		if (full) { full = false; return buffer; }
		while(true){
			char ch;
			cin >> ch;
			switch (ch) {
			case '&': case '^': case '|': case '!': case ';': case '(': case ')': case '=':
				return Token(ch);
			case 't': case 'T':
				return Token(ch, true);
			case 'f': case 'F':
				return Token(ch, false);
			case 'q': case 'Q':
				throw runtime_error("Exiting...");
			default: {
				cout << ch << " is not a valid token. Try again." << endl;
				return Token('x');
				break;
			}
			}
		}
	}
};

Token_stream ts; //output stream

int invalid = 0;

bool expression();  // declaration to deal with indirect recursion
bool term();
bool factor();

bool primary() {
	
	Token t = ts.get();
	switch (t.kind) {
	case '(': {
		bool d = expression();
		t = ts.get();
		if (t.kind != ')')
			cout << "')' expected" << endl;
		return d; }
	case '!': {	return !expression(); break; }
	case 't': return t.nature; break;
	case 'T': return t.nature; break;
	case 'f': return t.nature; break;
	case 'F': return t.nature; break;

	default: ts.putback(t);
	}
}

bool term() {
	bool val = factor();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '&':
			val = (factor() && val); break;
		default: ts.putback(t); return val;
		}
	}
}

bool factor() {
	bool val = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '^': {
			val = (val != primary()); break;
		}
		default: ts.putback(t); return val;
		}

	}
}

void setInvalid(int i) {
	invalid = i;
}

int getInvalid() {
	return invalid;
}

bool expression() {
	bool val = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '|': val = (term() || val); break;
			//invalid token
		case 'x': setInvalid(1); break;
		default: ts.putback(t); return val;
		}
	}
}



int main()
try {
	bool val;
	char output = ' ';
	while (true) {
		Token t = ts.get();
		if (t.kind == ';') {
			if (val == 1)
				output = 'T';
			else
				output = 'F';
			if (getInvalid() == 1) {
				output = ' ';
				setInvalid(0);
			}
			cout << output << endl;
		}
		else if (t.kind == '=') {
			if (val == 1)
				output = 'T';
			else
				output = 'F';
			if (getInvalid() == 1) {
				output = ' ';
				setInvalid(0);
			}
			cout << output << endl;
		}
		else
			ts.putback(t);
		val = expression();
	}
}
catch (runtime_error& e) {
	cerr << e.what() << endl;
	return 1;
}

catch (...) {
	cerr << "exception\n";
	return 2;
}