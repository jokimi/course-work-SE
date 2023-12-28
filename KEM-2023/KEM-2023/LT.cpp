#include <iostream>
#include "LT.h"
#include <fstream>
#include <string>
#include <iomanip>
#include "Error.h"
using namespace LT;
using namespace std;
LexTable LT::Create() {
	LexTable LexTable = {};
	LexTable.size = 0;
	LexTable.maxsize = LT_MAXSIZE;
	LexTable.table = new Entry[LexTable.maxsize];
	if (LexTable.size > LT_MAXSIZE)
		throw ERROR_THROW(116);
	return LexTable;
}
void LT::Add(LexTable& lextable, Entry entry) {
	lextable.table[lextable.size] = entry;
	lextable.size++;
}
void LT::Delete(LexTable& lextable) {
	LexTable temp = {};
	lextable = temp;
}
Entry LT::GetEntry(LexTable& lextable, int n) {
	if (n > lextable.size)
		throw ERROR_THROW(118);
	return lextable.table[n];
}
void LT::PrintTable(LexTable& lextable) {
	fstream fout("in.txt.lextable", fstream::out);
	if (!fout.is_open()) {
		throw ERROR_THROW(115);
	}
	Entry e;
	fout << endl << "\t\t\t\t\t\t*** ������� ������ ***" << endl << endl;
	int dist = 8;
	fout << "" << setw(70) << setfill('�') << "�" << endl;
	fout << "\t�������\t\t|� � ��\t\t|� � ����\t\t|�������� ���������" << endl;
	fout << "" << setw(70) << setfill('�') << "�" << endl;
	for (int i = 0; i < lextable.size; i++) {
		e = lextable.table[i];
		fout << "\t" << e.lexema << "\t\t\t|"
			<< (e.indID == -1 ? "" : std::to_string(e.indID + 1)) << "\t\t\t|"
			<< e.sn << "\t\t\t\t|" << e.operatorValue << endl;
	}
	fout << "" << setw(70) << setfill('�') << "�";
	fout.close();
}
void LT::PrintTablePolish(LexTable& lextable) {
	fstream fout("in.txt.polish", fstream::out);
	if (!fout.is_open()) {
		throw ERROR_THROW(115);
	}
	Entry e;
	fout << endl << "*** ������� ������ (�������� �������) ***" << endl << endl;
	int dist = 8;
	fout << "" << setw(41) << setfill('�') << "�" << endl;
	fout << "\t�������\t\t|� � ��\t\t|� � ����" << endl;
	fout << "" << setw(41) << setfill('�') << "�" << endl;
	for (int i = 0; i < lextable.size; i++) {
		e = lextable.table[i];
		fout << "\t" << e.lexema << "\t\t\t|"
			<< (e.indID == -1 ? "" : std::to_string(e.indID + 1)) << "\t\t\t|"
			<< e.sn << endl;
	}
	fout << "" << setw(41) << setfill('�') << "�";
	fout.close();
}