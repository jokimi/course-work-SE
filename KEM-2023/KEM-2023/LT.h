#pragma once
#define LEXEMA_FIXSIZE	1
#define LT_MAXSIZE		4096
#define LT_TI_NULLIDX	0xffffffff
#define LEX_UNINTEGER	't'			// uninteger
#define LEX_STRING		't'			// string
#define LEX_BOOLEAN		't'			// boolean
#define LEX_ID			'i'			// �������������
#define LEX_LITERAL		'l'			// �������
#define LEX_PROCESS		'f'			// process
#define LEX_MAKE		'm'			// make
#define LEX_OUT	        'o'			// out
#define LEX_WRITE		'w'			// write
#define LEX_WRITELINE	'w'			// writeline
#define LEX_IF			'c'			// if
#define LEX_SEMICOLON	';'			// ;
#define LEX_COMMA		','			// ,
#define LEX_LEFTBRACE	'{'			// {
#define LEX_RIGHTBRACE	'}'			// }
#define LEX_BEGIN		'['			// begin
#define LEX_END		    ']'			// end
#define LEX_LEFTHESIS	'('			// (
#define LEX_RIGHTHESIS	')'			// )
#define LEX_PLUS		'x'			// +
#define LEX_MINUS		'x'			// -
#define LEX_STAR		'x'			// *
#define LEX_DIRSLASH	'x'			// /
#define LEX_PERCENT     'x'			// %
#define LEX_EQUALITY    'x'			// =
#define LEX_EQUAL       '='			// :
#define LEX_PROGRAM		'p'			// Program
#define LEX_BOR 		'x'			// |
#define LEX_BAND     	'x'			// &
#define LEX_BNOT        'x'			// ~

namespace LT {
	struct Entry {
		char lexema;				// �������
		int sn;						// ����� ������
		int idxLT;					// ������ � ������� ������
		int indID;					// ����� � ������� ����������������
		char operatorValue;			// �������� ��������� ��� ����������.
		int posWord;				// ������� � ������
		char buf[LT_MAXSIZE * 2];	// ����� ��� ����� � �������� ������
	};
	struct LexTable {
		int maxsize;				// ���� ������ ������� ������
		int size;					// ������� ������
		Entry* table; 				// ������ ����� ������� ������
	};
	LexTable Create();
	void Add(
		LexTable& lextable,			// ��������� ���� ������
		Entry entry					// ������ ������� ������
	);
	Entry GetEntry(					// �������� ������ � ������� ������
		LexTable& lextable,			// ��������� ���� ������
		int n						// ����� ���������� ������			
	);
	void Delete(LexTable& lextable);		// ������� ������� ������
	void PrintTable(LexTable& lextable);	// ������ ������� ������
	void PrintTablePolish(LexTable& lextable);	// ������ ������� ������
};