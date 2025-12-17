#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ==========================================
// STRUKTUR DATA
// ==========================================
struct Node {
    string data;                
    bool isLeaf;                
    vector<Node*> children;     
    Node(string val, bool leaf); 
};

struct UserLog {
    int id;
    string namaPlayer;
    string kategori;
    string statusAkhir;
    vector<string> jejak;
};

struct Question {
    int id;
    string text;
    string kategori; // Hewan, Tumbuhan, Manusia
};

// ==========================================
// VARIABEL GLOBAL
// ==========================================
extern Node* rootHewan;
extern Node* rootTumbuhan;
extern Node* rootManusia;
extern vector<Node*> allNodes; 
extern vector<UserLog> historyLogs;
extern int logCounter;

// Database Pertanyaan
extern vector<Question> hewanQuestions;
extern vector<Question> tumbuhanQuestions;
extern vector<Question> manusiaQuestions;
extern int questionIdCounter;

// ==========================================
// FUNGSI UTAMA
// ==========================================
void initTrees();
void rebuildTrees();
void cleanUpMemory();
void playGame(Node* current, UserLog &currentLog, int skorYa);
void userMenu();
void adminMenu();
void viewMyHistory(string playerName);
void viewLastHistory(string playerName);

// ==========================================
// FUNGSI ADMIN - KELOLA PERTANYAAN
// ==========================================
void lihatSemuaPertanyaan();
void lihatPertanyaanKategori(string kategori);
void tambahPertanyaan();
void editPertanyaan();
void hapusPertanyaan();
void adminKelolaData();
void adminKelolaPertanyaan();

#endif