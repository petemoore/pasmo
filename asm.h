// asm.h
// Revision 7-apr-2004

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <deque>

class Asm {
public:
	Asm ();

	// This is not a copy constructor, it creates a new
	// instance copying only the options.
	explicit Asm (const Asm & a);

	~Asm ();

	enum DebugType { NoDebug, DebugSecondPass, DebugAll };
	DebugType debugtype;
	void setdebugtype (DebugType type);
	void errtostdout ();
	void setbase (unsigned int addr);
	void caseinsensitive ();
	void addincludedir (const std::string & dirname);

	void processfile (const std::string & filename);
	void emitobject (std::ostream & out);
	void emitplus3dos (std::ostream & out);
	void emittap (std::ostream & out, const std::string & filename);
	void emittapbas (std::ostream & out, const std::string & filename);
	void emithex (std::ostream & out);
	void emitamsdos (std::ostream & out, const std::string & filename);
	void emitprl (std::ostream & out, Asm & asmoff);
	void emitmsx (std::ostream & out);
	void dumppublic (std::ostream & out);
	void dumpsymbol (std::ostream & out);
private:
	void operator = (const Asm &); // Forbidden

	class In;
	friend class In;
	In * pin;
};

// End of asm.h