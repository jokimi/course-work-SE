#include "stdafx.h"
int wmain(int argc, wchar_t* argv[]) {
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INTLOG;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog((parm.log));
		wcout << "-in:" << parm.in << ", -out:" << parm.outASM << ", " << parm.outJS << ", -log: " << parm.log << endl;
		In::IN in = In::getin(parm.in);
		LA::Tables Tables = LA::Lex_analyz(in);
		LA::Inf inf;
		Log::WriteLine(log, " ТЕСТ:", " без ошибок\n", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		Log::WriteIn(log, in);
		Log::WriteLine(log, "\n\n", "");
		IT::PrintTable(Tables.idTable);
		LT::PrintTable(Tables.LexTable);
		MFST_TRACE_START
			MFST::Mfst mfst(Tables, GRB::getGreibach());
		mfst.start();
		mfst.printrules();
		std::vector<SA::Function> functions = SA::SemAnalysis(Tables);
		GenASM::Generation(parm.outASM, Tables, functions);
		LT::PrintTablePolish(Tables.LexTable);
		Log::WriteLine(log, "\n\n", "");
		Log::Close(log);
	}
	catch (Error::ERROR error) {
		cout << "Ошибка " << error.id << ": " << error.message /**/ << " (строка " << error.inext.line << ", позиция " << error.inext.col << ")" << std::endl;
		Log::WriteError(log, error);
	}
	system("pause");
}