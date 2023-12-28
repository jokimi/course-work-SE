#pragma once
#include "IT.h"
#include "LT.h"
#include "In.h"
#include <vector>
#include "LA.h"
#include "Log.h"
#include "SA.h"
#include <string>
#include <stack>
namespace GenASM {
	struct AsmCode {
		std::string Const = ".CONST\n\n";
		std::string Stack = ".STACK 4096\n";
		std::string Code = ".CODE\n\n";
		std::string Data = ".DATA\n";
		std::string Head = ".586P\n.MODEL FLAT, STDCALL\nincludelib kernel32.lib\nincludelib libucrt.lib\nincludelib ..\\Debug\\Library.lib\nEXTRN comp: PROC\nEXTRN concat: PROC\nEXTRN copy: PROC\nEXTRN len: PROC\nEXTRN ConsNum: PROC\nEXTRN ConsStr: PROC\nEXTRN ConsBool: PROC\nEXTRN consPause: proc\nExitProcess PROTO : DWORD\n\n";
	};
	struct Inf {
		int indFun = -1;
		int indI = -1;
		int indExpr = -1;
		bool inFunc = false;
		bool inStart = false;
		std::string id = "";
		bool inIf = false;
		int nIF = 1;
		std::stack<std::string> StExit;
		std::string jmpTrue = "true";
		std::string jmpExit = "exit";
	};
	void GetData(std::string& code, LA::Tables);
	void GetConst(std::string& code, LA::Tables);
	void GetCode(std::string& code, LA::Tables);
	void Generation(wchar_t* file, LA::Tables, std::vector<SA::Function>);
}