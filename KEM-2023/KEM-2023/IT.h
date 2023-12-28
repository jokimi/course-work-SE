#pragma once
#define ID_MAXSIZE		12
#define TI_MAXSIZE		4096
#define TI_INT_DEFAULT	0x00000000
#define TI_STR_DEFAULT	0x00
#define TI_NULLIDX		0xffffffff
#define TI_STR_MAXSIZE	255
namespace IT {
	enum IDDATATYPE { INT = 1, STR = 2, BOOL = 3, INT8 = 4, NODEF = 0 };		// ���� ������ ����������������
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4 };									// ���� ���������������: ����������, �������, ��������, �������
	struct Entry {
		int idxfirstLE;							// ������ ������ ������ � ������� ������
		char* id;								// �������������
		IDDATATYPE iddatatype;					// ��� ������
		IDTYPE idtype;							// ��� ��������������
		bool kek = false;
		int parm;
		union Value {
			unsigned int vint;					// �������� integer
			struct {
				int len;						// ���������� �������� � string
				char* str;						// c������ string
			} vstr;								// �������� string
			bool vbool;							// �������� bool
			int indexL;
		} value;								// �������� ��������������
	};
	struct IdTable {
		int maxsize;
		int size;
		Entry* table;
	};
	IdTable Create();
	void Add(IdTable& idtable, Entry entry);
	Entry GetEntry(IdTable& idtable, int n);
	int IsId(IdTable& idtable, char* id);		// ���� �� �������������� � �������
	void Delete(IdTable& idtable);
	void PrintTable(IdTable& idtable);
}