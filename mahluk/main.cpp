#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    initTrees(); 
    
    cout << "=========================================\n"; // Header Program
    cout << "  SISTEM IDENTIFIKASI MAKHLUK HIDUP     \n";
    cout << "         (DYNAMIC QUESTIONS)            \n";
    cout << "=========================================\n";
    
    while (true) {
        cout << "\n=========================================\n";
        cout << "             MENU UTAMA                  \n";
        cout << "=========================================\n";
        cout << "1. Mulai Tes (User)\n";
        cout << "2. Menu Admin\n";
        cout << "3. Keluar Program\n";
        cout << "=========================================\n";
        cout << "Pilih: ";
        
        int menu; 
        cin >> menu;
        
        if (menu == 1) {
            userMenu();
        } else if (menu == 2) {
            adminMenu();
        } else if (menu == 3) {
            cout << "\n=========================================\n";
            cout << "  Terima kasih telah menggunakan sistem! \n";
            cout << "=========================================\n";
            break;
        } else {
            cout << "Pilihan tidak valid! Silakan pilih 1-3.\n";
        }
    }
    
    cleanUpMemory();
    cout << "\nProgram selesai. Sampai jumpa!\n\n";
    return 0;
}