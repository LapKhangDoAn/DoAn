#include "Lap.h"

Node* createNode(SanPham x);
void addTail(List &DSSP, SanPham x);
SanPham nhapSP();
void nhapDS(List &DSSP);
void inDS(List DSSP);
void huyDS(List &DSSP);
Node* searchNode(struct SanPham x, List myList);
void bosungSP(List &DSSP);
void timkiemSP(List DSSP);
void muaSP(List &DSSP);