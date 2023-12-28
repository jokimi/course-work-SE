#include "Parm.h"
#include "Error.h"
#include <iostream>
#include <string.h>
namespace Parm {
	PARM getparm(int argc, wchar_t* argv[]) {
		PARM p;
		wcscpy_s(p.in, L"");
		wcscpy_s(p.outASM, L"");
		wcscpy_s(p.outJS, L"");
		wcscpy_s(p.log, L"");
		if (argc == 1) {
			throw ERROR_THROW(100);
		}
		for (int i = 1; i < argc; i++) {
			if (wcslen(argv[i]) >= PARM_MAX_SIZE) {
				throw ERROR_THROW(104);
			}
			if (wcsstr(argv[i], PARM_IN) == argv[i]) {
				wcscpy_s(p.in, argv[i] + wcslen(PARM_IN));
			}
			else if (wcsstr(argv[i], PARM_OUT) == argv[i]) {
				wcscpy_s(p.outASM, argv[i] + wcslen(PARM_OUT));
			}
			else if (wcsstr(argv[i], PARM_OUT) == argv[i]) {
				wcscpy_s(p.outJS, argv[i] + wcslen(PARM_OUT));
			}
			else if (wcsstr(argv[i], PARM_LOG) == argv[i]) {
				wcscpy_s(p.log, argv[i] + wcslen(PARM_LOG));
			}
		}
		if (wcslen(p.in) == 0) {
			throw ERROR_THROW(100);
		}
		if (wcslen(p.outASM) == 0) {
			if (wcslen(p.in) + wcslen(PARM_ASM_DEFAULT_EXT) >= PARM_MAX_SIZE) {
				throw ERROR_THROW(104);
			}
			wcscpy_s(p.outASM, p.in);
			wcsncat_s(p.outASM, PARM_ASM_DEFAULT_EXT, 4);
		}
		if (wcslen(p.outJS) == 0) {
			if (wcslen(p.in) + wcslen(PARM_JS_DEFAULT_EXT) >= PARM_MAX_SIZE) {
				throw ERROR_THROW(104);
			}
			wcscpy_s(p.outJS, p.in);
			wcsncat_s(p.outJS, PARM_JS_DEFAULT_EXT, 4);
		}
		if (wcslen(p.log) == 0) {
			if (wcslen(p.in) + wcslen(PARM_LOG_DEFAULT_EXT) >= PARM_MAX_SIZE) {
				throw ERROR_THROW(104);
			}
			wcscpy_s(p.log, p.in);
			wcsncat_s(p.log, PARM_LOG_DEFAULT_EXT, 4);
		}
		return p;
	}
}